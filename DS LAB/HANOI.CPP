#include<stdio.h>
#include<conio.h>
void towerofhanoi(int n,char from,char aux,char to)
{
if(n<=0)
return ;
if(n==1)
printf("Move disk 1 from peg %c to peg %c",from,to);
else
{
towerofhanoi(n-1,from,to,aux);
printf("Move disk %d from peg %c to peg %c",n,from,to);
towerofhanoi(n-1,aux,from,to);
}
}

void main()
{
int n;
char A,B,C;
printf("Enter n");
scanf("%d",&n);
towerofhanoi(n,'A','B','C');
getch();
}