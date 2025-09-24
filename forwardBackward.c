#include<stdio.h>
#include<stdlib.h>
struct node{
char url[100];
struct node* next;
struct node* prev;
}node;
struct node* current=NULL;

void visitNewPage(){
struct node* temp=( struct node*)malloc(sizeof(node));
printf("enter the url\n");
scanf("%s",temp->url);
temp->prev=current;
temp->next=NULL;
if(current!=NULL){
current->next=temp;}
current=temp;

printf("visited %s\n\n",current->url);
}


void goBack(){
if(current==NULL || current->prev==NULL)
printf("cannot go back\n\n");
else
{
current=current->prev;
printf("move back to %s\n\n",current->url);
}
}

void goForward(){
if(current==NULL ||current->next==NULL)
printf("cannot move forward\n\n");
else
{
current=current->next;
printf("moved forward to %s\n\n",current->url);
}}

void displayCurrentPage(){
if(current==NULL)
printf("nothing to display\n\n");
else
printf("the current url is %s\n\n",current->url);

}


int main(){
int n,i,m;
printf("how many times do you wish to choose \n");
scanf("%d",&n);
for(i=0;i<n;i++){
printf("enter 1:visit new page\n");
printf("enter 2 :go back\n");
printf("enter 3:go forward\n");
printf("4:current page\n");
printf("5:exit\n");
scanf("%d",&m);
switch(m){
case 1:
visitNewPage();
break;
case 2:
goBack();
break;
case 3:
goForward();
break;
case 4:
displayCurrentPage();
break;
case 5:
printf("Exiting Browser Simulation\n");
return 0;
default:
printf("invalid entry\n");
}
}
return 0;
}
