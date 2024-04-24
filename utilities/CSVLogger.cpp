#include "CSVLogger.hpp"

CSVLogger::CSVLogger()
{
    // 如果有必要，可以在这里进行构造函数的初始化工作
}

void CSVLogger::reset_table()
{
    columns_order.clear();
    table.clear();
}

void CSVLogger::put_data(int n, const std::string &s, double value, const std::string &format)
{
    if (std::find(columns_order.begin(), columns_order.end(), s) == columns_order.end())
    {
        columns_order.push_back(s);
    }
    table[n][s] = std::make_pair(value, format);
}

void CSVLogger::put_data(int n, const std::string &columnName, const std::string &dataToInsert)
{
    if (std::find(columns_order.begin(), columns_order.end(), columnName) == columns_order.end())
    {
        columns_order.push_back(columnName);
    }
    table[n][columnName] = dataToInsert;
}

int CSVLogger::getMaxRowNumber() const
{
    if (!table.empty())
    {
        // 获取最大的key
        int maxKey = table.rbegin()->first;
        return maxKey;
    }
    else
    {
        std::cout << "The map is empty." << std::endl;
        return -1;
    }
}

void CSVLogger::print_header()
{
    std::cout << "No.,\t";
    for (const auto &col : columns_order)
    {
        std::ostringstream oss;
        oss << col;
        if (&col != &columns_order.back())
        {
            oss << ",";
        }
        std::cout << std::left << std::setw(20) << oss.str();
    }
    std::cout << std::endl;
}

void CSVLogger::print_row(int n)
{
    std::cout << n << ",\t";
    for (const auto &col : columns_order)
    {
        print_value(n, col);
    }
    std::cout << std::endl;
}

void CSVLogger::save_table_to_csv(const std::string &filename)
{
    std::ofstream csv_file(filename);
    if (!csv_file.is_open())
    {
        std::cerr << "Failed to open CSV file: " << filename << std::endl;
        return;
    }

    write_header(csv_file);

    for (const auto &entry : table)
    {
        int n = entry.first;
        csv_file << n << ",";
        for (const auto &col : columns_order)
        {
            write_value(csv_file, n, col);
            if (&col != &columns_order.back())
            {
                csv_file << ",";
            }
        }
        csv_file << std::endl;
    }

    csv_file.close();
    std::cout << "CSV data saved to " << filename << std::endl;
}


void CSVLogger::write_header(std::ostream &os)
{
    os << "No.,";
    for (const auto &col : columns_order)
    {
        os << col;
        if (&col != &columns_order.back())
        {
            os << ",";
        }
    }
    os << std::endl;
}

void CSVLogger::print_value(int n, const std::string &col)
{
    if (table[n].find(col) != table[n].end())
    {
        auto &value = table[n][col];
        std::ostringstream oss;

        if (std::holds_alternative<std::pair<double, std::string>>(value))
        {
            auto &valPair = std::get<std::pair<double, std::string>>(value);
            auto format = valPair.second;
            if (format == "%d")
            {
                oss << static_cast<int>(valPair.first);
            }
            else
            {
                oss << std::fixed << std::setprecision(6) << valPair.first;
            }
        }
        else if (std::holds_alternative<std::string>(value))
        {
            oss << std::get<std::string>(value);
        }
        else
        {
            std::cerr << "Unknown value type!" << std::endl;
            exit(-1);
        }

        if (&col != &columns_order.back())
        {
            oss << ",";
        }
        std::cout << std::left << std::setw(20) << oss.str();
    }
    else
    {
        std::cout << std::left << std::setw(20) << "N/A";
    }
}

void CSVLogger::write_value(std::ostream &os, int n, const std::string &col)
{
    if (table[n].find(col) != table[n].end())
    {
        auto &value = table[n][col];
        if (std::holds_alternative<std::pair<double, std::string>>(value))
        {
            auto &valPair = std::get<std::pair<double, std::string>>(value);
            auto format = valPair.second;
            if (format == "%d")
            {
                os << static_cast<int>(valPair.first);
            }
            else
            {
                os << std::fixed << std::setprecision(6) << valPair.first;
            }
        }
        else if (std::holds_alternative<std::string>(value))
        {
            os << std::get<std::string>(value);
        }
        else
        {
            std::cerr << "Unknown value type!" << std::endl;
            exit(-1);
        }
    }
    else
    {
        os << "N/A";
    }
}
