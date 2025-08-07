#include<stdio.h>
struct poly{
int coeff;
int exp;
};
int main(){
 struct poly poly1[10];
 struct poly poly2[10];
struct poly poly3[20];
 int t1;
 int t2;
 int i,j,k;
 printf("enter the number of terms in polynomial 1\n");
 scanf("%d",&t1);
  printf("enter the number of terms in polynomial 2\n");
 scanf("%d",&t2);
 printf("enter the element of polynomial 1\n");
 for(i=1;i<=t1;i++){
 printf("enter the coeffient\n");
 scanf("%d",&poly1[i].coeff);
 printf("enter the exponent\n ");
 scanf("%d",&poly1[i].exp);
 }
 printf("enter the elements of polynomial 2\n");
 for(i=1;i<=t2;i++){
 printf("enter the coeffient\n");
 scanf("%d",&poly2[i].coeff);
 printf("enter the exponent\n");
 scanf("%d",&poly2[i].exp);
 }
 i=1;
 j=1;
 k=1;
 while(i<=t1&&j<=t2){
 if(poly1[i].exp==poly2[j].exp){
 poly3[k].coeff=poly1[i].coeff+poly2[j].coeff;
 poly3[k].exp=poly1[i].exp;
 i++;
 j++;
 k++;
 }
  else if(poly1[i].exp>poly2[j].exp){
 poly3[k].coeff=poly1[i].coeff;
 poly3[k].exp=poly1[i].exp;
 i++;
 k++;
 }
 else if(poly1[i].exp<poly2[j].exp){
 poly3[k].coeff=poly2[j].coeff;
 poly3[k].exp=poly2[j].exp;
 j++;
 k++;
 }}
 while(i<=t1){
 poly3[k].coeff=poly1[i].coeff;
 poly3[k].exp=poly1[i].exp;
 i++;
 k++;
 }
 while(j<=t2){
 poly3[k].coeff=poly2[j].coeff;
 poly3[k].exp=poly2[j].exp;
 j++;
 k++;}
 for(i=1;i<k;i++){
 if(i<k-1)
 printf("%dx^%d+",poly3[i].coeff,poly3[i].exp);
else
printf("%dx^%d",poly3[i].coeff,poly3[i].exp);
}
 return 0;
 }

