#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	string a,b; cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int n=a.size(), m=b.size();
	int i=0;
	vector<int> v;
	int ct=0;
	for(i=0;i<min(n,m);i++){
		int s=a[i]-'0'+b[i]-'0'+ct;
		ct=0;
		v.push_back(s%10);
		if(s>=10) ct=1;
	}
	for(;i<n;i++){
		int add = a[i]-'0'+ct;
		ct=0;
		v.push_back(add%10);
		if(add>=10) ct=1;
	}
	for(;i<m;i++){
		int add = b[i]-'0'+ct;
		ct=0;
		v.push_back(add%10);
		if(add>=10) ct=1;
	}
	if(ct) v.push_back(1);
	reverse(v.begin(), v.end());
	for(auto &e:v) cout << e;
	
	return 0;
}
