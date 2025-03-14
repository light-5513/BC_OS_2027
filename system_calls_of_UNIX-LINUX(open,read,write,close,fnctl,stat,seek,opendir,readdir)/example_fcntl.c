#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int fd= open("file1.txt", O_RDWR);
    if(fd<0)
    {
        perror("error opening file");
        exit(1);
    }

    int flags= fcntl(fd, F_GETFL);
    if(flags<0)
    {
        perror("error getting flags");
        exit(1);
        close(fd);
    }

    if (flags & O_RDONLY) printf("file is read only\n");
    if(flags & O_WRONLY) printf("file is write only\n");
    if (flags & O_RDWR) printf("file is read write\n");


    close(fd);
    return 0;
    
}