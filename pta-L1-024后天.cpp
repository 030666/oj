// 时间：2022.05.06 21点50分
#include<iostream>
using namespace std;

int main ()
{
    int n;
    cin>>n;
    if(n==5){
        cout<<7<<endl;
        return 0;}
    cout<<(n+2)%7<<endl;
    return 0;
}