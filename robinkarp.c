#include<stdio.h>
#include<string.h>
#include<conio.h>
int hashing_function(char * str,int x)
{
int i,sum=0;
for(i=0;i<x;i++)
sum+=*(str+i);
sum=sum%200;
return sum;
}
void KarpRobinR(char *x,int m,char *y,int n)
{int hx,hy,i,j;
printf("\nstring:[%s]"
	"\nlength:[%d]"
	"\npattern:[%s]"
	"\nlength:[%d]\n\n",y,n,x,m);

hx=hashing_function(x,strlen(x));
j=0;

while(j<=n-m)
{
	hy=hashing_function(&y[j],strlen(x));
	if((hx==hy)&&(memcmp(x,y+j,m)==0)){
printf("Match found at [%d]\n",j);}

++j;}}

int main()
{char * string="heroheroheorhero",*pattern="heor";
KarpRobinR(pattern,strlen(pattern),string,strlen(string));
printf("\n\n");
getch();
return 0;}