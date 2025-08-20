#include<stdio.h>
int main(){
int row,col;
int i,j;
int sum;
printf("enter your row size");
scanf("%d",&row);
printf("enter your column size");
scanf("%d",&col);
int a[row][col];
int b[row][col];
int c[row][col];
int count=0;
int s[100][3];
int s_transpose[3][100];
printf("enter your first array elements\n");
for(i=0;i<row;i++){
for(j=0;j<col;j++)
{
scanf("%d",&a[i][j]);
}}
printf("enter your second array elements\n");
for(i=0;i<row;i++){
for(j=0;j<col;j++)
{
scanf("%d",&b[i][j]);
}}
for(i=0;i<row;i++){
for(j=0;j<col;j++){
sum=a[i][j]+b[i][j];
c[i][j]=sum;
}}
s[0][0]=i;
s[0][1]=j;
for(i=0;i<row;i++){
for(j=0;j<col;j++){
if(c[i][j]!=0){
count++;
s[count][0]=i;
s[count][1]=j;
s[count][2]=c[i][j];
}}}
s[0][2]=count;
for(i=0;i<3;i++){
for(j=0;j<=count;j++){
s_transpose[i][j]=s[j][i];
}}
printf("SPARSE MATRIX 1\n");
for(i=0;i<row;i++){
for(j=0;j<col;j++){
printf("%d\t",a[i][j]);
}
printf("\n");
}
printf("SPARSE MATRIX 2\n");
for(i=0;i<row;i++){
for(j=0;j<col;j++){
printf("%d\t",b[i][j]);
}
printf("\n");
}
printf("SUM OF MATRIX\n");
for(i=0;i<row;i++){
for(j=0;j<col;j++){
printf("%d\t",c[i][j]);
}
printf("\n");
}
printf("representation matrix\n");
for(i=0;i<=count;i++){
for(j=0;j<3;j++){
printf("%d\t",s[i][j]);
}
printf("\n");
}
printf("TRANSPOSE MATRIX");
printf("SPARSE MATRIX 1\n");
for(i=0;i<3;i++){
for(j=0;j<=count;j++){
printf("%d\t",s_transpose[i][j]);
}
printf("\n");
}
return 0;
}
