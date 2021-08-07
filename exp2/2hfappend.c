/* File append - fappend.c */

#include     <stdio.h>
#include     <string.h>
#include     <stdlib.h>
#include     <fcntl.h>

main(int argc, char *argv[])
{
   int fd, n, len;
   char buf[100];

    if (argc != 2)
    {
       printf("Usage: ./a.out <filename>\n");
       exit(-1);
    }



    fd = open(argv[1], O_APPEND|O_WRONLY|O_CREAT, 0644);
    if (fd < 0)
    {
       perror(argv[1]);
       exit(-1);
    }

    while((n = read(0, buf, sizeof(buf))) > 0)
    {
       len = strlen(buf);
       write(fd, buf, len);
    }

    close(fd);
}


