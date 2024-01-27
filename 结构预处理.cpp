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
将训练集的密码转化为SLD结构，并统计每个结构出现的概率； 
*/
const int MAX = 8e6 + 10;
const int MOD = 1e9+7;
string s;
string s1[MAX];
map<string,int>p;
int n;
int tot;
double pos[MAX];
string trans(string a)
{
	string sss;
	int type;
	int len = 1;
	if((a[0] >= 'a' && a[0] <= 'z') || (a[0] >= 'A' && a[0] <= 'Z'))type = 1,sss += 'L';
	else if(a[0] >= '0' && a[0] <= '9')type = 2,sss += 'D';
	else type = 3,sss += 'S';
	for(int i = 1;i < a.size();i++)
	{
		if((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z'))
		{
			if(type != 1)
			{
				string lin;
				while(len)
				{
//					cout<<len<<endl;
					lin += (char)(len % 10 + '0');
					len = len / 10; 
				}
				for(int j = lin.size() - 1;j >= 0;j--)sss += lin[j];
				sss += 'L';
				len = 1;
				type = 1;
			}
			else len++;
		}
		else if(a[i] >= '0' && a[i] <= '9')
		{
			if(type != 2)
			{
				string lin;
				while(len)
				{
					lin += (char)(len % 10 + '0');
					len = len / 10; 
				}
				for(int j = lin.size() - 1;j >= 0;j--)sss += lin[j];
				sss += 'D';
				len = 1;
				type = 2;
			}
			else len++;
		}
		else
		{
			if(type != 3)
			{
				string lin;
				while(len)
				{
					lin += (char)(len % 10 + '0');
					len = len / 10; 
				}
				for(int j = lin.size() - 1;j >= 0;j--)sss += lin[j];
				sss += 'S';
				len = 1;
				type = 3;
			}
			else len++;
		}
	}
		string lin;
		while(len)
	{
		lin += (char)(len % 10 + '0');
		len = len / 10;
	}
	for(int j = lin.size() - 1;j >= 0;j--)sss += lin[j];
	p[sss]++;
	return sss;
}
struct node
{
	string s;
	double pos;
}output[MAX];
bool cmp(node &a,node &b)
{
	return a.pos > b.pos;
}
int main()
{
	freopen("train.out","r",stdin);
	freopen("structure.out","w",stdout); 
	cin>>n;
	for(int i = 1;i <= n;i++)
	{
		cin>>s;
		string s2 = trans(s);
//		cout<<s<<" "<<s2<<endl;
		if(p[s2] == 1)s1[++tot] = s2;
	}
	cout<<tot<<endl;
	for(int i = 1;i <= tot;i++)
	{
		pos[i] = 1.0 * p[s1[i]] / n;
		output[i].pos = pos[i];
		output[i].s = s1[i];
	}
	sort(output + 1,output + tot + 1,cmp);
	for(int i = 1;i <= tot;i++)cout<<output[i].s<<" "<<output[i].pos<<endl;
	return 0;
}

