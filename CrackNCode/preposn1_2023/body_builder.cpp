#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 21, mxN = (1<<20)+2;
vector<pii> v;
int ans[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m,s,w; cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> s >> w;
		v.emplace_back(s, w);
	}
	sort(v.begin(), v.end());
	for(int i=1;i<1<<n;i++){
		vector<int> p;
		int c=0;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				++c;
				auto it = lower_bound(p.begin(), p.end(), v[j].second);
				if(it==p.end()) p.push_back(v[j].second);
			}
		}
		if(c==p.size()) ans[p.size()]++;
	}
	int t;
	while(m--){
		cin >> t;
		cout << ans[t] << "\n";
	}
	
	return 0;
}