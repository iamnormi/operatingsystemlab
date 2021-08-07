/* Shared memory server - shms.c */

#include   <stdio.h>
#include   <stdlib.h>
#include   <sys/un.h>
#include   <sys/types.h>
#include   <sys/ipc.h>
#include   <sys/shm.h>

#define shmsize 27

main()
{
   char c;
   int shmid;
   key_t key = 2013;
   char *shm, *s;

    if ((shmid = shmget(key, shmsize, IPC_CREAT|0666)) < 0)
    {
       perror("shmget");
       exit(1);
    }
    printf("Shared memory id : %d\n", shmid);

    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1)
    {
       perror("shmat");
       exit(1);
    }

    memset(shm, 0, shmsize);
    s = shm;
    printf("Writing (a-z) onto shared memory\n");
    for (c = 'a'; c <= 'z'; c++)
       *s++ = c;
    *s = '\0';

    while (*shm != '*');
    printf("Client finished reading\n");

    if(shmdt(shm) != 0)
       fprintf(stderr, "Could not close memory segment.\n");

    shmctl(shmid, IPC_RMID, 0);
}