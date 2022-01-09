// ʱ�䣺2022.1.9 15��10�� 

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=10;

int n;
char g[N][N];
bool st[N][N];
int ans;//���Ĵ�

int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
void dfs(int x,int y,int l,int r)
{
    st[x][y]=true;//���һ�±��ѹ���
    if(l==r)//��������������ȵ�ʱ�����ҵ�һ���Ӵ�
     {
         ans=max(ans,l+r);
         st[x][y]=false;//�ָ��ֳ�
         return ;
     }
     
     for(int i=0;i<4;i++)//ÿ����������ĸ���λ����
     {
         int a=x+dx[i],b=y+dy[i];
         if(a>=0&&a<n&&b>=0&&b<n&&!st[a][b])//a,b��û�г��粢��û�б��ѹ�
        {
            if(g[x][y]==')'&&g[a][b]=='(')//ֻ����������ǲ��Ϸ���
                continue;
            if(g[a][b]=='(') dfs(a,b,l+1,r);
            else dfs(a,b,l,r+1);
                
        }
     }
     st[x][y]=false;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>g[i];
    
    if(g[0][0]=='(')//�ų���һ������������
        dfs(0,0,1,0);//�����Ͻǿ�ʼ��������ʱ������һ�������������
    cout<<ans<<endl;
    return 0;
}
