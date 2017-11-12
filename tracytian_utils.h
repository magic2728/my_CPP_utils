#ifndef TRACY_TIAN_UTILS_H_
#define TRACY_TIAN_UTILS_H_
#define MAX_SIZE 65535
#define SIZE 1024
#define OPEN_FILE_INFO  __FILE__, __LINE__, __FUNCTION__
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <unistd.h>
using namespace std;

namespace tracytian_utils {
    bool ck_open(FILE ** FH, const string &file_path, const char* mode, const char * file, const int &line, const char * func);
    string bin_path();
    char * itoa(int num,char * str,int radix = 10);
}
using namespace tracytian_utils;
#endif// TRACY_TIAN_UTILS_H_ ending tag
