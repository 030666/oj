// ʱ�䣺2021.12.26 20��56��
// ��Դ��AcWing 31������ 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int a,b,p1,p2,p3,p4;
    cin>>p1>>p2>>p3>>p4>>a>>b;
    //��һ���ҳ�p1~4�е���Сֵ
    vector<int>p;
    p.push_back(p1);
    p.push_back(p2);
    p.push_back(p3);
    p.push_back(p4);
    sort(p.begin(),p.end());
    if(a>p[0])//�Ƚ���һ�����У�a��b��û�б�p����Сֵ��С��
        cout<<0<<endl;
    else
        cout<<min(b,p[0]-1)-a+1<<endl;
    return 0;
}
