#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << #x << ": " << x << " "

using namespace std;

const int N = 1e5+2;
vector<pii> edge;
stack<int> ask,ans;
int pa[N];

int fp(int x){
	if(pa[x]==x) return x;
	return pa[x]=fp(pa[x]);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m; cin >> n >> m;
	iota(pa+1, pa+n+1, 1);
	for(int i=0;i<m;i++){
		int u,v; cin >> u >> v;
		edge.push_back({u,v});
	}
	for(int i=0;i<m;i++){
		int t; cin >> t;
		ask.push(t);
	}
	int cnt=n;
	while(!ask.empty()){
		int u=edge[ask.top()-1].first, v=edge[ask.top()-1].second;
		int pu=fp(u), pv=fp(v);
		ask.pop();
		if(pu==pv) ans.push(cnt);
		else {
			pa[pv]=pu;
			ans.push(cnt--);
		}
	}
	while(!ans.empty()){
		cout << ans.top() << "\n";
		ans.pop();
	}
	
	return 0;
}