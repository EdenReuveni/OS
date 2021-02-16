#include <errno.h>
#include <stdio.h>
#include <stdlib.h>


void check_pid(char* p_id){
    int pid=atoi(p_id);
    if (kill(pid,0)<0){
        if(errno==ESRCH)
            printf("Process %d does not exist.\n",pid);
        if(errno==EPERM)
            printf("Process %d exists but we have no permission.\n",pid);
    }
    else
        printf("Process %d exists.\n",pid);

}

int main(int argc, char*argv[]){


    if(argv[1]){
        check_pid(argv[1]);
        return 0;
    }
    else {
        printf("You need to run the program along with a pid.\nTry again\n");
        return 1;
    } 
    
}