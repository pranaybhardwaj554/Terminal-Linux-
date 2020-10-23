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
    char c;
    if(strncmp(argv[1],"-n",2)==0){
        int number=1;
        FILE * file=fopen(argv[2],"r");
        if(file==NULL){
            perror("");
        }
        char line[1000];
        while(fgets(line,1000,file)!=NULL){
            printf("%d)%s",number,line);
            number++;
        }
        fclose(file);
    }
    else if(strncmp(argv[1],"-E",2)==0){
        FILE * file=fopen(argv[2],"r");
        if(file==NULL){
            perror("");
        }
        char line[1000];
        while(fscanf(file,"%[^\n]\n",line) != EOF){
            strcat(line,"$");
            printf("%s\n",line);
        }
        fclose(file);
    }
    else if(strcmp(argv[2],"")==0 && strcmp(argv[1],"")!=0){
        FILE * file=fopen(argv[1],"r");
        if(file==NULL){
            perror("");
        }
        c = fgetc(file);
        while (c != EOF)
        {
            printf ("%c", c);
            c = fgetc(file);
        }
        fclose(file);
    }
    else if(strcmp(argv[2],"")!=0 && strcmp(argv[1],"")!=0){
        FILE * file=fopen(argv[1],"r");
        if(file==NULL){
            perror("");
            exit(1);
        }
        FILE * file1=fopen(argv[2],"r");
        if(file1==NULL){
            perror("");
            exit(1);
        }
        c = fgetc(file);
        while (c != EOF)
        {
            printf ("%c", c);
            c = fgetc(file);
        }
        fclose(file);
        printf("\n");
        c = fgetc(file1);
        while (c != EOF)
        {
            printf ("%c", c);
            c = fgetc(file1);
        }
        fclose(file1);
    }
    else{
        printf("Invalid Input");
    }
}
