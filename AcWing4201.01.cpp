// ʱ�䣺2021.12.26 23��15��
// ��Դ��AcWing31������

#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int res=0;
	for(int i=1;i<1<<10;i++)//�����ݷ�Χת���ɶ����ƣ�Ȼ��ö�� 
	{
		int x=0;
		for(int j=0;j<10;j++)//�������Ƶ���ת��Ϊʮ���� 
			x=x*10+(i>>j&1);
		if(x<=n) res++;
	}
	cout<<res<<endl;
	return 0;
}
