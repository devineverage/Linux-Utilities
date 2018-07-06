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
int sflag;
struct stat buf;
 
while ((c = getopt(argc, argv, "s:")) != -1)
    switch (c)
  {
      case 's':
        sflag = 1;  
        break;

  }
  
if(sflag == 1){

  symlink(argv[2], argv[3]);


}else{
  
  stat(argv[1], &buf);
  if((buf.st_mode & S_IFMT) == S_IFDIR ){
    
    perror("Can not hardlink a directory");
  
  }else
    link(argv[1], argv[2]);

}

return 0;

}