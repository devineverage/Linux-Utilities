#include <string.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <cstdlib> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <pwd.h> 
#include <unistd.h> 
#include <time.h>
#include <dirent.h>
#include <fcntl.h> 
#include <limits.h>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int main(const int argc, char *argv[]){

int aflag = 0;
std::cout.setf(std::ios::unitbuf);
const char *spec = argv[1];
string hol = string(spec);
string delim = "+";
if((hol.find(delim)) == 0);
aflag = 1;


char str[50];

if(argc == 1){

  time_t time2 = time(NULL);
  struct tm * p = localtime(&time2);
  strftime(str, 100, "%a %b %e %T %Z %Y",p);
  
  printf("%s", str);
}else if(aflag == 1){

  string fname = hol.substr(hol.find(delim) + 1, hol.length());
  const char *pd = fname.c_str();
  time_t time2;
  struct tm * p = localtime(&time2);
  strftime(str, 100, pd ,p);
  printf("%s", str);


}else{

  cout << argv[1];
  


}

return 0;

}