// ʱ�䣺2022.1.8 21��06��
// ��Դ��AcWing ��33�������ڶ��� 


//һ�������ǺϷ����У��ȼ��ڣ�
//1�����������������(���cnt=0)
//2������ǰ׺�У�����������>=����������(cnt>=0)

//cnt=0
//����������:cnt++
//����������:cnt--

//̰��˼·��
//������������ѡ��ѡ��cnt>0,�����ű�ѡ��
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N=1000010;
char str[N];
int main()
{  scanf("%s", str);

    int l = 0, r = 0;
    for (int i = 0; str[i]; i ++ )
        if (str[i] == '(') l ++ ;
        else if (l > 0)
        {
            l -- ;
            r ++ ;
        }

    printf("%d\n", r * 2);
    return 0;
}







