//
// Created by pranay on 9/29/20.
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
    if(strncmp(argv[0],"-v",2)==0 && strcmp(argv[1],"")!=0 ){
        int ch=mkdir(argv[1],0777);
        if(ch==-1){
            printf("mkdir can't make file %s already exits\n",argv[1]);
            perror("");
        }else{
            printf("mkdir: created directory '%s'\n",argv[1]);
        }
        if(strcmp(argv[2],"")!=0){
            ch=mkdir(argv[2],0777);
            if(ch==-1){
                printf("mkdir can't make file %s already exits\n",argv[2]);
                perror("");
            }
            else{
                printf("mkdir: created directory '%s'\n",argv[2]);
            }
        }
    }
    else if(strncmp(argv[0],"-p",2)==0 && strcmp(argv[1],"")!=0){
        char b[200];
        for(int i=0;i<200;i++){b[i]='\0';}
        int m=0;
        for(int i=0;i<strlen(argv[1]);i++){
            if(argv[1][i]=='/'){
                mkdir(b,0777);
            }
            b[m]=argv[1][i];
            m++;
        }
        mkdir(argv[1],0777);
    }
    else if(strcmp(argv[0],"")!=0 ){
        int ch=mkdir(argv[0],0777);
        if(ch==-1){
            printf("mkdir can't make file %s already exits\n",argv[0]);
            perror("");
        }
        if(strcmp(argv[1],"")!=0){
        ch=mkdir(argv[1],0777);
        if(ch==-1){
            printf("mkdir can't make file %s already exits\n",argv[1]);
            perror("");
        }
        }
        if(strcmp(argv[2],"")!=0){
        ch=mkdir(argv[2],0777);
        if(ch==-1){
            printf("mkdir can't make file %s already exits\n",argv[2]);
            perror("");
        }
        }
    }
    else{
        printf("mkdir: Invalid input\n");
    }
}
