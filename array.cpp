#include<iostream>

using namespace std;

int main(){
int i,arr[50],j,n;

cout<<"Enter the size of array:";
cin>>n;

cout<<"Enter any elements of array";
for(i=0; i<n; i++)
{
    cin>>arr[i];
}

cout<<"Duplicate elements of an array"<<endl;

 for(i=0; i<n; i++)
 {
     for(j=i+1; j<n; j++)
     {
         if(arr[i]==arr[j]);
     }
     cout<<arr[i]<<"  ";
 }

}
