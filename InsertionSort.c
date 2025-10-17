#include<stdio.h>
int main(){
int n,j,i;
int temp;
printf("enter the array size");
scanf("%d",&n);
int a[n];
printf("enter the array elements");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
for(i=1;i<n;i++){
temp=a[i];
j=i-1;
while(a[j]>temp && j>=0){
a[j+1]=a[j];
j--;
}
a[j+1]=temp;
}
for(i=0;i<n;i++){
printf("%d ",a[i]);
}
return 0;
}
