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
const int MOD = 1e9+7;
/*
密码的重新分组 
*/
int n;
vector<string>input,train,test;
double eps;
int main()
{
	freopen("myspace.out","r",stdin);
	srand(std::time(0));
	n = read();
	eps = 0.5;
	cout<<n<<endl;
	for(int i = 1;i <= n;i++)
	{
		string s;cin>>s;
		input.push_back(s);
	}
	 
	int g1_num = eps * n;
	vector<int>randomIndices(input.size());
	for(int i = 0;i < input.size();i++)randomIndices[i] = i;
	for (int i = input.size() - 1; i > 0; --i)
	{
        int j = rand() % (i + 1);
        swap(randomIndices[i], randomIndices[j]);
    }
//	cout<<"train:"<<endl;
	freopen("train.out","w",stdout);
	cout<<g1_num<<endl;
	for(int i = 1;i <= g1_num;i++)
		cout<<input[randomIndices[i]]<<endl;
//		cout<<"test:"<<endl;
	freopen("test.out","w",stdout);
	cout<<n  - g1_num<<endl;
	for(int i = g1_num + 1;i <= n;i++)
		cout<<input[randomIndices[i]]<<endl;
}

