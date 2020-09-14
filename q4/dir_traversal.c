
#define _XOPEN_SOURCE 700//enables Posix 2008 features
#include <stdlib.h>
#include <unistd.h>
#include <ftw.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include<sys/types.h>
#include <sys/stat.h>


#ifndef USE_FDS
#define USE_FDS 15//each file has entry in the filedescriptor table we set it to 15 which is a reasonable value
#endif

int is_file(const char *path)//use struct path features to print file type and inode
{
    struct stat path_stat;//stat system call
    stat(path,&path_stat);
    printf("%ld ",path_stat.st_ino);//momber inode
    return S_ISREG(path_stat.st_mode);
}



int print_entry(const char *filepath, const struct stat *info,
                const int typeflag, struct FTW *pathinfo)
{
    char c;
    if(is_file(filepath))
    {
        c='F';
    }
    else
    {
        c='D';
    }

    
    
     if (typeflag == FTW_F)
        printf("%c %s\n",c,filepath);
    
    else if (typeflag == FTW_D )
        printf("%c %s/\n",c, filepath);
    
    
    else
        printf("\n");//ignore soft link

    return 0;
}


int print_directory_tree(const char *const dirpath)
{
    int result;

    /* directory is not valid */
    if (dirpath == NULL || *dirpath == '\0')
        return errno = EINVAL;

    result = nftw(dirpath, print_entry, USE_FDS, FTW_PHYS);//
    if (result >= 0)
        errno = result;

    return errno;
}

int main(int argc, char *argv[])
{
    int arg;

    if (argc < 2) {

        if (print_directory_tree(".")) {
            fprintf(stderr, "%s.\n", strerror(errno));
            return 1;
        }

    } else {

        for (arg = 1; arg < argc; arg++) {
            if (print_directory_tree(argv[arg])) {
                fprintf(stderr, "%s.\n", strerror(errno));
                return 1;
            }
        }

    }

    return 0;
}