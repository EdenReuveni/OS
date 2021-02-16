#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include <linux/sched.h>
#include <sys/resource.h>
#include <stdlib.h>


int count=0;
void sigint_handler(int signo)
{
  if (signo == SIGINT)
   count++;
}

void sigusr1_handler(int signo){

       


if (signo == SIGUSR1)
printf("Number of recevied signals: %d\n",count);
exit(0);
}

int main()
{


   printf("%d\n",getpid());
    

  // A long long wait so that we can easily issue a signal to this process
 while(1){
       signal(SIGINT, sigint_handler);
      signal(SIGUSR1, sigusr1_handler);

 }
     
  
   
  return 0;
}