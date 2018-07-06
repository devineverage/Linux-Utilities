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
#include <wctype.h>

using namespace std;

int main(const int argc, char *argv[]){

int cflag = 0;
int mflag = 0;
int lflag = 0;
int wflag = 0;
int c;
std::cout.setf(std::ios::unitbuf);
struct stat buf;

const size_t BUFFSIZE = 1024;

while ((c = getopt(argc, argv, "cmlw")) != -1)
    switch (c)
  {
      case 'c':
        cflag = 1;
        break;
      case 'm':
        mflag = 1;
        break;
      case 'l':
        lflag = 1;
        break;
      case 'w':
        wflag = 1;
        break;
  }
  
  if(cflag == 1 && lflag == 0 && wflag == 0){
    
   stat(argv[2], &buf);
   printf("%ld", buf.st_size);
  
  
  
  
  }else if(argc <= 2){
  
    int lines = 0;
    string line;
    int k = 0;
    int numChar = 1;
    ifstream refile (argv[1]);
    stat(argv[1], &buf);
    size_t len;
    char bu[4096];
    
    
    int so = open(argv[1], O_RDONLY, 0);
    while((len = read(so, bu, 1)) > 0){

      if(iswspace(bu[k]))
       numChar++;
       
      if(bu[0] == '\n'){
    
        lines++;
    
      }
   
    }
    close(so);
    cout << lines << " " << numChar << " " ;
    printf("%ld", buf.st_size);
  
  }else if(cflag == 0 && lflag == 1 && wflag == 0){
  
    int lines = 0;
    string line;
    char bu[4096];
    size_t len;

    int so = open(argv[2], O_RDONLY, 0);
    while((len = read(so, bu, 1)) > 0){
       
      if(bu[0] == '\n'){
    
        lines++;
    
      }
      
    }
    close(so);
    cout << lines;
  
  }else if(cflag == 0 && lflag == 0 && wflag == 1){
  
    int numChar = 1;
    char bu[4096];
    int k = 0;
    size_t len;
    int so = open(argv[2], O_RDONLY, 0);
    while((len = read(so, bu, 1)) > 0){

      if(iswspace(bu[k]))
       numChar++;
   
    }
    close(so);
    cout << numChar;
  
  }else if(cflag == 1 && lflag == 1 && wflag == 0){
    
    stat(argv[3], &buf);
    int lines = 0;
    string line;
    ifstream refile (argv[3]);
    size_t len;
    char bu[4096];
    int so = open(argv[3], O_RDONLY, 0);
    while((len = read(so, bu, 1)) > 0){

 
      if(bu[0] == '\n'){
    
        lines++;
    
      }
      
    }
      close(so);
    printf("%ld", buf.st_size);
    cout << " " << lines;
  
  }else if(cflag == 1 && lflag == 0 && wflag == 1){
  
    stat(argv[3], &buf);
    printf("%ld", buf.st_size);
    cout << " ";
    int numChar = 1;
    size_t len;
    char bu[4096];
    int k = 0;
    int so = open(argv[3], O_RDONLY, 0);
    while((len = read(so, bu, 1)) > 0){

      if(iswspace(bu[k]))
       numChar++;
   
    }
    close(so);
    cout << numChar;
    
  }else if(cflag == 0 && lflag == 1 && wflag == 1){
    
    
    
    int lines = 0;
    string line;
    ifstream refile (argv[3]);
    size_t len;
    int numChar = 1;
    char bu[4096];


    int so = open(argv[3], O_RDONLY, 0);
    while((len = read(so, bu, 1)) > 0){

      if(iswspace(bu[0]))
       numChar++;
       
      if(bu[0] == '\n'){
    
        lines++;
    
      }
    }
    close(so);
    cout << lines << " " <<numChar;
   
  
  
  
  }else if(cflag == 1 && lflag ==1 && wflag ==1){
  
  
    stat(argv[4], &buf);
    printf("%ld", buf.st_size);
    cout << " ";
    int lines = 0;
    string line;
    ifstream refile (argv[4]);
    size_t len;

   
    int numChar = 1;
    char bu[4096];
    int k = 0;
    int so = open(argv[4], O_RDONLY, 0);
    while((len = read(so, bu, 1)) > 0){

      if(iswspace(bu[k]))
       numChar++;
       
      if(bu[0] =='\n'){
        lines++;
      
      }
     close(so);
    }
    cout << lines << " " <<numChar;
    
  
  }else if(mflag == 1 && lflag == 0 && wflag == 0){
  
    std::setlocale(LC_ALL, "en_US.utf8");        // enable unicode
    const char * filename = argv[2];             // filename
    char buffer [BUFFSIZE];                      // read buffer
    int fd = (argc == 1) ? STDIN_FILENO : open(filename, O_RDONLY);
    size_t nbytes = 0;                           // # bytes read
    size_t nchars = 0;                           // # characters read
    while ((nbytes = read(fd, buffer, BUFFSIZE)) > 0) {
      std::mbstate_t state = std::mbstate_t();   // initialize state
      size_t len = 0;                            // # bytes processed
      wchar_t wc = 0;                            // multibyte character
      size_t sum = 0;                            // sum # bytes processed
      while((len = std::mbrtowc(&wc, buffer+sum, nbytes-sum, &state)) > 0) {
        if (len == (size_t) -2) break;           // incomplete wchar
        sum    += len;                           // accumulate sum
        nchars += 1;                             // increment character count
      } // while
      // handle incomplete wchar at end of buffer by seeking back a little
      if (sum < nbytes) lseek(fd, sum-nbytes, SEEK_CUR);
    } // while
    std::wcout << nchars << std::endl;
    close(fd);
    
  }else if(mflag == 1 && lflag == 1 && wflag == 0){
    
     std::setlocale(LC_ALL, "en_US.utf8");        // enable unicode
    const char * filename = argv[3];             // filename
    char buffer [BUFFSIZE];                      // read buffer
    int fd = (argc == 1) ? STDIN_FILENO : open(filename, O_RDONLY);
    size_t nbytes = 0;                           // # bytes read
    size_t nchars = 0;                           // # characters read
    while ((nbytes = read(fd, buffer, BUFFSIZE)) > 0) {
      std::mbstate_t state = std::mbstate_t();   // initialize state
      size_t len = 0;                            // # bytes processed
      wchar_t wc = 0;                            // multibyte character
      size_t sum = 0;                            // sum # bytes processed
      while((len = std::mbrtowc(&wc, buffer+sum, nbytes-sum, &state)) > 0) {
        if (len == (size_t) -2) break;           // incomplete wchar
        sum    += len;                           // accumulate sum
        nchars += 1;                             // increment character count
      } // while
      // handle incomplete wchar at end of buffer by seeking back a little
      if (sum < nbytes) lseek(fd, sum-nbytes, SEEK_CUR);
    } // while
    std::wcout << nchars << std::endl;
    close(fd);
    int lines = 0;
    string line;
    char bu[4096];
    ifstream refile (argv[3]);
    size_t len;
    int so = open(argv[4], O_RDONLY, 0);
    while((len = read(so, bu, 1)) > 0){

      if(bu[0] =='\n'){
        lines++;
      
      }
   
     
    } 
    close(so);
    cout << lines;
  
  }else if(mflag == 1 && lflag == 0 && wflag == 1){
  
    std::setlocale(LC_ALL, "en_US.utf8");        // enable unicode
    const char * filename = argv[3];             // filename
    char buffer [BUFFSIZE];                      // read buffer
    int fd = (argc == 1) ? STDIN_FILENO : open(filename, O_RDONLY);
    size_t nbytes = 0;                           // # bytes read
    size_t nchars = 0;                           // # characters read
    while ((nbytes = read(fd, buffer, BUFFSIZE)) > 0) {
      std::mbstate_t state = std::mbstate_t();   // initialize state
      size_t len = 0;                            // # bytes processed
      wchar_t wc = 0;                            // multibyte character
      size_t sum = 0;                            // sum # bytes processed
      while((len = std::mbrtowc(&wc, buffer+sum, nbytes-sum, &state)) > 0) {
        if (len == (size_t) -2) break;           // incomplete wchar
        sum    += len;                           // accumulate sum
        nchars += 1;                             // increment character count
      } // while
      // handle incomplete wchar at end of buffer by seeking back a little
      if (sum < nbytes) lseek(fd, sum-nbytes, SEEK_CUR);
    } // while
    std::wcout << nchars << std::endl;
    close(fd);
  
    int numChar = 1;
    char bu[4096];
    size_t len;
    int k = 0;
    int so = open(argv[3], O_RDONLY, 0);
    while((len = read(so, bu, 1)) > 0){

      if(iswspace(bu[k]))
       numChar++;
   
    }
    close(so);
    cout << numChar;
  
  
  
  }else if(mflag == 1 && lflag == 1 && wflag == 1){
  
   std::setlocale(LC_ALL, "en_US.utf8");        // enable unicode
    const char * filename = argv[4];             // filename
    char buffer [BUFFSIZE];                      // read buffer
    int fd = (argc == 1) ? STDIN_FILENO : open(filename, O_RDONLY);
    size_t nbytes = 0;                           // # bytes read
    size_t nchars = 0;                           // # characters read
    while ((nbytes = read(fd, buffer, BUFFSIZE)) > 0) {
      std::mbstate_t state = std::mbstate_t();   // initialize state
      size_t len = 0;                            // # bytes processed
      wchar_t wc = 0;                            // multibyte character
      size_t sum = 0;                            // sum # bytes processed
      while((len = std::mbrtowc(&wc, buffer+sum, nbytes-sum, &state)) > 0) {
        if (len == (size_t) -2) break;           // incomplete wchar
        sum    += len;                           // accumulate sum
        nchars += 1;                             // increment character count
      } // while
      // handle incomplete wchar at end of buffer by seeking back a little
      if (sum < nbytes) lseek(fd, sum-nbytes, SEEK_CUR);
    } // while
    std::wcout << nchars << std::endl;
    close(fd);
    int lines = 0;
    string line;
    ifstream refile (argv[4]);
    size_t len;

     int numChar = 1;
    char bu[4096];
    int k = 0;
    int so = open(argv[4], O_RDONLY, 0);
    while((len = read(so, bu, 1)) > 0){

      if(iswspace(bu[k]))
       numChar++;
       
      if(bu[0] == '\n'){
      
        lines++;
      }
   
    }
    close(so);
    cout << lines << " " <<numChar;
  
  
  }


return 0;
}