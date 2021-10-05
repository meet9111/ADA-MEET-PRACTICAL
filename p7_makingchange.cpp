#include <stdio.h>
#include <stdlib.h>
int main()
{

int item[]={500,200,100,50,10,1},n,i=0,j;
 printf("Enter Total:");
  scanf("%d",&n);
while(n>0)
{
	if(n>=item[i])
	{
		n=n-item[i];
		printf(" %d " ,item[i]);
	}
else
	{
		i++;
	}
}
return 0;
}

