#define _XOPEN_SOURCE 500
#include <ftw.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>


static int link(const char *n){
    struct stat buf;
    if(lstat(n,&buf)<0){
        perror("Error occured");
        exit(1);
    }
    if (S_ISLNK(buf.st_mode)==1)
        return 1;
    return 0;
}
static int display_info(const char *fpath, const struct stat *sb,
             int tflag, struct FTW *ftwbuf)
{
  
    char t=0;
    if(tflag == FTW_D)
       t='D';
    if (tflag == FTW_F)
            t='F';
    if (t!=0 && link(fpath)!=1){
        printf("%c ",t);

    printf("%ld %s\n",sb->st_ino,fpath+ftwbuf->base);
    }
      
    return 0;           /* To tell nftw() to continue */
}

int main(int argc, char *argv[])
{
    int flags = 0;

    if (argc > 2 && strchr(argv[2], 'd') != NULL)
         flags |= FTW_DEPTH;
     if (argc > 2 && strchr(argv[2], 'p') != NULL)
         flags |= FTW_PHYS;
   
   if (nftw((argc < 2) ? "." : argv[1], display_info, 20, flags)
            == -1) {
        perror("nftw");
        exit(EXIT_FAILURE);
    
    }
    exit(EXIT_SUCCESS);
}