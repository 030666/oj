// ʱ�䣺2022.1.8 20��08�� 
#include<iostream>
#include<cstring>
#include<algorithm>

#define x first
#define y second

using namespace std;
typedef pair<int,int> PII;
const int N=100010;
int n;
int h[N];//��¼�������ӵĸ߶�
PII q[N];//���Լȴ�߶��ִ��±�

int main ()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&h[i]);
    
    n=unique(h+1,h+n+1)-h-1;
//���� �����ڵ��ظ�Ԫ��ɾ����unique�������ص���ȥ��֮�����һλԪ�ص���һ��λ��
    h[n+1]=0;//����������ܻ��õ���n+1��λ�ã���Ҫ�ѵ�n+1��λ�����
    
    for(int i=1;i<=n;i++) q[i]={h[i],i};
    sort(q+1,q+n+1);//��ȥ��֮������Ӹ߶����� 
    int res=1,cnt=1;//cnt�����ʼʱС������
    
    for(int i=1;i<=n;i++)
    {
        int k=q[i].y;//ȡ������ʱ������ӵ��±� 
        if(h[k-1]<h[k]&&h[k+1]<h[k]) cnt--;//����м�����ӱ����߶���
        else if(h[k-1]>h[k]&&h[k+1]>h[k]) cnt++;//����м�����ӱ����߶�С
        
        if(q[i].x!=q[i+1].x)//��ֹ����������ȸ߶ȵ�����û���ŵ���ûȥ�� 
            res=max(res,cnt);
    }
    printf("%d\n",res);
    return 0;
}
