#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <variant>

class CSVLogger {
public:
    CSVLogger();  // 如果有必要，可以添加构造函数

    void reset_table();
    int getMaxRowNumber() const;
    void put_data(int n, const std::string &s, double value, const std::string &format = "%.6f");
    void put_data(int n, const std::string &columnName , const std::string &dataToInsert );
    void print_header();
    void print_row(int n);
    void save_table_to_csv(const std::string &filename);

private:
    std::vector<std::string> columns_order;
    // std::map<int, std::map<std::string, std::pair<double, std::string>>> table;
    std::map<int, std::map<std::string, std::variant<std::string, std::pair<double, std::string>>>> table;

    void print_value(int n, const std::string &col);
    void write_header(std::ostream &os);
    void write_value(std::ostream &os, int n, const std::string &col);
};
