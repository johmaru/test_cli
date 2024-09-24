//
// Created by Administrator on 2024/09/24.
//

#include "log_controller.h"

int create_directory(const char *path){
    if(mkdir(path) == 0){
        printf("Directory created successfully\n");
        return 0;
    }
    else{
        printf("Unable to create directory\n");
        return -1;
    }
}

int directory_exists(const char *path){
    if(opendir(path) == NULL){
        return -1;
    }
    else{
        return 0;
    }
}