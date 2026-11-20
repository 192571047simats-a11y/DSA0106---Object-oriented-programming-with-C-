#include <iostream>
int& maxMark(int a[],int n){int best=0;for(int i=1;i<n;++i)if(a[i]>a[best])best=i;return a[best];}
int main(){int marks[]={72,91,85,88};maxMark(marks,4)+=2;for(int x:marks)std::cout<<x<<' ';std::cout<<'\n';}