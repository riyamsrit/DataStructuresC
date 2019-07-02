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

NODE insend(int item,NODE first)
{
NODE curr;
NODE temp=getnode();
temp->info=item;
temp->link=NULL;
if(first==NULL) return temp;
curr=first;
while(curr->link!=NULL)
{
curr=curr->link;
}
curr->link=temp;
return first;

}

NODE delfirst(NODE first)
{
NODE curr;
if(first==NULL)
{
printf("LIST EMPTY\n");
return first;
}
curr=first;
curr=curr->link;
printf("ITEM DELETED IS %d",first->info);
free(first);
return curr;
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
printf("1.INS END 2.DEL FIRST 3. DISPLAY\n 4.EXIT\n");
scanf("%d",&choice);
switch(choice)
{
case 1: printf("ENTER ITEM \n");
scanf("%d",&item);
first=insend(item,first);
break;

case 2:first= delfirst(first);
break;

case 3: display(first);
break;

case 4: exit(0);
default:printf("INVALID\n");
exit(0);
}
}while(choice<=4);

}
