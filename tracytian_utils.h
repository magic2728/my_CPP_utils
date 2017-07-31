#ifndef TRACY_TIAN_UTILS_H_
#define TRACY_TIAN_UTILS_H_
//special add here 2 ^ 30
#define MAX_MAX_SIZE 1073741824
#define MAX_SIZE 65535
#define SIZE 1024
#define OPEN_FILE_INFO  __FILE__, __LINE__, __FUNCTION__
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>// special add here
#include <regex>//special add here
#include <iomanip>//special add here
#include <math.h>//special add here
#include <fstream>//special add here
#include <ctime>//special add here
using namespace std;

namespace tracytian_utils {
    bool ck_open(FILE ** FH, const string &file_path, const char* mode, const char * file, const int &line, const char * func);
    bool ck_open(const string &file_path, fstream &FH, ios_base::openmode mode);// special add here
    string bin_path();
    char * itoa(int num,char * str,int radix = 10);
    // special added here string utils added
    bool split(const string & input_str, const string& regex, vector<string> * const split_list);
    bool chomp(string const &line, char const &end, string * const res_line);
}
using namespace tracytian_utils;
#endif// TRACY_TIAN_UTILS_H_ ending tag
