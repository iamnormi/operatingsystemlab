#include <stdio.h>
#include <stdio.h>

main()
{
   int r[1][10], av[1][10];
   int all[10][10], max[10][10], ne[10][10], w[10],safe[10];
   int i=0, j=0, k=0, l=0, np=0, nr=0, count=0, cnt=0;

    clrscr();
    printf("enter the number of processes in a system");
    scanf("%d", &np);
    printf("enter the number of resources in a system");
    scanf("%d",&nr);
    for(i=1; i<=nr; i++)
    {
       printf("Enter no. of instances of resource R%d " ,i);
       scanf("%d", &r[0][i]);
       av[0][i] = r[0][i];
    }

    for(i=1; i<=np; i++)
       for(j=1; j<=nr; j++)
          all[i][j] = ne[i][j] = max[i][j] = w[i]=0;
         

printf("Enter the allocation matrix");
for(i=1; i<=np; i++)
{
   for(j=1; j<=nr; j++)
   {
       scanf("%d", &all[i][j]);
       av[0][j] = av[0][j] - all[i][j];
   }
}

printf("Enter the maximum matrix");
for(i=1; i<=np; i++)
{
   for(j=1; j<=nr; j++)
   {
         scanf("%d",&max[i][j]);
   }
}

for(i=1; i<=np; i++)
{
   for(j=1; j<=nr; j++)
   {
      ne[i][j] = max[i][j] - all[i][j];
   }
}

for(i=1; i<=np; i++)
{
   printf("pocess P%d", i);
   for(j=1; j<=nr; j++)
   {
      printf("\n allocated %d\t",all[i][j]);
      printf("maximum %d\t",max[i][j]);
      printf("need %d\t",ne[i][j]);
   }
   printf("\n_________________________\n");
}

printf("\nAvailability ");
for(i=1; i<=nr; i++)
   printf("R%d %d\t", i, av[0][i]);
printf("\n____________");
printf("\n safe sequence");
                                                   75

    for(count=1; count<=np; count++)
    {
      for(i=1; i<=np; i++)
      {
          Cnt = 0;
          for(j=1; j<=nr; j++)
          {
             if(ne[i][j] <= av[0][j] && w[i]==0)
                cnt++;
          }
          if(cnt == nr)
          {
             k++;
             safe[k] = i;
             for(l=1; l<=nr; l++)
                av[0][l] = av[0][l] + all[i][l];
             printf("\n P%d ",safe[k]);
             printf("\t Availability ");
             for(l=1; l<=nr; l++)
                printf("R%d %d\t", l, av[0][l]);
             w[i]=1;
          }
       }
    }
    getch();
}