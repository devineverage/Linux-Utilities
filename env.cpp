#include <stdio.h>


using namespace std;

int main(const int argc, const char *argv[], char ** envp){


char ** env;
for(env = envp; *env != 0; env++){

    char* thisEnv = *env;
    printf("%s\n", thisEnv);
  
  }



return 0;

}





