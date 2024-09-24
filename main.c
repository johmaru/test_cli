#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include "core/log_controller.h"

#ifndef MAX_BUF
#define MAX_BUF 200
#endif


int main(void) {
    char path[MAX_BUF];
   getcwd(path, MAX_BUF);
    printf("Current working directory: %s\n",path);

    if(directory_exists("logs") == -1){
        create_directory("logs");
    }



    return 0;
}
