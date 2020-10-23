//
// Created by pranay on 9/28/20.
//
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
void main(int argc, char *argv[]){
    char *p;
    struct tm *local;
    time_t localtime;
    time(&localtime);
    char blr[PATH_MAX];
    struct stat attr;
    if(strcmp(argv[1],"")==0){
        printf("%s",ctime(&localtime));
    }
    else if(strncmp(argv[1],"-u",2)==0){
        localtime=time(NULL);
        local=gmtime(&localtime);
        printf("%s",asctime(local));
    }
    else if(strncmp(argv[1],"-r",2)==0){
        stat(argv[2], &attr);
        p=ctime(&attr.st_mtime);
        if(strncmp(p,"Tue Jan 20 19:24:08 1970",24)!=0){
            printf("%s",ctime(&attr.st_mtime));
        }
        else{
            perror("error");
        }
    }
}
