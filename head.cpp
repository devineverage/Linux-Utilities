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
#include <stdlib.h>
#include <ctype.h>

using namespace std;

int main(const int argc, char *argv[]){
std::cout.setf(std::ios::unitbuf);
int c;
int nflag;



while ((c = getopt(argc, argv, "n:")) != -1)
    switch (c)
  {
      case 'n':
        nflag = 1;
        break;

  }

if(nflag == 1 && argc <= 3){ 
    int lines = 0;
    char str[5];
    strcpy(str, argv[2]);
    string ech;
    if(isdigit(str[0])){
      lines = atoi(argv[2]);
      if(lines == 0){
        lines = 10;
      }
    }else{
      cout << "Please enter a positive integer" << endl;
      exit(0);
    }
    for(int a = 0; a < lines; a++){
    
      cin >> ech;
      if(cin.eof()){
        exit(0);
      }
      cout << ech <<endl;
    
    }
  
  
  }
  
else if(nflag == 0 && argc <= 1){

    string ech;
    cin >> ech;
    cout << ech << endl;
    for(int k = 0; k < 9; k++){
    
    cin >> ech;
    if(cin.eof()){
      exit(0);
    }
    cout << ech << endl;
  }
  
  
  
}          

else if(nflag == 1 && argc >= 4){
  
  int lines = 0;
  
  char str[5];
  strcpy(str, argv[2]);
  if(isdigit(str[0])){
      lines = atoi(argv[2]);
      if(lines == 0){
        lines = 10;
      }
    }else{
      cout << "Please enter a positive integer" << endl;
      exit(0);
    }
  string line;
  struct stat buf;
  for(int i = 3; i < argc; i++){

    if((stat(argv[i], &buf)) != 0){
      perror("Filename doesnt exist");
      exit(0);
    
    }else{
    
      int index = 0;
      ifstream refile (argv[i]);
      if(refile.is_open()){
        while(getline(refile, line))
        {
        
          
          if(index == lines){
            break;
          }
          cout << line << '\n';
          index ++;
        }
        refile.close();
        
      }
      else cout << "Unable to open file";
      
    }
  }
  
  }else if(nflag == 0 && argc > 1) {
    int lines = 10;
    string line;
    struct stat buf;
    
    for(int i = 1; i < argc; i++){

      if((stat(argv[i], &buf)) != 0){
        perror("Filename doesnt exist");
        exit(0);
      
      }else{
      
        int index = 0;
        ifstream refile (argv[i]);
        if(refile.is_open()){
          while(getline(refile, line))
          {
           
            if(index == lines){
              break;
            }
            cout << line << '\n';
            index ++;
          }
          refile.close();
          
        }
        else cout << "Unable to open file";
        
      }
  
  }
 
 }       

return 0;

}
          