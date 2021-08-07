
/* rm command simulation - del.c */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

main(int argc, char* argv[])
{
   int fd;

    if (argc != 2)
    {
       printf("Usage: gcc del.c -o del\n");
       printf("Usage: ./del <filename>\n");
       exit(-1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd != -1)
    {
       close(fd);
       unlink(argv[1]);
    }
    else
       perror(argv[1]);
}