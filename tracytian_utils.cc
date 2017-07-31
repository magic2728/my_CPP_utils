#include "tracytian_utils.h"// the include and using lines before are all for the declaration reliance
// all the variable or functions declared in namespace should also defined by giving the namespace field operator::, however, when using them, you can only say using namespace XXX to leave out the namespace field operation

bool tracytian_utils::ck_open(FILE ** FH, const string &file_path, const char * mode, const char * file, const int &line, const char * func) {//assemble them together to the tracytian_util class, and the declaration and definition should be divided for avoiding multi-definition
	* FH = fopen(file_path.c_str(), mode);
	if (! * FH) {
		cerr << "Cannot open " << file_path << " in " << mode << " mode!" << endl;
		cerr << "File " << file << endl << "Line " << line << endl << "Function " << func << endl;
		return false;
	} else {
		return true;
	}
}

bool tracytian_utils::ck_open(const string &file_path, fstream &FH, ios_base::openmode mode) {
  FH.open(file_path, mode);
  if (!FH.is_open()) {
    cerr << "Cannot open file " << file_path << endl;
    return false;
  } else {
    return true;
  }
}

string tracytian_utils::bin_path() {
	char bin_path[MAX_SIZE], * p;
	readlink("/proc/self/exe", bin_path, MAX_SIZE);
	p = strrchr(bin_path, '/');
	* p = '\0';
	return string(bin_path);
}

char * tracytian_utils::itoa(int num,char * str,int radix) {/*索引表*/// the default value of radix can not presented in definition if has been declared
	char index[]="0123456789ABCDEF";
	unsigned unum;/*中间变量*/
	int i=0,j,k;
	/*确定unum的值*/
	if(radix==10&&num<0)/*十进制负数*/
	{
		unum=(unsigned)-num;
		str[i++]='-';
	}
	else unum=(unsigned)num;/*其他情况*/
	/*转换*/
	do{
		str[i++]=index[unum%(unsigned)radix];
		unum/=radix;
	}while(unum);
	str[i]='\0';
	/*逆序*/
	if(str[0]=='-')k=1;/*十进制负数*/
	else k=0;
	char temp;
	for(j=k;j<=(i-1)/2;j++)
	{
		temp=str[j];
		str[j]=str[i-1+k-j];
		str[i-1+k-j]=temp;
	}
	return str;
}

bool tracytian_utils::split(const string & input_str, const string& regex, vector<string> * const split_list) {
  std::regex reg(regex);
  sregex_token_iterator
    first{input_str.begin(), input_str.end(), reg, - 1}, last;
  * split_list = {first, last};
  return true;
}

bool tracytian_utils::chomp(string const &line, char const &end, string * const res_line) {
  uint32_t pos = line.length();
  while (line[-- pos] == end){}
  * res_line = line.substr(0, pos + 1);
  return true;
}
