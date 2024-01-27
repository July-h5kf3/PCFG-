#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
inline int read()
{
	int s = 0,w = 1;
	char c = getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')w=-1;c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		s=s*10+c-'0';c=getchar();
	}
	return s*w;
}
/*
这是处理密码数据的代码 
*/
int n; 
const int MAX = 1;
const int MOD = 1e9+7;
int main()
{
	freopen("myspace-withcount.txt","r",stdin);
	freopen("myspace.out","w",stdout);
	cin>>n;
//	cout<<n<<endl;
	int t = 0; 
	for(int i = 1;i <= n;i++)
	{
		int num;
		string s;
		cin>>num;
		bool flag = 0;
		getline(cin,s);
		for(int j = 1;j < s.size();j++)
		{
		if(s[j] == ' ' || (int)s[j] > 127)flag = 1;
		if(s[j] >= 'A' && s[j] <= 'Z')s[j] = s[j] - 'A' + 'a';
		}
		if(flag == 1)continue;
		t += num;
		for(int j = 1;j <= num;j++)cout<<s<<endl;
	}
	cout<<t<<endl;
	return 0;
}

