/* Shared memory client - shmc.c */

#include   <stdio.h>
#include   <stdlib.h>
#include   <sys/types.h>
#include   <sys/ipc.h>
#include   <sys/shm.h>

#define shmsize 27

main()
{
   int shmid;
   key_t key = 2013;
   char *shm, *s;

    if ((shmid = shmget(key, shmsize, 0666)) < 0)
    {
       printf("Server not started\n");
       exit(1);
    }
    else
       printf("Accessing shared memory id : %d\n",shmid);

    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1)
    {
       perror("shmat");
       exit(1);
    }

    printf("Shared memory contents:\n");
    for (s = shm; *s != '\0'; s++)
       putchar(*s);
    putchar('\n');

    *shm = '*';
}