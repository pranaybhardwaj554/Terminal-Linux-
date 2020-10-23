#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <dirent.h>
void main(int argc, char *argv[]){//1st arument is ls ,2nd is address, 3rd is flag
    struct dirent *d;
    int a=1;
    int b=1;
    DIR *dr=opendir(argv[1]);
    while ((d = readdir(dr)) != NULL){
        if(strncmp(argv[2],"-a",2)==0){
            printf("%s  ", d->d_name);
            if(a%7==0){
                printf("\n");
            }
            a++;
        }
        if(strcmp(argv[2],"")==0){
            if(strncmp(d->d_name,".",1)==0){
                }
            else{
                printf("%s  ", d->d_name);
                if(b%7==0){
                    printf("\n");
                }
                b++;
            }
        }
        if(strncmp(argv[2],"-1",2)==0){
            if(strncmp(d->d_name,".",1)==0){

            }
            else{
                printf("%s\n", d->d_name);
            }
        }
    }
    closedir(dr);
    printf("\n");
}

