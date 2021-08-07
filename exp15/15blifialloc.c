#include <stdio.h> 
#include <string.h> 

int main() 
{ 
 static int b[20], i, j, blocks[20][20]; 
 char F[20][20], S[20], ch; 
 int sb[20], eb[20], x, n; 
 printf("\n Enter no. of Files ::");
 scanf("%d",&n);
 for(i=0;i<n;i++) 
 { 
 	printf("\n Enter file %d name ::", i+1); 
 	scanf("%s", &F[i]); 
 	printf("\n Enter No. of blocks::", i+1); 
 	scanf("%d",&b[i]); 
 } 
 
 for(i=0;i<n;i++) 
 { 
 	printf("\n Enter Starting block of file%d::",i+1); 
 	scanf("%d", &sb[i]); 
 	printf("\nEnter blocks for file%d::\n", i+1); 
 	for(j=0; j<b[i]-1;) 
 	{ 
 		printf("\n Enter the %dblock ::", j+2); 
 		scanf("%d", &x); 
 		if(b[i] != 0) 
 		{ 
 			blocks[i][j] = x; 
 			j++; 
 		}	 
 		else 
 		printf("\n Invalid block::"); 
 	}	 
 } 
 printf("\nEnter the Filename :"); 
 scanf("%s", &S); 
 for(i=0; i<n; i++) 
{ 
	 if(strcmp(F[i],S) == 0) 
 	{	 
 		printf("\nFname\tBsize\tStart\tBlocks\n"); 
 		printf("\n--------------------------------------\n"); 
 		printf("\n%s\t%d\t%d\t", F[i], b[i], sb[i]); 
 		printf("%d->",sb[i]); 
 		for(j=0; j<b[i]; j++) 
 		{ 
 			if(b[i] != 0) 
 				printf("%d->", blocks[i][j]); 
 		}			 
 	} 
 } 
 printf("\n-------------------------------------------\n"); 
 }
