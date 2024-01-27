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
const int MAX = 5e5 + 10;
const int MAXX = 1e7 + 10;
const int MOD = 1e9+7;
int n,m,t;
struct node
{
	string a,ys;
	int pivot,max_pivot;
	double pos;
	friend bool operator < (node a,node b)
	{
		if(a.pos == b.pos)return a.pivot < b.pivot;
		else return a.pos < b.pos;
	}
};
struct node1
{
	string pret,ys;
	double pos;
}output[MAXX];
int tot;
priority_queue<node>q;
struct rule
{
	string tihuang;
	double pos;
}R[3][65][MAX];
map<string,double>pp,nn;//看下一个替换的 
int js[3][MAX];//0 -> S,1 -> D,2 -> L
struct nex
{
	string s;
	double pos;
};
map<string,string>mm;
map<string,int>ttype,nnum;
void input_DSrule()
{
	freopen("PCFGrule.out","r",stdin);
	cin>>m;
	for(int i = 1;i <= m;i++)
	{
		string s;cin>>s;
		int type = s[0] == 'D';
		int num = 0; 
		for(int j = 1;j < s.size();j++)
		{
			num = num * 10 + s[j] - '0';
		}
		cin>>js[type][num];
		for(int j = 1;j <= js[type][num];j++)
		{
			cin>>R[type][num][j].tihuang >> R[type][num][j].pos;
			ttype[R[type][num][j].tihuang] = type;
			nnum[R[type][num][j].tihuang] = j;
			pp[R[type][num][j].tihuang] = R[type][num][j].pos;
		}
	}
}
void input_Lrule()
{
	freopen("PCFGrule_L.out","r",stdin);
	cin>>m;
	for(int i = 1;i <= m;i++)
	{
		string s;cin>>s;
		int num = 0;
		for(int j = 1;j < s.size();j++)num = num * 10 + s[j] - '0';
		cin>>js[2][num];
		double pos_L;cin>>pos_L;
		for(int j = 1;j <= js[2][num];j++)cin>>R[2][num][j].tihuang,R[2][num][j].pos = pos_L;
	}
}
void input_basestruct()
{
	freopen("structure.out","r",stdin);
	cin>>n;
	for(int i = 1;i <= n;i++)
	{
		string ss;cin>>ss;
		double pos_1;cin>>pos_1;
		node preterminal_struct;
		preterminal_struct.pivot = 1;
		int max_pp = 0;
		int len = ss.size();
		string pre_terminal;
		int flag;
		bool flagg = 0;
		if(ss[0] == 'L')flag = 2,pre_terminal += 'L';
		else flag = ss[0] == 'D';
		int num = 0;
		for(int j= 1;j <= len;j++)
		{
			if((ss[j] >= 'A' && ss[j] <= 'Z') || j == len)
			{	
					if(num >= 70)
					{
						flagg = 1;
						break;
					}
					max_pp++;
					if(flag != 2)
					{
						pre_terminal += R[flag][num][1].tihuang;	
					}
					pos_1 = pos_1 * R[flag][num][1].pos;
					if(ss[j] == 'L') pre_terminal += ss[j],flag = 2;
					else flag = ss[j] == 'D';
					num = 0;	
			}
			else
			{
				num = num * 10 + ss[j] - '0';
				if(flag == 2) pre_terminal += ss[j];
			}
		}
		if(flagg == 1)continue;
		preterminal_struct.a = pre_terminal;
		preterminal_struct.pos = pos_1;
		preterminal_struct.ys = ss;
		preterminal_struct.max_pivot = max_pp;
//		cout<<pre_terminal<<" "<<pos_1<<" "<<ss<<endl;
		if(preterminal_struct.pos >= 1e-9)q.push(preterminal_struct);
	}
}
int main()
{
	freopen("preterminal_struct.out","w",stdout);
	int test_count;
	cin>>test_count;
	cout<<test_count<<endl; 
	input_DSrule();
	input_Lrule();
	input_basestruct();
	/*
	生成预终端结构 
	*/
//	cout<<"fuck"<<endl;
//	cout<<mm["123456"].pos<<" "<<mm["123456"].s<<endl;
	while(!q.empty())
	{
		node noww = q.top();q.pop();
		int p = noww.pivot;
		string l = noww.a;
		string L = noww.ys;
		int siz = L.size();
		int max_p = noww.max_pivot;
		if (p < 1e-9)break;
		output[++tot].pret = noww.a;
		output[tot].ys = noww.ys;
		output[tot].pos = noww.pos;
		cout<<output[tot].pret<<" "<<output[tot].pos<<" "<<output[tot].ys<<" "<<max_p<<endl;
		if(tot >= test_count)break;
		int tot1 = 0; 
		int n_p = 0;
		int num = 0;
//		cout<<l<<" "<<L<<" "<<max_p<<" "<<p<<endl;
		for(int i = p;i <= max_p;i++)//枚举替换的部分 
		{
			tot1  = 0;
			for(int j = 0;j <= siz;j++)
			{
				if((L[j] >= 'A' && L[j] <= 'Z') || j == siz)tot1++;
				if(tot1 == i)
				{
					n_p = j;
					break;
				}
			}
//			cout<<"n_p = "<<n_p<<endl;
			if(L[n_p] == 'L')continue;
			string i_s = l;
			double poss = noww.pos;
			bool flgg = L[0] == 'L';
			int x = flgg;//替换开始的位置 
			int numm = 0;
			int xxx = 0;//替换长度 
			for(int j = 1;j <= n_p;j++)
			{
				if((L[j] >= 'A' && L[j] <= 'Z') || L[j] == siz)
				{
					if(L[j] == 'L')x++;
					if(flgg == 0)x += numm;
					flgg = L[j] == 'L';
					numm = 0;
				}
				else
				{
					numm = numm * 10 + L[j] - '0';
					if(flgg)x++;	
				}
			}
			numm = 0;
			for(int j = n_p + 1;j <= siz;j++)
			{
				if((L[j] >= 'A' && L[j] <= 'Z') || j == siz)
				{
					xxx += numm;
					break;
				}
				else numm = numm * 10 + L[j] - '0';
			}
//			cout<<"x = "<<x<<" xxx = "<<xxx<<endl; 
			string linshi;
			for(int j = x;j < x + xxx;j++)linshi += l[j];
			poss = poss / pp[linshi];
//			cout<<"linshi  = "<<linshi<<endl;
			if(nnum[linshi] == js[ttype[linshi]][linshi.size()])continue;
//			cout<<noww.ys<<" "<<noww.a<<" "<<linshi<<" 替换为："; 
			linshi = R[ttype[linshi]][linshi.size()][nnum[linshi] + 1].tihuang;
//			cout<<linshi<<endl;
			poss = poss * pp[linshi];
			for(int j = x;j <= x + xxx - 1;j++)i_s[j] = linshi[j - x];
			node insert;
			insert.a = i_s;insert.max_pivot = max_p;
			insert.pivot = i;insert.pos = poss;
			insert.ys = L;
			q.push(insert);
		}
	}
}

