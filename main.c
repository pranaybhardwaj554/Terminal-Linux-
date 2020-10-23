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
#include <sys/wait.h>
#include <dirent.h>
extern int errno;
int main(){
    char external[PATH_MAX];
    getcwd(external,PATH_MAX);
    char okiesh[PATH_MAX];
    char echo[]="echo", cd[]="cd",history[]="history",pwd[]="pwd",exit1[]="exit",ls[]="ls",date1[]="date";
    char *token;
    int hist[]={0};
    // echo//
    FILE *file10;
    char cdhelp[PATH_MAX];
    char historyhelp[PATH_MAX];
    char history1[PATH_MAX];
    strcpy(history1,external);
    strcat(history1,"/history.txt");
    strcpy(historyhelp,external);
    strcat(historyhelp,"/historyhelp.txt");
    strcpy(cdhelp,external);
    strcat(cdhelp,"/cdhelp.txt");
    while(1){
        char str[2000];
        char str1[2000];
        char str2[2000];
        char str3[2000];
        char str4[2000];
        char str5[2000];
        for(int i=0;i<2000;i++){ str[i]='\0'; str1[i]='\0'; str2[i]='\0'; str3[i]='\0';str4[i]='\0';str5[i]='\0'; }
        fgets(str, 2000, stdin);
        strcpy(str1,str);
        strcpy(str5,str);
        token=strtok(str," ");
        if(strncmp(token,echo,4)==0){
            token=strtok(NULL," ");
            char str2[2000];
            if(strcmp(token,"-e")==0 || strcmp(token,"-e\n")==0){
                int j=1;
                for(int i=0;i<strlen(str1);i++){
                    if(str1[i]=='\\' && str1[j]=='c'){
                        str1[i]='\0';
                    }
                    j++;
                }
                j=1;
                int m=2;
                int k=0;
                for(int i=0;i<strlen(str1);i++,j++,m++){
                    if(str1[j]=='\\' && str1[m]=='b'){
                        i=m;
                        j=i+1;
                        m=j+1;
                    }
                    else{
                        str2[k]=str1[i];
                        k++;
                    }
                }
                strcpy(str1,str2);
                token=strtok(str1," ");
                token =strtok(NULL," ");
                token =strtok(NULL," ");
                while(token!=NULL){
                    printf( "%s ", token );
                    token = strtok(NULL, " ");
                }

            }
            else if(strcmp(token,"*")==0 || strcmp(token,"*\n")==0){
                int b=1;
                struct dirent *d;
                char curdirec1[PATH_MAX];
                getcwd(curdirec1,PATH_MAX);
                DIR *dr=opendir(curdirec1);
                while ((d = readdir(dr)) != NULL){
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
                printf("\n");
            }
            else if(strncmp(token,"-n",2)==0){
                strncpy(str3,str1,strlen(str1)-1);
                token=strtok(str3," ");
                token =strtok(NULL," ");
                token =strtok(NULL," ");
                while(token!=NULL){
                    printf( "%s ", token );
                    token = strtok(NULL, " ");
                }
            }
            else{
                token=strtok(str1," ");
                token =strtok(NULL," ");
                while(token!=NULL){
                    printf( "%s ", token );
                    token = strtok(NULL, " ");
                }

            }
        }
            //pwd
        else if (strncmp (token,pwd,3) == 0){
            token=strtok(NULL," ");
            if(token==NULL){
                getcwd (okiesh, PATH_MAX);
                printf ("%s\n",okiesh);
            }
            else if(strncmp(token,"-P",2)==0){
                char blah[PATH_MAX];
                char *a=realpath (getcwd(okiesh,PATH_MAX), blah);
                printf ("%s\n",a);
            }
            else if(strncmp(token,"--help",2)==0){
                printf ("pwd: pwd [-LP]\n");
                printf("Print the name of the current working directory.\n");

                printf("        Options:\n");
                printf("-L	print the value of $PWD if it names the current working\n");
                printf("directory\n");
                printf("-P	print the physical directory, without any symbolic links\n");

                printf("By default, `pwd' behaves as if `-L' were specified.\n");

                printf("        Exit Status:\n");
                printf("Returns 0 unless an invalid option is given or the current directory\n");
                printf("cannot be read.\n");
            }
                //ERROR HANDLED
            else if (strncmp(token,"-",1)==0){
                printf("bash: pwd: -%c: invalid option\n",token[1]);
                printf("pwd: usage: pwd [-LP]\n");
            }
            else{
                getcwd (okiesh, PATH_MAX);
                printf ("%s\n",okiesh);
            }
        }
            //exit///////
        else if(strncmp(token,exit1,4)==0){
            token=strtok(NULL," ");
            if(token==NULL){
                printf("Thanks for using the shell\n");
                return 0;
            }
            else if(strncmp(token,"--help",6)==0){
                printf("exit: exit [n]\n");
                printf("Exit the shell.\n");
                printf("Exits the shell with a status of N.  If N is omitted, the exit status\n");
                printf("is that of the last command executed.\n");
            }
            else{
                int a;
                sscanf(token, "%d", &a);
                printf("Thanks for using the shell\n");
                return (a);
            }
        }
        else if(strncmp(token,cd,2)==0){
            char b[PATH_MAX];
            int m=0;
            strncpy(str3,str1,strlen(str1)-1);
            for(int i=0;i<strlen(str3);i++){
                if(str3[i]=='\\'){
                    i++;
                }
                str2[m]=str3[i];
                m++;
            }
            char token2[2000];
            for(int i=0;i<2000;i++){token2[i]='\0'; token[i]='\0';}
            token=strtok(str2," ");
            //Error handled if there is an backslash in the string then it will be automatically cleared
            token=strtok(NULL," ");
            if(token!=NULL){
                strcpy(token2,token);
            }
            token=strtok(NULL," ");
            if(strcmp(token2,"")==0){
                chdir(getenv("HOME"));
                printf("New Directory %s\n",getcwd(b,PATH_MAX));
            }
            else if(strncmp(token2,"--help",6)==0){
                file10 =fopen(cdhelp,"r");
                char c1 = fgetc(file10);
                while (c1 != EOF)
                {
                    printf ("%c", c1);
                    c1 = fgetc(file10);
                }
                fclose(file10);
            }
            else if(strncmp(token2,"-P",2)==0){
               // token=strtok(NULL," ");
              //  strcpy(token2,token);
                int a=chdir(token);
                token=strtok(NULL," ");
                if (token==NULL && a!=-1){
                   // chdir(token);
                    printf("New Directory-%s\n",getcwd(b,PATH_MAX));
                }
                else if(a==-1 ){
                    perror("No such Directory found or Not a valid input\n");
                    // printf("or Not valid Input\n");
                }
                else{
                    chdir(getenv("HOME"));
                    printf("Invalid Input\n");
                }
            }
            else{
                int a=chdir(token2);
                if (token==NULL && a!=-1){
                  //  chdir(token);
                    printf("New Directory-%s\n",getcwd(b,PATH_MAX));
                }
                else if(a==-1 ){
                    perror("No such Directory found or Not a valid input\n");
                   // printf("or Not valid Input\n");
                }
                else{
                    chdir(getenv("HOME"));
                    printf("Invalid Input\n");
                }

            }
        }
        ////Help///////////////
        else if (strncmp(token,history,7)==0){
            token=strtok(NULL," ");
            if(token==NULL){
                file10 =fopen(history1,"r+");
                char c1 = fgetc(file10);
                while (c1 != EOF)
                {
                    printf ("%c", c1);
                    c1 = fgetc(file10);
                }
                fclose(file10);
            }
            else if(strncmp(token,"-c",2)==0){
                remove(history1);
                file10 =fopen(history1,"w");
                fclose(file10);
            }
            else if(strncmp(token,"--help",6)==0){
                file10 =fopen(historyhelp,"r");
                char c1 = fgetc(file10);
                while (c1 != EOF)
                {
                    printf ("%c", c1);
                    c1 = fgetc(file10);
                }
                fclose(file10);
            }
            else{
                printf("history:Invalid command\n");
            }
        }
        else if (strncmp(token,ls,2)==0){
            int m=0;
            ///removing backslash from the input
            strncpy(str3,str1,strlen(str1)-1);
            for(int i=0;i<strlen(str3);i++){
                if(str3[i]=='\\'){
                    i++;
                }
                str2[m]=str3[i];
                m++;
            }
            token = strtok(str2," ");
            token=strtok(NULL," ");
            char flag[2000];
            for(int i=0;i<2000;i++){ flag[i]='\0';}
            if(token!=NULL){
            strcpy(flag,token);
            }
            if(strncmp(flag,"-a",2)==0 || strncmp(flag,"-1",2)==0 || token==NULL ){
                pid_t pid,w;
                int wstatus;
                pid=fork();
                if(pid<0){
                    perror("Fork failed in ls\n");
                    exit(1);
                }
                else if (pid==0){
                    //child process
                    char curdirec[PATH_MAX];
                    getcwd(curdirec,PATH_MAX);
                    char direc[PATH_MAX];
                    strcpy(direc,external);
                    execl(strcat(direc,"/ls"),"ls",curdirec,flag,NULL);
                    exit(0);
                }
                else{
                    w=waitpid(pid , &wstatus , 0);//waiting for child to terminate.
                    if(w>0){
                        //printf("Parent executes");
                    }
                    else if(w==-1){
                        //waitpid() is failed
                        printf("waitpid is failed");
                        exit(1);
                    }
                }
            }
            else{
                printf("NO such command found\n");
            }

        }
        else if(strncmp(token,date1,4)==0){
            int m=0;
            ///removing backslash from the input
            strncpy(str3,str1,strlen(str1)-1);
            for(int i=0;i<strlen(str3);i++){
                if(str3[i]=='\\'){
                    i++;
                }
                str2[m]=str3[i];
                m++;
            }
            token = strtok(str2," ");
            token=strtok(NULL," ");
            char flag[2000];
            char file1[2000];
            for(int i=0;i<2000;i++){ flag[i]='\0'; file1[i]='\0';}
            if(token!=NULL){
                strcpy(flag,token);
            }
            token=strtok(NULL," ");
            if(token!=NULL){
                strcpy(file1,token);
            }
            if((strncmp(flag,"-u",2)==0 && strcmp(file1,"")==0)   || (strncmp(flag,"-r",2)==0 && strcmp(file1,"")!=0 ) || (strcmp(flag,"")==0 && strcmp(file1,"")==0) ){
                pid_t pid,w;
                int wstatus;
                pid=fork();
                if(pid<0){
                    perror("Fork failed in ls\n");
                    exit(1);
                }
                else if (pid==0){
                    //child process
                    char direc[PATH_MAX];
                    strcpy(direc,external);
                    char blr[PATH_MAX];
                    getcwd(blr,PATH_MAX);
                    execl(strcat(direc,"/date"),"date",flag,file1,NULL);
                    exit(0);
                }
                else{
                    w=waitpid(pid , &wstatus , 0);//waiting for child to terminate.
                    if(w>0){
                        //printf("Parent executes");
                    }
                    else if(w==-1){
                        //waitpid() is failed
                        printf("waitpid is failed");
                        exit(1);
                    }
                }
           }
            else{
                printf("error:Invalid input for date");
            }
        }
        else if(strncmp(token,"cat",3)==0){
            int m=0;
            ///removing backslash from the input
            strncpy(str3,str1,strlen(str1)-1);
            for(int i=0;i<strlen(str3);i++){
                if(str3[i]=='\\'){
                    i++;
                }
                str2[m]=str3[i];
                m++;
            }
            token = strtok(str2," ");
            token=strtok(NULL," ");
            char flag[2000];
            char file1[2000];
            for(int i=0;i<2000;i++){ flag[i]='\0'; file1[i]='\0';}
            if(token!=NULL){
                strcpy(flag,token);
            }
            token=strtok(NULL," ");
            if(token!=NULL){
                strcpy(file1,token);
            }
            pid_t pid,w;
            int wstatus;
            pid=fork();
            if(pid<0){
                perror("Fork failed in ls\n");
                exit(1);
            }
            else if (pid==0){
                //child process
                char direc[PATH_MAX];
                strcpy(direc,external);
                char blr[PATH_MAX];
                getcwd(blr,PATH_MAX);
                execl(strcat(direc,"/cat"),"cat",flag,file1,NULL);
                exit(0);
            }
            else{
                w=waitpid(pid , &wstatus , 0);//waiting for child to terminate.
                if(w>0){
                    //printf("Parent executes");
                }
                else if(w==-1){
                    //waitpid() is failed
                    printf("waitpid is failed");
                    exit(1);
                }
            }
        }
        else if(strncmp(token,"mkdir",5)==0){
            int m=0;
            ///removing backslash from the input
            strncpy(str3,str1,strlen(str1)-1);
            for(int i=0;i<strlen(str3);i++){
                if(str3[i]=='\\'){
                    i++;
                }
                str2[m]=str3[i];
                m++;
            }
            token = strtok(str2," ");
            token=strtok(NULL," ");
            char flag[2000];
            char file1[2000];
            char file2[2000];
            for(int i=0;i<2000;i++){ flag[i]='\0'; file1[i]='\0'; file2[i]='\0' ; }
            if(token!=NULL){
                strcpy(flag,token);
            }
            token=strtok(NULL," ");
            if(token!=NULL){
                strcpy(file1,token);
            }
            token=strtok(NULL," ");
            if(token!=NULL){
                strcpy(file2,token);
            }
            pid_t pid,w;
            int wstatus;
            pid=fork();
            if(pid<0){
                perror("Fork failed in ls\n");
                exit(1);
            }
            else if (pid==0){
                //child process
                char direc[PATH_MAX];
                strcpy(direc,external);
                char blr[PATH_MAX];
                getcwd(blr,PATH_MAX);
                execl(strcat(direc,"/mkdir"),flag,file1,file2,NULL);
                exit(0);
            }
            else{
                w=waitpid(pid , &wstatus , 0);//waiting for child to terminate.
                if(w>0){
                    //printf("Parent executes");
                }
                else if(w==-1){
                    //waitpid() is failed
                    printf("waitpid is failed");
                    exit(1);
                }
            }
        }
        else if(strncmp(token,"rm",2)==0){
            int m=0;
            ///removing backslash from the input
            strncpy(str3,str1,strlen(str1)-1);
            for(int i=0;i<strlen(str3);i++){
                if(str3[i]=='\\'){
                    i++;
                }
                str2[m]=str3[i];
                m++;
            }
            token = strtok(str2," ");
            token=strtok(NULL," ");
            char flag[2000];
            char file1[2000];
            char file2[2000];
            for(int i=0;i<2000;i++){ flag[i]='\0'; file1[i]='\0'; file2[i]='\0' ; }
            if(token!=NULL){
                strcpy(flag,token);
            }
            token=strtok(NULL," ");
            if(token!=NULL){
                strcpy(file1,token);
            }
            token=strtok(NULL," ");
            if(token!=NULL){
                strcpy(file2,token);
            }
            strcat(file2," ");
            strcat(file2,external);
            pid_t pid,w;
            int wstatus;
            pid=fork();
            if(pid<0){
                perror("Fork failed in ls\n");
                exit(1);
            }
            else if (pid==0){
                //child process
                char direc[PATH_MAX];
                strcpy(direc,external);
                char blr[PATH_MAX];
                getcwd(blr,PATH_MAX);
                execl(strcat(direc,"/rm"),flag,file1,file2,NULL);
                exit(0);
            }
            else{
                w=waitpid(pid , &wstatus , 0);//waiting for child to terminate.
                if(w>0){
                    //printf("Parent executes");
                }
                else if(w==-1){
                    //waitpid() is failed
                    printf("waitpid is failed");
                    exit(1);
                }
            }
        }
        else if(token==NULL){

        }
        else{
            printf("Invalid Input:Please check\n");
        }
        file10 =fopen(history1,"r+");
        char c;
        int count=0;
        for (c = getc(file10); c != EOF; c = getc(file10)){
            if (c == '\n'){
                count = count + 1;
            }
        }
        char scout[50];
        sprintf(scout, "%d", count+1);
        strcat(str4,scout);
        strcat(str4," ");
        strcat(str4,str5);
        fputs(str4,file10);
        fclose(file10);
    }
    return(0);
}
