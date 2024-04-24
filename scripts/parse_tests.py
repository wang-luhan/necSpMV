import re
import openpyxl
import sys
from openpyxl import Workbook

def parse_google_test_output(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()

    data = []
    nnz, current_dataset, gflops = None, None, None
    for line in lines:
        if 'matrix has' in line:
            nnz = re.search(r'matrix has (\d+)', line).group(1)

        if '[ RUN      ]' in line:
            current_dataset = line.split('.')[-1].strip()

        if 'SpMV Performance' in line:
            gflops = re.search(r'SpMV Performance\s+=\s+(\d+\.\d+)', line).group(1)

        # 当所有需要的数据都被找到时，添加到数据列表
        if nnz and current_dataset and gflops:
            data.append((nnz, current_dataset, gflops))
            nnz, current_dataset, gflops = None, None, None

    return data

def save_to_excel(data, output_file):
    workbook = Workbook()
    sheet = workbook.active
    sheet.append(['NNZ', 'Dataset', 'GFLOPS'])

    for row in data:
        sheet.append(row)

    workbook.save(filename=output_file)

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python parse_google_test.py <input_file> <output_file>")
        sys.exit(1)

    input_file_path = sys.argv[1]
    output_file_path = sys.argv[2]

    data = parse_google_test_output(input_file_path)
    save_to_excel(data, output_file_path)
    print(f"Data saved to {output_file_path}.")
