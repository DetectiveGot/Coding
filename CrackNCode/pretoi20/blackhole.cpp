#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>

const int N = 2e3+1;
const int M = 7e2+1;
const int K = 7e2+1;
int sz[M][N], d1[K][N], d2[K][N],cc[M][N];
std::queue<int> q;

int main() {
	int n,m,k,ed,u,v,id,cnt; scanf("%d%d%d", &n,&m,&k);
	for(int i=1; i<=m; i++) {
		scanf("%d", &ed);
		std::vector<std::vector<int>> g(n+1);
		for(int j=0; j<ed; j++) {
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		id=n;
		for(int j=1; j<=n; j++) {
			if(cc[i][j]) continue;
			++id;
			cnt=0;
			q.push(j); cc[i][j]=id;
			while(!q.empty()) {
				u = q.front();
				q.pop();
				++cnt;
				for(auto &e:g[u]) {
					if(cc[i][e]) continue;
					cc[i][e]=id;
					q.push(e);
				}
			}
			sz[i][id]=cnt;
		}
	}
	memset(d1, -0x3f, sizeof(d1));
	memset(d2, -0x3f, sizeof(d2));
	for(int i=1; i<=n; i++) if(cc[1][i]==n+1) d1[0][i]=sz[1][n+1];
	int ans=sz[1][n+1], gp_next, no_next, gp_nw, no_nw;
	for(int j=1; j<m; j++) {
		int mn = std::min(k-1, j);
		for(int i=mn; i>=0; --i) {
			for(int t=1; t<=n; t++) {
				gp_next = cc[j+1][t], no_next = t, gp_nw = cc[j][t], no_nw = t;
				d2[i+1][gp_next]=std::max(d2[i+1][gp_next], std::max(d1[i][no_nw], d1[i][gp_nw])+sz[j+1][gp_next]);
				d2[i][no_next]=std::max({d2[i][no_next], d1[i][gp_nw], d1[i][no_nw]});
			}
		}
		for(int i=0; i<=mn+1; i++) {
			for(int t=1; t<=n; t++) {
				ans=std::max({ans, d2[i][t], d2[i][t+n]});
				d1[i][t]=d2[i][t];
				d1[i][t+n]=d2[i][t+n];
				d2[i][t]=d2[i][t+n]=-1e9;
			}
		}
	}
	printf("%d", ans);

	return 0;
}