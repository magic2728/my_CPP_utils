#include "tracytian_utils.h"

bool ck_open(FILE ** FH, const string &file_path, const char * mode, const char * file, const int &line, const char * func) {//assemble them together to the tracytian_util class, and the declaration and definition should be divided for avoiding multi-definition
	* FH = fopen(file_path.c_str(), mode);
	if (! * FH) {
		cerr << "Cannot open " << file_path << " in " << mode << " mode!" << endl;
		cerr << "File " << file << endl << "Line " << line << endl << "Function " << func << endl;
		return false;
	} else {
		return true;
	}
}

string bin_path() {
	char bin_path[MAX_SIZE], * p;
	readlink("/proc/self/exe", bin_path, MAX_SIZE);
	p = strrchr(bin_path, '/');
	* p = '\0';
	return string(bin_path);
}
