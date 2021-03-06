//  时间：2022.05.30  22点43分
// 这个题l1中傻x，测试点3的数据123 123 kjaksdj应该输出123 + ? = ?
//就是这个点害得我一直过不了 
#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;
//注意：我们把输入中出现的第1个空格认为是A和B的分隔。题目保证至少存在一个空格，并且B不是一个空字符串
//这句话是个大坑，a有可能是空串

string a,b;
bool check(string str)
{
    for(int i=0;i<str.size();i++)
    {
        //有时候可能是超出范围的数字、负数、带小数点的实数、甚至是一堆乱码。
        if(str[i]=='-' || str[i]=='.'|| str[i]-'0'<0 || str[i]-'0'>9)//检查负数乱码和带小数点的情况
            return false;
     } 
    //检查数字的范围是否在1~1000
    int ret;//字符串转换后的数字大小
    stringstream ss;
    ss<<str;
    ss>>ret;
    if(ret<1 || ret >1000)
        return false;
    
    return true;
}
int main ()
{
    string str;//一定要字符串按行读入
    getline(cin,str);
    int ans=str.find(" ");//找到第一个空格的位置即是a,b的分界线
    a=str.substr(0,ans);
    b=str.substr(ans+1,str.size()-ans+1);
   
    bool bool_a=check(a);//判断a和b的合法性
    bool bool_b=check(b);
    
    if(bool_a&&bool_b)//两个都是合法的情况
    {
        int aa,bb;//aa、bb是数字形式
        stringstream ss,tt;
        ss << a;
        ss >> aa;
        tt<<b;
        tt>>bb;
        cout<<a<<" + "<<b<<" = "<<aa+bb<<endl;
    }
    if(!bool_a&&bool_b)//b字符串合法
    {
        int bb;
        stringstream ss;
        ss<<b;
        ss>>bb;
        printf("? + %d = ?\n",bb);
    }
    if(bool_a&&!bool_b)//a字符串合法
    {
        int aa;
        stringstream ss;
        ss<<a;
        ss>>aa;
        printf("%d + ? = ?\n",aa);
    }
    if(!bool_a&&!bool_b)//两个都不合法
    {
        printf("? + ? = ?\n");
    }
    return 0;
}