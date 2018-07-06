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

bool direnticmp(struct dirent * a, struct dirent * b) {
  return strcasecmp(a->d_name, b->d_name) < 0; 
} // direnticmp


int main(const int argc, char *argv[]){

int aflag = 0;
int lflag = 0;
int c;
std::cout.setf(std::ios::unitbuf);
opterr = 0;

while ((c = getopt(argc, argv, "al")) != -1)
    switch (c)
  {
      case 'a':
        aflag = 1;
        break;
      case 'l':
        lflag = 1;
        break;

  } 


struct stat buf;

if(aflag == 1 && lflag == 0 && argc < 3){

list<struct dirent *> entries;                 // entry list
  struct dirent * entry = nullptr;               // entry pointer
  DIR * pwd = opendir(".");                      // open directory

  if (pwd == nullptr) { 
    perror("ls");
  } else {
    while ((entry = readdir(pwd)) != nullptr) {  // read entries
      entries.push_back(entry);                  // add entry to list
    } // while
    entries.sort(direnticmp);                    // sort entries
    for (auto dir : entries){ 
      if(strcmp(dir -> d_name, ".") == 0  || strcmp(dir -> d_name, "..") == 0){
              
      }else
      cout << dir->d_name << endl;       // print entry name
    }
    closedir(pwd);                               // close directory; avoid memory leak
  } // if


}//can delete this one
///////////////////////////////////////////////////////////////////
else if(aflag == 1 && lflag == 0 && argc >= 3){

  list<struct dirent *> entries;                 // entry list
  struct dirent * entry = nullptr;               // entry pointer
  DIR * pwd = opendir(argv[2]);                      // open directory

  if (pwd == nullptr) { 
    perror("ls");
  } else {
    while ((entry = readdir(pwd)) != nullptr) {  // read entries
      entries.push_back(entry);                  // add entry to list
    } // while
    entries.sort(direnticmp);
    for (auto dir : entries){ 
      if(strcmp(dir -> d_name, ".") == 0  || strcmp(dir -> d_name, "..") == 0){
              
      }else
      cout << dir->d_name << endl;       // print entry name
    }
    closedir(pwd);                               // close directory; avoid memory leak
  } // if

}

//222222222222222222222222222222222222222222222222222222
else if(aflag == 1 && lflag == 1 && argc < 3 ){


  list<struct dirent *> entries;                 // entry list
  struct dirent * entry = nullptr;               // entry pointer
  DIR * pwd = opendir(".");                      // open directory
  char first;
  int mode = buf.st_mode & 07777;
  char str2[50]; 
  if (pwd == nullptr) { 
    perror("ls");
  } else {
    while ((entry = readdir(pwd)) != nullptr) {  // read entries
      entries.push_back(entry);                  // add entry to list
    } // while
    entries.sort(direnticmp);                     // sort entries
    for (auto dir : entries){
      
     stat(dir -> d_name, &buf); 
     
       switch (buf.st_mode & S_IFMT) {
      case S_IFBLK: 
      //printf("block device\n"); 
      first = 'b';
      break;
      case S_IFCHR:
      //printf("character device\n"); 
      first = 'c';
      break;
      case S_IFDIR: 
      //printf("directory\n");
      first = 'd';
      break;
      case S_IFIFO: 
      //printf("FIFO/pipe\n"); 
      first = 'p';
      break;
      case S_IFLNK: 
      //printf("symlink\n");
      first = 'l';
      break;
      case S_IFREG: 
      //printf("regular file\n"); 
      first= '-';
      break;
      case S_IFSOCK: 
      //printf("socket\n"); 
      first = 's';
      break;
      default: 
      printf("unknown?\n");
      first = '?';
      break;
    }
      if(strcmp(dir -> d_name, ".") == 0  || strcmp(dir -> d_name, "..") == 0){
              
  }else{
          printf(&first);
          if ((mode & S_IRUSR) && (mode & S_IREAD))
            printf("r");
          else
            printf("-");
          if ((mode & S_IWUSR) && (mode & S_IWRITE))
            printf("w");
          else
            printf("-");
          if ((mode & S_IXUSR) && (mode & S_IEXEC))
            printf("x");
          else
            printf("-");
          
          if ((mode & S_IRGRP) && (mode & S_IREAD))
            printf("r");
          else
            printf("-");
          if ((mode & S_IWGRP) && (mode & S_IWRITE))
            printf("w");
          else
            printf("-");
          if ((mode & S_IXGRP) && (mode & S_IEXEC))
            printf("x");
          else
            printf("-");
  
          if ((mode & S_IROTH) && (mode & S_IREAD))
            printf("r");
          else
            printf("-");
          if ((mode & S_IWOTH) && (mode & S_IWRITE))
            printf("w");
          else
            printf("-");
          if ((mode & S_IXOTH) && (mode & S_IEXEC))
            printf("x)");
          else
            printf("-");
            
          }
  
  if(strcmp(dir -> d_name, ".") == 0  || strcmp(dir -> d_name, "..") == 0){
              
  }else{
     
            
            
  cout << ". ";
  printf("%ld", buf.st_nlink);
  cout << " ";
  cout << "everage ";
  cout << "ugrad ";
  printf("%ld", buf.st_size);
  cout << " ";
  time_t time2 = (buf.st_mtime);
  struct tm * p = localtime(&time2);
  strftime(str2, 100, "%b %e %R",p);
  printf("%s", str2);
    
    
     cout << " " << dir->d_name << endl; 
     }
    }      // for
    closedir(pwd);                               // close directory; avoid memory leak
  } // if

  
                    

}//can delete this one

else if(aflag == 0 && lflag == 0 && argc < 2){

list<struct dirent *> entries;                 // entry list
  struct dirent * entry = nullptr;               // entry pointer
  DIR * pwd = opendir(".");                      // open directory

  if (pwd == nullptr) { 
    perror("ls");
  } else {
    while ((entry = readdir(pwd)) != nullptr) {  // read entries
      entries.push_back(entry);                  // add entry to list
    } // while
    entries.sort(direnticmp);                    // sort entries
    for (auto dir : entries){
    if(dir -> d_name[0] == '.' ||(strcmp(dir -> d_name, ".") == 0 ) || (strcmp(dir -> d_name, "..") == 0)){ 

    
    }else{

        cout << dir->d_name << endl;
      }
    }       // print entry name
    closedir(pwd);                               // close directory; avoid memory leak
  } // if

  


}//can delete 3

else if(aflag == 0 && lflag == 0 && argc >= 2){

list<struct dirent *> entries;                 // entry list
  struct dirent * entry = nullptr;               // entry pointer
  DIR * pwd = opendir(argv[1]);                      // open directory

  if (pwd == nullptr) { 
    perror("ls");
  } else {
    while ((entry = readdir(pwd)) != nullptr) {  // read entries
      entries.push_back(entry);                  // add entry to list
    } // while
    entries.sort(direnticmp);                    // sort entries
    for (auto dir : entries){
   if(dir -> d_name[0] == '.' ||(strcmp(dir -> d_name, ".") == 0 ) || (strcmp(dir -> d_name, "..") == 0)){ 

    
    }else{

        cout << dir->d_name << endl;
      }
    }       // print entry name
    closedir(pwd);                               // close directory; avoid memory leak
  } // if



}

else if(aflag == 0 && lflag == 1 && argc > 2){

  list<struct dirent *> entries;                 // entry list
  struct dirent * entry = nullptr;               // entry pointer
  DIR * pwd = opendir(argv[2]);                      // open directory
  char first;
  int mode = buf.st_mode & 07777;
  char str2[50];
  char strd[50];
  char strh[50];
  
  if (pwd == nullptr) { 
    perror("ls");
  } else {
    while ((entry = readdir(pwd)) != nullptr) {  // read entries
      entries.push_back(entry);                  // add entry to list
    } // while
    entries.sort(direnticmp);                     // sort entries
    for (auto dir : entries){
      strcpy(strd, argv[2]);
      strcpy(strh, dir -> d_name);
      strncat(strd, strh, 100);
     stat(strd, &buf); 
     
       switch (buf.st_mode & S_IFMT) {
      case S_IFBLK: 
      //printf("block device\n"); 
      first = 'b'; 
      break; 
      case S_IFCHR:
      //printf("character device\n"); 
      first = 'c';
      break;
      case S_IFDIR: 
      //printf("directory\n");
      first = 'd';
      break;
      case S_IFIFO: 
      //printf("FIFO/pipe\n"); 
      first = 'p';
      break;
      case S_IFLNK: 
      //printf("symlink\n");
      first = 'l';
      break;
      case S_IFREG: 
      //printf("regular file\n"); 
      first= '-';
      break;
      case S_IFSOCK: 
      //printf("socket\n"); 
      first = 's';
      break;
      default: 
      printf("unknown?\n");
      first = '?';
      break;
    }
            
    if(dir -> d_name[0] == '.' ||(strcmp(dir -> d_name, ".") == 0 ) || (strcmp(dir -> d_name, "..") == 0)){ 

    
    }else{
          printf(&first);
          if ((mode & S_IRUSR) && (mode & S_IREAD))
            printf("r");
          else
            printf("-");
          if ((mode & S_IWUSR) && (mode & S_IWRITE))
            printf("w");
          else
            printf("-");
          if ((mode & S_IXUSR) && (mode & S_IEXEC))
            printf("x");
          else
            printf("-");
          
          if ((mode & S_IRGRP) && (mode & S_IREAD))
            printf("r");
          else
            printf("-");
          if ((mode & S_IWGRP) && (mode & S_IWRITE))
            printf("w");
          else
            printf("-");
          if ((mode & S_IXGRP) && (mode & S_IEXEC))
            printf("x");
          else
            printf("-");
  
          if ((mode & S_IROTH) && (mode & S_IREAD))
            printf("r");
          else
            printf("-");
          if ((mode & S_IWOTH) && (mode & S_IWRITE))
            printf("w");
          else
            printf("-");
          if ((mode & S_IXOTH) && (mode & S_IEXEC))
            printf("x)");
          else
            printf("-");
       }     
   if(dir -> d_name[0] == '.' ||(strcmp(dir -> d_name, ".") == 0 ) || (strcmp(dir -> d_name, "..") == 0)){ 

    
    }else{         
            
  cout << ". ";
  printf("%ld", buf.st_nlink);
  cout << " ";
  cout << "everage ";
  cout << "ugrad ";
  printf("%ld", buf.st_size);
  cout << " ";
  time_t time2 = (buf.st_mtime);
  struct tm * p = localtime(&time2);
  strftime(str2, 100, "%b %e %R",p);
  printf("%s", str2);
    
    
     cout << " " << dir->d_name << endl; 
     }
    }      // for
    closedir(pwd);                               // close directory; avoid memory leak
  } // if

  


}

else if(aflag == 0 && lflag == 1 && argc <= 2){

   list<struct dirent *> entries;                 // entry list
  struct dirent * entry = nullptr;               // entry pointer
  DIR * pwd = opendir(".");                      // open directory
  char first;
  int mode = buf.st_mode & 07777;
  char str2[50];
  if (pwd == nullptr) { 
    perror("ls");
  } else {
    while ((entry = readdir(pwd)) != nullptr) {  // read entries
      entries.push_back(entry);                  // add entry to list
    } // while
    entries.sort(direnticmp);                     // sort entries
    for (auto dir : entries){
      
     stat(dir -> d_name, &buf); 
     
       switch (buf.st_mode & S_IFMT) {
      case S_IFBLK: 
      //printf("block device\n"); 
      first = 'b';
      break;
      case S_IFCHR:
      //printf("character device\n"); 
      first = 'c';
      break;
      case S_IFDIR: 
      //printf("directory\n");
      first = 'd';
      break;
      case S_IFIFO: 
      //printf("FIFO/pipe\n"); 
      first = 'p';
      break;
      case S_IFLNK: 
      //printf("symlink\n");
      first = 'l';
      break;
      case S_IFREG: 
      //printf("regular file\n"); 
      first= '-';
      break;
      case S_IFSOCK: 
      //printf("socket\n"); 
      first = 's';
      break;
      default: 
      printf("unknown?\n");
      first = '?';
      break;
    }
            
    if(dir -> d_name[0] == '.' ||(strcmp(dir -> d_name, ".") == 0 ) || (strcmp(dir -> d_name, "..") == 0)){ 

    
    }else{
          printf(&first);
          if ((mode & S_IRUSR) && (mode & S_IREAD))
            printf("r");
          else
            printf("-");
          if ((mode & S_IWUSR) && (mode & S_IWRITE))
            printf("w");
          else
            printf("-");
          if ((mode & S_IXUSR) && (mode & S_IEXEC))
            printf("x");
          else
            printf("-");
          
          if ((mode & S_IRGRP) && (mode & S_IREAD))
            printf("r");
          else
            printf("-");
          if ((mode & S_IWGRP) && (mode & S_IWRITE))
            printf("w");
          else
            printf("-");
          if ((mode & S_IXGRP) && (mode & S_IEXEC))
            printf("x");
          else
            printf("-");
  
          if ((mode & S_IROTH) && (mode & S_IREAD))
            printf("r");
          else
            printf("-");
          if ((mode & S_IWOTH) && (mode & S_IWRITE))
            printf("w");
          else
            printf("-");
          if ((mode & S_IXOTH) && (mode & S_IEXEC))
            printf("x)");
          else
            printf("-");
         }   
     if(dir -> d_name[0] == '.' ||(strcmp(dir -> d_name, ".") == 0 ) || (strcmp(dir -> d_name, "..") == 0)){ 

    
    }else{       
            
    cout << ". ";
    printf("%ld", buf.st_nlink);
    cout << " ";
    cout << "everage ";
    cout << "ugrad ";
    printf("%ld", buf.st_size);
    cout << " ";
    time_t time2 = (buf.st_mtime);
    struct tm * p = localtime(&time2);
    strftime(str2, 100, "%b %e %R",p);
    printf("%s", str2);
    cout << " " << dir->d_name << endl; 

      }
    }
    closedir(pwd);                               // close directory; avoid memory leak
  } // if
  }
  
 else if(aflag == 1 && lflag == 1 && argc >= 3 ){



  list<struct dirent *> entries;                 // entry list
  struct dirent * entry = nullptr;               // entry pointer
  DIR * pwd = opendir(argv[2]);                      // open directory
  char first;
  int mode = buf.st_mode & 07777;
   char str2[50];
  char strd[50];
  char strh[50];
  
  if (pwd == nullptr) { 
    perror("ls");
  } else {
    while ((entry = readdir(pwd)) != nullptr) {  // read entries
      entries.push_back(entry);                  // add entry to list
    } // while
    entries.sort(direnticmp);                     // sort entries
    for (auto dir : entries){
      strcpy(strd, argv[2]);
      strcpy(strh, dir -> d_name);
      strncat(strd, strh, 100);
     stat(strd, &buf); 
     
       switch (buf.st_mode & S_IFMT) {
      case S_IFBLK: 
      //printf("block device\n"); 
      first = 'b';
      break;
      case S_IFCHR:
      //printf("character device\n"); 
      first = 'c';
      break;
      case S_IFDIR: 
      //printf("directory\n");
      first = 'd';
      break;
      case S_IFIFO: 
      //printf("FIFO/pipe\n"); 
      first = 'p';
      break;
      case S_IFLNK: 
      //printf("symlink\n");
      first = 'l';
      break;
      case S_IFREG: 
      //printf("regular file\n"); 
      first= '-';
      break;
      case S_IFSOCK: 
      //printf("socket\n"); 
      first = 's';
      break;
      default: 
      printf("unknown?\n");
      first = '?';
      break;
    }
            
    if((strcmp(dir -> d_name, ".") == 0 ) || (strcmp(dir -> d_name, "..") == 0)){ 

    
    }else{
          printf(&first);
          if ((mode & S_IRUSR) && (mode & S_IREAD))
            printf("r");
          else
            printf("-");
          if ((mode & S_IWUSR) && (mode & S_IWRITE))
            printf("w");
          else
            printf("-");
          if ((mode & S_IXUSR) && (mode & S_IEXEC))
            printf("x");
          else
            printf("-");
          
          if ((mode & S_IRGRP) && (mode & S_IREAD))
            printf("r");
          else
            printf("-");
          if ((mode & S_IWGRP) && (mode & S_IWRITE))
            printf("w");
          else
            printf("-");
          if ((mode & S_IXGRP) && (mode & S_IEXEC))
            printf("x");
          else
            printf("-");
  
          if ((mode & S_IROTH) && (mode & S_IREAD))
            printf("r");
          else
            printf("-");
          if ((mode & S_IWOTH) && (mode & S_IWRITE))
            printf("w");
          else
            printf("-");
          if ((mode & S_IXOTH) && (mode & S_IEXEC))
            printf("x)");
          else
            printf("-");
  }
            
            
    if((strcmp(dir -> d_name, ".") == 0 ) || (strcmp(dir -> d_name, "..") == 0)){ 

    
    }else{        
  cout << ". ";
  printf("%ld", buf.st_nlink);
  cout << " ";
  cout << "everage ";
  cout << "ugrad ";
  printf("%ld", buf.st_size);
  cout << " ";
  time_t time2 = (buf.st_mtime);
  struct tm * p = localtime(&time2);
  strftime(str2, 100, "%b %e %R",p);
  printf("%s", str2);
    
    
     cout << " " << dir->d_name << endl; 
     }
    }      // for
    closedir(pwd);                               // close directory; avoid memory leak
  } // if

  
                    

}//can delete this one

return 0;

}