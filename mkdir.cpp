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
#include <math.h>

using namespace std;

int coun = 0;
int ind = 0;
string hold[30];
string sname;


void findDir(const char* dire){

  const char *dirname = dire;
  DIR* dir = opendir(dirname);
  string fname = string(dirname);
  
  if(dir){
    
    closedir(dir);
    sname = fname;
    
  
  }else if(ENOENT == errno){
    
    string newdname;
    std::string str(dirname);
    string delim = "/";
    string fname = str.substr(0,str.find_last_of(delim));
    newdname = str.substr(str.find_last_of(delim), str.length());
    //cout<< newdname << "\n";
    //const char *newd = newdname.c_str();
    const char *chname = fname.c_str();
    //cout << chname << "\n";
    if(newdname != "/"){
      
      hold[ind] = newdname;
      ind++;
      coun++;
    }
    findDir(chname);
    
    
  }


}



int main(const int argc, char *argv[]){

int pflag = 0;
int mflag = 0;
int mode;
int c;
std::cout.setf(std::ios::unitbuf);
while ((c = getopt(argc, argv, "pm")) != -1)
    switch (c)
  {
      case 'p':
        pflag = 1;
        break;
      case 'm':
        mflag = 1;
        break;

  }
 
 if(argc <= 2){
 
   mkdir(argv[1], 0755);
 
 
 }

  if(mflag == 1 && pflag == 0){
    
    int i = 0;
    int r = 0;
    int d = 0;
    mode = atoi(argv[2]);
    while (mode != 0)
    {
        r = mode % 10;
        mode /= 10;
        d += r * pow(8, i);
        ++i;
    }
 
    mkdir(argv[3], d);
   
  
  }else if(mflag == 0 && pflag == 1){
    
    
    findDir(argv[2]);

    for(int t = coun - 1; t >= 0; t--){
    
      string cur = hold[t];
      sname = sname + cur;
      const char *full = sname.c_str();
      mkdir(full, 0755);

    
    }
    
  
  
  }


  return 0;
}