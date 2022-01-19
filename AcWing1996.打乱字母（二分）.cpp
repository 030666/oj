// ʱ�䣺2022.1.12 19��54�� 
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=50010;
int n;
string a[N],b[N],c[N];//a��ԭ�ַ�����b�ǽ�ÿ����ȡ�����ֵ����֮��Ľ����c����Сֵ����Ľ��

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=c[i]=a[i];
        sort(b[i].begin(),b[i].end(),greater<char>());//�Ӵ�С����
        sort(c[i].begin(),c[i].end());
    }
    
    sort(b+1,b+n+1);
    sort(c+1,c+n+1);
    
    for(int i=1;i<=n;i++)
    {
        sort(a[i].begin(),a[i].end());
        int l=1,r=n;
        while(l<r)
        {
            int mid=l+r>>1;
            if(b[mid]>=a[i]) r=mid;
            else l=mid+1;
        }
        cout<<r<<" ";
        reverse(a[i].begin(),a[i].end());
        l=1,r=n;
        while(l<r)
        {
            int mid=l+r+1>>1;
            if(c[mid]<=a[i]) l=mid;
            else r=mid-1;
        }
        cout<<r<<endl;
    }
    
    return 0;
}
