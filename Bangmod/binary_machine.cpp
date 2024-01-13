//WRONG ANS
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
		v.push_back(s%2);
		if(s>=2) ct=1;
	}
	for(;i<n;i++){
		int add = a[i]-'0'+ct;
		ct=0;
		v.push_back(add%2);
		if(add>=2) ct=1;
	}
	for(;i<m;i++){
		int add = b[i]-'0'+ct;
		ct=0;
		v.push_back(add%2);
		if(add>=2) ct=1;
	}
	if(ct) v.push_back(1);
//	for(auto &e:v) if(e==1) ++cnt;
//	if(cnt&1)
//	for(auto &e:v) cout << e;
//	cout << endl;
	if(v[0]==0){
		v[0]=1;
		if(v.size()>1) v[1]--;
		for(int i=1;i<v.size();i++){
			if(v[i]<0) v[i]=1;
			else break;
			if(i+1<v.size()) v[i+1]--;
		}
	} else v[0]--;
	while(v[v.size()-1]==0) v.pop_back();
	reverse(v.begin(), v.end());
	if(v.empty()) cout << 0;
	else for(auto &e:v) cout << e;
	
	return 0;
}
