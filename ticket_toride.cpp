#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << #x << ": " << x << " "

using namespace std;

const int N = 1e5+2;
struct DATA{
	int u,v,w;
	bool operator < (const DATA &dt) const{
		return w<dt.w;
	}
};
vector<DATA> edges;
int pa[N];

int fp(int &x){
	if(pa[x]==x) return x;
	return pa[x]=fp(pa[x]);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,k,u,v,w,ans=0; cin >> n >> m >> k;
	iota(pa+1, pa+n+1, 1);
	while(m--){
		cin >> u >> v >> w;
		edges.push_back({u,v,w});
	}
	sort(edges.begin(), edges.end());
	n-=k+1;
	int cnt=0;
	for(int i=0;i<edges.size() && cnt<n;i++){
		u=fp(edges[i].u),v=fp(edges[i].v);
		if(u==v) continue;
		pa[v]=u;
		ans+=edges[i].w;
		cnt++;
	}
	cout << ans;
	
	return 0;
}
