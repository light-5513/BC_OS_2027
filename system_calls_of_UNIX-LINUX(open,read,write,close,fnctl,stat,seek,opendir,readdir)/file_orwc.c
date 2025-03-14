#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int fd1,fd2;
    char buffer[1024];
    ssize_t bytesread, byteswritten;

    fd1 = open("file1.txt", O_RDONLY);
    if (fd1<0)
    {
        perror("error opening file");
        exit(1);
    }

    fd2 = open("file2.txt", O_WRONLY | O_CREAT, 0644);
    if(fd2<0)
    {
        perror("error opening file");
        exit(1);
    }

    while((bytesread = read(fd1, buffer, sizeof(buffer)))>0)
    {
        byteswritten = write(fd2, buffer, (ssize_t)bytesread);
        if(byteswritten != bytesread)
        {
            perror("error writing to file");
            exit(1);
        }
    }

    close(fd1);
    close(fd2);

    printf("file copied successfully\n");
    return 0;
}

