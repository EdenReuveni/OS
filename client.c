#include<stdio.h>
#include<signal.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include <linux/sched.h>
#include <sys/resource.h>


int main(int argc, char *argv[])
 
{
    if(argv[1] && argv[2] && argv[3]){
    int server_id=atoi(argv[1]);
    int type=atoi(argv[2]);
     
    int num=atoi(argv[3]);
       switch (type){
      case 2:
        for(int i=0;i<num;i++){
          kill(server_id,SIGINT);
        }
        break;
      case 10:
        
          kill(server_id,SIGUSR1);
        
        break;
      default:
        printf("Only one of two signals is allowed: SIGINT(2) or SIGUSR1(10)\n");
        return 1;
       }
  // A long long wait so that we can easily issue a signal to this process
    
 
  return 0;
    }
    else{
        printf("You need to run the program along with the server pid AND signal number AND number of signals to be sent.\nTry again\n");
        return 1;
    }
}