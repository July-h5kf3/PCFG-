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
字典的导入和概率计算 
*/
const int MAX = 1e7 + 10;
const int MOD = 1e9+7;
int n;
string s[MAX];
int len_word[MAX];
int js[MAX];
int js1[MAX];
map<int,map<int,string> >w; 
int main()
{
	int minn = 0x3f3f3f;
	int maxx = 0;
	freopen("dic-0294.txt","r",stdin);
	freopen("PCFGrule_L.out","w",stdout); 
	n = read();
	int tot = 0;
	for(int i = 1;i <= n;i++)
	{
		cin>>s[i];
		len_word[i] = s[i].size();
		for(int j = 0;j < s[i].size();j++)if(s[i][j] >= 'A' && s[i][j] <= 'Z')s[i][j] = s[i][j] - 'A' + 'a';
		if(js1[len_word[i]] == 0 && len_word[i] != 0)tot++;
		js1[len_word[i]]++;
		w[len_word[i]][++js[len_word[i]]] = s[i];
		maxx = max(maxx,len_word[i]);
		minn = min(minn,len_word[i]);
	}
	cout<<tot<<endl;
	for(int i = 1;i <= maxx;i++)
	{
		if(js[i] == 0)continue;
		cout<<"L"<<i<<" "<<js[i]<<" "<<(double)1.0 / js[i]<<endl;
		for(int j = 1;j <= js[i];j++)
		{
			cout<<w[i][j]<<endl;
		}
	}
	return 0;
}

