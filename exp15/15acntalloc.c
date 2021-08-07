/* Contiguous Allocation - cntalloc.c */

#include <stdio.h>
#include <string.h>

int num=0, length[10], start[10];
char fid[20][4], a[20][4];

void directory()
{
   int i;
   printf("\nFile Start Length\n");
     

    for(i=0; i<num; i++)
       printf("%-4s %3d %6d\n",fid[i],start[i],length[i]);
}

void display()
{
   int i;
   for(i=0; i<20; i++)
      printf("%4d",i);
   printf("\n");
   for(i=0; i<20; i++)
      printf("%4s", a[i]);
}

main()
{
   int i,n,k,temp,st,nb,ch,flag;
   char id[4];

    for(i=0; i<20; i++)
       strcpy(a[i], "");
    printf("Disk space before allocation:\n");
    display();
    do
    {
       printf("\nEnter File name (max 3 char) : ");
       scanf("%s", id);
       printf("Enter start block : ");
       scanf("%d", &st);
       printf("Enter no. of blocks : ");
       scanf("%d", &nb);
       strcpy(fid[num], id);
       length[num] = nb;
       flag = 0;

      if((st+nb) > 20)
      {
         printf("Requirement exceeds range\n");
         continue;
      }

      for(i=st; i<(st+nb); i++)
         if(strcmp(a[i], "") != 0)
            flag = 1;
      if(flag == 1)
      {
         printf("Contiguous allocation not possible.\n");
         continue;
      }
      start[num] = st;
      for(i=st; i<(st+nb); i++)
    

            strcpy(a[i], id);;
         printf("Allocation done\n");
         num++;

       printf("\nAny more allocation (1. yes / 2. no)? : ");
       scanf("%d", &ch);
    } while (ch == 1);
    printf("\n\t\t\tContiguous Allocation\n");
    printf("Directory:");
    directory();
    printf("\nDisk space after allocation:\n");
    display();
}