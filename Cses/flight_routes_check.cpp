#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+2;
int pa[N];

int fp(int x){
	if(pa[x]==x) return x;
	return pa[x]=fp(pa[x]);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m; cin >> n >> m;
	for(int i=1;i<=n;i++) pa[i]=i;
	while(m--){
		int u,v; cin >> u >> v;
		if(fp(u)==fp(v)) continue;
		pa[fp(v)]=pa[u];
	}
	set<int> s;
	
	return 0;
}
