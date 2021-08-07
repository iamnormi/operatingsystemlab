#include <stdio.h>

struct process
{
   int size;
   int flag;
   int holeid;
} p[10];

struct hole
{
   int hid;
   int size;
   int actual;
} h[10];
 


main()
{
   int i, np, nh, j;
   void bsort(struct hole[], int);
   printf("Enter the number of Holes : ");
   scanf("%d", &nh);
   for(i=0; i<nh; i++)
   {
      printf("Enter size for hole H%d : ",i);
      scanf("%d", &h[i].size);
      h[i].actual = h[i].size;
      h[i].hid = i;
   }
   printf("\nEnter number of process : " );
   scanf("%d",&np);
   for(i=0;i<np;i++)
   {
      printf("enter the size of process P%d : ",i);
      scanf("%d", &p[i].size);
      p[i].flag = 0;
   }
   for(i=0; i<np; i++)
   {
      bsort(h, nh);
      for(j=0; j<nh; j++)
      {
         if(p[i].flag != 1)
         {
            if(p[i].size <= h[j].size)
            {
               p[i].flag = 1;
               p[i].holeid = h[j].hid;
               h[j].size -= p[i].size;
            }
         }
      }
   }
   printf("\n\tBest fit\n");
   printf("\nProcess\tPSize\tHole");
   for(i=0; i<np; i++)
   {
      if(p[i].flag != 1)
         printf("\nP%d\t%d\tNot allocated", i, p[i].size);
      else
         printf("\nP%d\t%d\tH%d", i, p[i].size, p[i].holeid);
   }
   printf("\n\nHole\tActual\tAvailable");
   for(i=0; i<nh ;i++)
      printf("\nH%d\t%d\t%d", h[i].hid, h[i].actual,
h[i].size);
            

    printf("\n");
}

void bsort(struct hole bh[], int n)
{
   struct hole temp;
   int i,j;
   for(i=0; i<n-1; i++)
   {
      for(j=i+1; j<n; j++)
      {
         if(bh[i].size > bh[j].size)
         {
            temp = bh[i];
            bh[i] = bh[j];
            bh[j] = temp;
         }
      }
   }
}