// ʱ�䣺2022.1.7 14��51��
// �㷨��floodfill�㷨 dfs 

#include<iostream>
#include<cstring>
#include<algorithm>
#include <vector>
#define x first
#define y second
using namespace std;
typedef pair<int,int> PII; 
const int N=55;
int n,m;
char g[N][N];

vector<PII>points[2];

int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};

void dfs(int x,int y,vector<PII>& ps)
{
    g[x][y]='.';//������λ����'X'��ô�Ƚ������Ϊ'.' 
    ps.push_back({x,y});
    for(int i=0;i<4;i++)//�ĸ��������dfs 
    {
        int a=x+dx[i],b=y+dy[i];
        if(a>=0 && a<n && b>=0 && b<m && g[a][b]=='X')
            dfs(a,b,ps);
    }
}

int main()
{
     cin>>n>>m;
     for(int i=0;i<n;i++)  cin>>g[i];

     for(int i=0,k=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(g[i][j]=='X')
                dfs(i,j,points[k++]);//��һ���ҳ���һ���飬�ŵ�points[0] 
    int res=1e8;//�ڶ��ξͷŵ�points[1] 
    for(auto&a:points[0])
        for(auto&b:points[1])
            res=min(res,abs(a.x-b.x)+abs(a.y-b.y)-1);//abs��������Ǿ���ֵ 
    cout<<res<<endl;

    return 0;
}
