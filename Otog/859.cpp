#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+1;
int pa[N];

int fp(int x){
	if(pa[x]==x) return x;
	return pa[x]=fp(pa[x]);
}
struct DATA{
	int u,v,w;
	bool operator < (const DATA &dt) const{
		return w>dt.w;
	}
};
vector<DATA> g;
priority_queue<int, vector<int>, greater<int>> pq;
set<int> s;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m,k,u,v,w; cin >> n >> m >> k;
	iota(pa+1, pa+n+1, 1);
	for(int i=0;i<m;i++){
		cin >> u >> v >> w;
		g.push_back({u,v,w});
	}
	sort(g.begin(), g.end());
	for(auto &e:g){
		u=fp(e.u), v=fp(e.v);
		if(u==v) continue;
		pa[v]=u;
		pq.push(e.w);
	}
	for(int i=1;i<=n;i++) s.insert(fp(i));
	k-=s.size();
	while(!pq.empty() && k--) pq.pop();
	if(pq.empty()) cout << 0;
	else cout << pq.top();
	
	return 0;
}
/*
12
15
8
1 3 25
3 2 12
1 2 40
4 5 26
7 4 18
7 6 32
4 6 31
8 9 20
9 10 17
9 12 29
8 11 42
10 11 56
10 8 31
12 10 11
11 12 45
*/
