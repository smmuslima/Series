//Serires : 1+(1+2)+(1+2+3)+.....+(1+2+3+4+....+n)

#include<stdio.h>
#include<conio.h>

int main(){
int i, n;
int termSum, termTotal=0;

printf("Enter the value of n\n");


scanf("%d",&n);

for(i=1; i<=n; i++)
{
    termSum=((i*(i+1))/2); //Formula for determine sum of the serires প্রতিটা আলাদা  পার্ট এর জোগফল
    termTotal+=termSum;//সবগুলি  পার্ট এর জোগফল
}

printf("Total sum of the sereis is=\n%d",termTotal);
}
