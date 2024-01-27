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
const int MAX = 1e6;
const int MOD = 1e9+7;
//²úÉú×îÖÕ²Â²â 
int n,m;
struct PCFG_rule
{
	string s;
	double pos;
}L[55][MAX];
int js[55];
void input_Lrule()
{
	freopen("PCFGrule_L.out","r",stdin);
	cin>>m;
	for(int i = 1;i <= m;i++)
	{
		string s1;int tot;double pos;
		cin>>s1>>tot>>pos;
		int num = 0;
		for(int j = 1;j < s1.size();j++)num = num * 10 + s1[j] - '0';
		js[num] = tot;
		for(int j = 1;j <= tot;j++)
		{
			string s2;cin>>s2;
			L[num][j].pos = pos;
			L[num][j].s = s2;
		}
	}
}
int guess_num;
int cnt;
void dfs(string nows,string pre_terminal,string base,int max_pivot,int now_pivot,int bnow_place,int pnow_place)
{
	if(cnt >= guess_num)return;
	if(now_pivot == max_pivot)
	{
		cnt++;
		cout<<nows<<endl;
		return;
	}
	int flag = base[bnow_place] == 'L';
	int num = 0;
	int jl = 0;
	string xxx = nows;
	int cd = flag;
	for(int i = bnow_place + 1;i <= base.size();i++)
	{
		if(base[i] >= 'A' && base[i] <= 'Z' || i == base.size())
		{
			if(flag  == 0)
			{
				string linshi;
				for(int j = pnow_place;j < pnow_place + num;j++)linshi += pre_terminal[j];
				nows += linshi;
			}
			jl = i;
			break;
		}
		else
		{
			num = num * 10 + base[i] - '0';
			cd++;
		}
	}
//	cout<<"num = "<<num<<" cd = "<<cd<<endl;
	if(flag == 0)dfs(nows,pre_terminal,base,max_pivot,now_pivot + 1,jl,pnow_place + num),nows = xxx;
	else
	{
		for(int i = 1;i <= js[num];i++)
		{
			nows += L[num][i].s;
			dfs(nows,pre_terminal,base,max_pivot,now_pivot + 1,jl,pnow_place + cd);
			nows = xxx;
		}
	}
}
int main()
{
	cin>>guess_num;
	input_Lrule();
	freopen("preterminal_struct.out","r",stdin);
	freopen("guess.out","w",stdout);
	cin>>n;
	cout<<guess_num<<endl; 
	for(int i = 1;i <= n && cnt < guess_num;i++)
	{
		string s1,s2,s3;
		double pos;int max_pivot;
		cin>>s1>>pos>>s2>>max_pivot;
		dfs(s3,s1,s2,max_pivot,0,0,0);
	}
	return 0;
}
/*
1
2
L1 5 0.2
a
b
c
d
e
L2 10 0.1
ab
ac
ad
ae
af
bb
ba
bc
bd
be
1
6L123L2 1 D1L1D2L2
4
*/
