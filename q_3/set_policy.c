#define _GNU_SOURCE
#include <errno.h>		
#include <unistd.h>		
#include <sched.h>		
#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <linux/unistd.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <sys/syscall.h>
#include <pthread.h>
#include <linux/kernel.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <time.h>
#include <linux/types.h>
#include <sched.h>
#include <linux/sched.h>
#include <sys/types.h>

/* __NR_sched_setattr number */
#ifndef __NR_sched_setattr
#ifdef __x86_64__
#define __NR_sched_setattr      314
#endif

#ifdef __i386__
#define __NR_sched_setattr      351
#endif

#ifdef __arm__
#define __NR_sched_setattr      380
#endif

#ifdef __aarch64__
#define __NR_sched_setattr      274
#endif
#endif

/* __NR_sched_getattr number */
#ifndef __NR_sched_getattr
#ifdef __x86_64__
#define __NR_sched_getattr      315
#endif

#ifdef __i386__
#define __NR_sched_getattr      352
#endif

#ifdef __arm__
#define __NR_sched_getattr      381
#endif

#ifdef __aarch64__
#define __NR_sched_getattr      275
#endif
#endif

struct sched_attr {
    __u32 size;
    __u32 sched_policy;
    __u64 sched_flags;
    __s32 sched_nice;
    __u32 sched_priority;
    __u64 sched_runtime;
    __u64 sched_deadline;
    __u64 sched_period;
};

int sched_setattr(pid_t pid,
               const struct sched_attr *attr,
               unsigned int flags)
{
     return syscall(__NR_sched_setattr, pid, attr, flags);
}

 void set_policy(char* poli,char* prio){
    int priority=atoi(prio);
    int policy=atoi(poli);
    printf("Server's pid: %d\n",getpid()); 
    struct sched_param param;
    if (policy==0 || policy==3 || policy==5){
        param.sched_priority=0;
            sched_setscheduler(0,policy,&param);
    }
    else{
        param.sched_priority=priority;
        sched_setscheduler(0,policy,&param);
    }
    struct sched_attr attr;
    if (policy==6){
        attr.size = sizeof(attr);
        attr.sched_policy=6;
        attr.sched_runtime = 10 * 100 * 1000;
        attr.sched_period = 2*100*100*1000;
        attr.sched_deadline = 11 * 1000 * 1000;
        attr.sched_flags=0;
        sched_setattr(0, &attr, attr.sched_flags);
     

      }
     
    
 }

/*
other: 0
deadline: 6
fifo: 1
idle: 5
rr: 2
*/

int main(int argc, char* argv[]){
    if (argv[1] && argv[2]){
   
        set_policy(argv[1],argv[2]);
    
        while(1){}
        
        return 0;
    }
    else
    {
        printf("You need to run the program along with a policy number AND a priority number.\nTry again\n");
        return 1;
    }
}



