#include<bits/stdc++.h>
using namespace std;
int n,m;
set<string> t;

int main()
{
	freopen("test.out","r",stdin);
	cin>>n;
	for(int i = 1;i <= n;i++)
	{
		string s;cin>>s;
		t.insert(s);
//		cout<<"s = "<<s<<endl;
	}
	freopen("guess.out","r",stdin);
	freopen("result.out","w",stdout);
	cin>>m;
	int ans = 0;
	for(int i = 1;i <= m;i++)
	{
		string s;cin>>s;
		std::set<string>::iterator it = t.find(s);
		ans += it != t.end();
//		cout<<"������"<<i<<"�β²� �ɹ���"<<ans<<"��"<<endl;
//		cout<<i<<" "<<ans<<endl; 
		cout<<ans<<endl;
	}
}
