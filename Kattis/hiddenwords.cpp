#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 11, dx[]= {1,0,-1,0},dy[]= {0,-1,0,1}, p = 41, mod = 1e9+7;
char a[N][N];
int ch[26];
unordered_map<string, bool> hsh;
vector<pii> pos[26];
bool vis[N][N], found = false;
string s;
int sz,n,m;

inline void dfs(int i, int x, int y) {
	if(found) return;
	if(i==sz-1) {
		found = true;
		return;
	}
	for(int d=0; d<4; d++) {
		int vx=x+dx[d], vy=y+dy[d];
		if(vx<1 || vy<1 || vx>n || vy>m || vis[vx][vy]) continue;
		if(s[i+1]==a[vx][vy]) {
			vis[vx][vy]=1;
			dfs(i+1, vx, vy);
			vis[vx][vy]=0;
		}
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	cin >> n >>  m;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin >> a[i][j];
			ch[a[i][j]-'A']++;
			pos[a[i][j]-'A'].push_back({i,j});
		}
	}
	int q,ans=0;
	cin >> q;
	while(q--) {
		cin >> s;
		sz=s.size();
		found = false;
		if(!hsh.count(s)) {
			vector<int> cc(26);
			for(auto &e:s) cc[e-'A']++;
			bool bk=true;
			for(auto &e:s)
				if(cc[e-'A']>ch[e-'A']) {
					hsh[s]=false;
					bk=false;
					break;
				}
			if(!bk) continue;
			for(auto &e:pos[s[0]-'A']) {
				vis[e.first][e.second]=1;
				dfs(0, e.first, e.second);
				vis[e.first][e.second]=0;
				if(found) {
					++ans;
					break;
				}
			}
			hsh[s]=found;
		} else ans+=hsh[s];
	}
	cout << ans;

	return 0;
}
