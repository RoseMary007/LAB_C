#include<stdio.h>
void enqueue();
 void dequeue();
int QueueArr[100];
int front=-1;
int rear=-1;
int max_limit;
int main(){
int n,m,i;
printf("enter your max limit\n");
scanf("%d",&max_limit);
QueueArr[max_limit];
printf("how many times you want the functions to work");
scanf("%d",&n);
for(i=0;i<n;i++){
printf("enter 1 for enqueue and 2 for dequeue");
scanf("%d",&m);
if(m==1)
enqueue();
else
dequeue();
}
return 0;
}
void enqueue(){
int item;
if(rear==-1&&front==-1){
rear=0;
front=0;
printf("enter the element you want in the array\n");
scanf("%d",&item);
QueueArr[rear]=item;
printf("%d\n",QueueArr[rear]);
}
else if(front==(rear+1)%max_limit){
printf("overflow\n");}
else{
rear=(rear+1)%max_limit;
printf("enter the element you want in the array\n");
scanf("%d",&item);
QueueArr[rear]=item;
int i=front;
while(1){
    if(i==rear)
    break;
    else
    printf("%d ",QueueArr[i]);
    i=(i+1)%max_limit;
}
printf("%d",QueueArr[i]);
printf("\n");
}
}
 void dequeue(){
int item;
if(rear==-1&& front==-1){
printf("underflow\n");}
else if(front==rear){
printf("unferflow\n");
rear=front=-1;
}
else{
item=QueueArr[front];
printf("deleted element is %d \n",item);
int i=(front+1)%max_limit;
while(1){
    if(i==rear)
    break;
    else
    printf("%d ",QueueArr[i]);
    i=(i+1)%max_limit;
}
printf("%d ",QueueArr[i]);
printf("\n");
front=(front+1)%max_limit;
}}
