#pragma once
void reset_table();
void put_data(int n, const std::string& s, double value, const std::string& format = "%.6f");
void print_header();
void print_row(int n);
void save_table_to_csv(const std::string& filename);