#include<stdio.h>
#include<conio.h>
#include<alloc.h>
/*structure containing a data part and a link part*/
struct node
{int info;
struct node *link;
};
struct node* create_list(void);
void split_list_into_2(struct node **q);
void concatenate_2_list(void);
void duplicate_list(struct node **q);
void add_at_beg(struct node **q);
void add_at_end(struct node **q);
void display(struct node **q);
 
void main()
{int k;
struct node *p;
p=NULL;
clrscr();
z:printf("/n program for performing some operations on linked list\n\nenter 1->to create a linear linked list\nenter 2-> to split a linear linked list into two\nenter 3-> to concatenate 2 linear linked list\n enter 4->to create a duplicate of list/n enter 5->to exit\n");
scanf("%d",&k);
switch(k)
{case 1:p=create_list();
goto z;
case 2:split_list_into_2(&p);
goto z;
case 3:concatenate_2_list();
goto z;
case 4:duplicate_list(&p);
goto z;
case 5:return;
}
getch();
}
struct node* create_list(void)
{ int no,i;
struct node *p;
p=NULL;    //empty linked list
printf("enter no of nodes wanted in list\n");
scanf("%d",&no);
for(i=0;i<no;i++)
add_at_end(&p);
printf("linked list created and its elements are\n");
display(&p);
return(p);
}
void split_list_into_2(struct node **q)
{struct node *first,*second=NULL,*temp,*old;
int loc,i;
first=*q;
temp= first;
old=temp;
printf("enter location after which you want to split list");
scanf("%d",&loc);
for(i=0;i<loc,i++)
{old=temp;
temp=temp->link;
}
if(temp==NULL)
{printf("location is more than nodes in list\n");
getch();
return;}
second=temp;
old->link=NULL;
printf("elements of first list are\n");
display(&first);
printf("elements of second list are\n");
display(&second);
getch();
return;
}
void concatenate_2_list(void)
{struct node *temp,*first,*second;
temp=NULL;
printf("create first list\n");
first=create_list();'
printf("create second list\n");
second=create_list();
temp=first;
while(temp->link!=NULL)
temp=temp->link;
temp->link=second;
printf("two lists concatenated with elements\n");
display(&first);
getch();
}
void duplicate_list(struct node **q)
{struct node *duplicate;
duplicate=*q;
printf("duplicate list created with elements\t");
display(&duplicate);
getch();
}
/*add a node at beginning of list*/
void add_at_beg(struct node **q)
{int num;
struct node *temp;
/*memory allocation for node*/
temp=(struct node*)malloc(sizeof(struct node));
printf("enter data part of node\n");
scanf("%d",&num);
temp->info=num;
temp->link=*q;
*q=temp;
}
/*add a node at the end*/
void add_at_end(struct node *q)
{int num;
struct node *temp,*a;
temp=*q;
printf("enter data part of node \n");
scanf("%d",&num);
if(*q==NULL)//no node present
{temp=(struct node *)malloc(sizeof(struct node));
temp->info=num;
temp->link=NULL;
*q=temp;
}
else
{temp=*q;
while(temp->link!=NULL)
temp=temp->link;
//add node at the end
a=(struct node*)malloc(sizeof(struct node));
a->info=num;
a->link=NULL:
temp->link=NULL;
temp->link=a;
}}
//display all nodes
void display(struct node **q)
{struct node *s;
s=*q;
printf("\n");
//traverse entire linked list
while(s!=NULL)
{printf("%d\t",s->info);
s=s->link;
}
if(s==*q)
printf("linked list empty");
getch();
return;
}