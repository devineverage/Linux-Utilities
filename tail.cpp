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

using namespace std;

int main(const int argc, char *argv[]){

int c;
int fflag = 0;
int cflag = 0;
int nflag = 0;
int lines = 0;
int index = 1;
int numByte = 0;
std::cout.setf(std::ios::unitbuf);

while ((c = getopt(argc, argv, "fcn")) != -1)
    
    switch (c)
  {
      case 'f':
        fflag = 1;
        break;
      case 'c':
        cflag = 1;
        break;
      case 'n':
        nflag = 1;
        break;

  }
  
  if(nflag == 1 && (argc <= 3 || string(argv[3]) == "-") && fflag == 0){ 

    char str[5];
    string ech;
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
    for(int a = 0; a < lines; a++){
    
      cin >> ech;
      if(cin.eof()){
        exit(0);
      }
      cout << ech <<endl;
    
    }
  }else if(nflag == 0 && (argc <= 1 || string(argv[1]) == "-") && fflag == 0 && cflag == 0){
  
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
  
  }else if(cflag == 1 && (argc <= 3 || string(argv[3]) == "-") && fflag == 0){
    string ech;
    numByte = atoi(argv[2]);
    
    for(int a = 0; a < 9; a++){
    
      cin >> ech;
      cout << ech <<endl;
    
    }
  
  
  
  
  }else if(nflag == 0 && fflag == 0 && cflag == 0 && argc >= 2){
    
    string line;
    ifstream refile (argv[1]);
    if(refile.is_open()){
      while(getline(refile, line))
      {
      
        if(index >= lines){
          cout << line << '\n';
        }
        index ++;
  
      }
      refile.close();
    
      }
    
  
  }else if(nflag == 1 && fflag == 0){

    char str[5];
    string ech;
    string line;
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
   size_t len; 
    size_t len2;
    char bu[4096];
    char nbu[4096];
    int count;
  
      int so = open(argv[3], O_RDONLY, 0);  
      while((len = read(so, bu, 1)) > 0){
      
          if(bu[0] == '\n'){
    
            count++;
    
          }
 
         
      }
      close(so);
      int med = count - lines;
      if( med <= 0){
        med = lines;
      }
      int ne = open(argv[3], O_RDONLY, 0); 
      while((len2 = read(ne, nbu, 1)) > 0){
  
        if(count <= lines){
            
           write(STDOUT_FILENO, nbu, len2);
           
        }
         
        if(nbu[0] == '\n'){
          count--;

        }
     
      }
    
  }else if(cflag == 1 && fflag == 0){

  char str[5];
  int counter = 0;
    string ech;
    strcpy(str, argv[2]);
    if(isdigit(str[0])){
        numByte = atoi(argv[2]);
        //cout << numByte;
      }else{
        cout << "Please enter a positive integer" << endl;
        exit(0);
      }
  string line;
  //struct stat buf;
  //stat(argv[3], &buf);
  //int tot = (int)buf.st_size;
  size_t len; 
  size_t len2;
  char bu[4096];
  char nbu[4096];

    int so = open(argv[3], O_RDONLY, 0);  
    while((len = read(so, bu, 1)) > 0){

        counter++;
       
    }
    close(so);
    int med = counter - numByte;
    if( med <= 0){
      med = counter;
    }
    int ne = open(argv[3], O_RDONLY, 0); 
    while((len2 = read(ne, nbu, 1)) > 0){

      if(counter <= numByte){
          
         write(STDOUT_FILENO, nbu, len2);
         
      }
       
      
        counter--;
      
   
    }
    
  
  }else if(cflag == 0 && nflag == 0 && fflag == 1){
  
  lines = 10;
  string line;
  size_t len;
  char bu[4096];
  int coun = 0;
  int next = 0;
  const char* fil = argv[2];
  
  int so = open(fil, O_RDONLY);
  while((len = read(so, bu, 1)) > 0){

    if(bu[0] == '\n'){
    
      coun++;
    
    }
     
   }
   close(so);
   next = coun - lines;
   if(next < 0){
     next = 0;
   }

   so = open(fil, O_RDONLY);
    

   while(((signed int)(len = read(so, bu, 1))) > -1){
   
   if(next <= 0){
       if(((signed int)len) != write(STDOUT_FILENO, bu, len)){
       
         cout << bu[0];
        
       }
     }
   if(bu[0] == '\n'){
      next--;

    }
   
   }
   close(so);
   cout << endl;
  }else if(nflag == 1 && fflag == 1){
  char str[5];
    strcpy(str, argv[3]);
    if(isdigit(str[0])){
        lines = atoi(argv[3]);
        if(lines == 0){
          lines = 10;
        }
      }else{
        cout << "Please enter a positive integer" << endl;
        exit(0);
      }
  string line;
  size_t len;
  char bu[4096];
  int coun = 0;
  int next = 0;
  const char* fil = argv[4];
  
  int so = open(fil, O_RDONLY);
  while((len = read(so, bu, 1)) > 0){

    if(bu[0] == '\n'){
    
      coun++;
    
    }
     
   }
   close(so);
   next = coun - lines;
   if(next < 0){
     next = 0;
   }

   so = open(fil, O_RDONLY);

   while(((signed int)(len = read(so, bu, 1))) > -1){
   
   if(next <= 0){
       if(((signed int)len) != write(STDOUT_FILENO, bu, len)){
       
         cout << bu[0];
        
       }
     }
   if(bu[0] == '\n'){
      next--;

    }
   
   }
   close(so);
   cout << endl;
  
  
  }
  
  
  return 0;
}