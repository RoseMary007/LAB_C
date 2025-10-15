#include<stdio.h>
int main(){
int count=0;
int n;
int key;
int f=0;
printf("enter the number elements ");
scanf("%d",&n);
count++;
int a[n];
printf("enter the array elemets\n");
for(int i=0;i<n;i++){
scanf("%d",&a[i]);
count++;
}
printf("enter the search element");
scanf("%d",&key);
count++;
for(int i=0;i<n;i++){
count++;
if(key==a[i]){
f=1;
count++;
break;
}}

if(f==1)
printf("element is found ");
else
printf("element not found");
count++;
printf("space complexity is %d\n",((5*4)+(n*4)));
printf("time complexity is %d ",count);
return 0;
}
