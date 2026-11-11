#pragma once
#include <algorithm>
#include <cassert>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>

namespace fs = std::filesystem;
extern std::ofstream outFile;

enum class ReportKind
{
   TIMING,
   FAULT,
   NULLPTR,
};

constexpr size_t KIND_STRING_LEN = std::max({sizeof("TIMING"), sizeof("FAULT"), sizeof("NULLPTR")}) - 1;
std::string reportkind_to_string(ReportKind kind);
void create_statistical_report_file();
void open_statistical_report_file();
void write_statistical_report(ReportKind kind, const std::string &message);
void dump_buffer();
void close_statistical_report_file();
