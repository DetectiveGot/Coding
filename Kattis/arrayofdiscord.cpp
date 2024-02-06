#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	vector<string> v(n);
	for(auto &e:v) cin >> e;
	bool ok=false;
	for(int i=1;i<n;i++){
		if(v[i].size()==v[i-1].size()){
			if(v[i].size()==1 && v[i-1][0]=='0' && v[i][0]=='9') continue;
			if(v[i][0]-'0'+1<=9) v[i-1][0]=v[i][0]+1, ok=true;
			else if(v[i].size()>1 && v[i-1][0]-'0'-1>0) v[i][0]=v[i-1][0]-1, ok=true;
			else if(v[i].size()==1 && v[i-1][0]-'0'-1>=0) v[i][0]=v[i-1][0]-1, ok=true;
			if(ok) break;
		}
		if(ok) break;
	}
	if(!ok) cout << "impossible";
	else for(auto &e:v) cout << e << " ";

	return 0;
}

