#include<stdio.h>
#include<stdlib.h>


struct node
{
int info;
struct node*link;
};
typedef struct node *NODE;

NODE getnode()
{
NODE x;
x=(NODE) malloc(sizeof(struct node));
if(x==NULL)
{
printf("OUT OF MEMORY");
exit(0);
}
return x;
}

NODE insfront(int item,NODE first)
{
NODE temp=getnode();
temp->info=item;
temp->link=first;
return temp;
}

NODE delrear(NODE first)
{
NODE prev,curr;
if(first==NULL)
{
printf("LIST EMPTY\n");
return first;
}
if(first->link==NULL)
{
printf("ITEM DELETED IS %d",first->info);
free(first);
return NULL;
}
printf("\n");
prev=NULL;
curr=first;
while(curr->link!=NULL)
{
prev=curr;
curr=curr->link;
}
printf("Item deleted is %d",curr->info);
free(curr);
prev->link=NULL;
return first;
printf("\n");
}

void display(NODE first)
{
NODE curr;
if(first==NULL)
{
printf("list empty");
return;
}
else
curr=first;
printf("CONTENTS OF LL ARE");
while(curr!=NULL)
{
printf("%d",curr->info);
curr=curr->link;
}
printf("\n");
}

void main()
{

NODE first;
int item,choice;
first=NULL;
do
{
printf("1.INS FRONT 2.DEL END 3. DISPLAY\n 4.EXIT\n");
scanf("%d",&choice);
switch(choice)
{
case 1: printf("ENTER ITEM \n");
scanf("%d",&item);
first=insfront(item,first);
break;

case 2:first= delrear(first);
break;

case 3: display(first);
break;

case 4: exit(0);
default:printf("INVALID\n");
exit(0);
}
}while(choice<=4);

}
