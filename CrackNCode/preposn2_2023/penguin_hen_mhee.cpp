#include<bits/stdc++.h>
#define pii pair<int,int>


using namespace std;

const int N = 1e6+5;
vector<int> g[N];
bool vis[N];
queue<pii> q;

int main(){
	int n,m,l,r; scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		g[i].push_back(i-1);
		g[i-1].push_back(i);
	}
	for(int i=0;i<m;i++){
		scanf("%d%d",&l,&r);
		--l;
		g[l].push_back(r);
		g[r].push_back(l);
	}
	q.push({0,0});
	vis[0]=1;
	while(!q.empty()){
		auto [d, u] = q.front();
		q.pop();
		if(u==n){
			printf("%d", d);
			return 0;
		}
		for(auto e:g[u]){
			if(vis[e]) continue;
			vis[e]=1;
			q.push({d+1, e});
		}
	}

	return 0;
}
