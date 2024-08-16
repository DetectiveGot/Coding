#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define tpi tuple<int,int,int>
#define siz(x) (int)(x.size())
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+1;
int lvl[N];
ll a[N], mn[N], qs[N];
bool vis[N];
vector<int> g[N], mem[N];
queue<int> q;
vector<pii> vec;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m,s,qq,u,v; cin >> n >> m >> s >> qq;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=0;i<m;i++){
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int mx=0;
	q.push(s); vis[s]=1;
	while(!q.empty()){
		u = q.front();
		q.pop();
		mx=max(mx, lvl[u]);
		for(auto &e:g[u]){
			if(vis[e]) continue;
			lvl[e]=lvl[u]+1;
			mem[lvl[e]].push_back(e);
			vis[e]=1;
			q.push(e);
		}
	}
	for(int i=0;i<=mx;i++) mn[i]=1e18;
	ll sum=0;
	priority_queue<ll> pq;
	for(int i=mx;i>=1;--i){
		for(auto &e:mem[i]) pq.push(a[e]);
		if(!pq.empty()){
			sum+=pq.top();
			mn[i]=min(mn[i], pq.top());
			pq.pop();
		}
	}
	vector<int> vec;
	for(int i=1;i<=mx;i++) mn[i]=min(mn[i], mn[i-1]);
	for(int i=1;i<=n;i++) vec.push_back(mn[lvl[i]+1]);
	vec.push_back(0);
	sort(vec.begin(), vec.end());
	for(int i=1;i<=n;i++) qs[i]=qs[i-1]+vec[i];
	ll cmd,x,y;
	while(qq--){
		cin >> cmd;
		ll ans=sum;
		if(cmd==1){
			cin >> x >> y;
			if(lvl[x]+1>mx) ans+=y;
			else {
				if(mn[lvl[x]+1]<y){
					ans-=mn[lvl[x]+1];
					ans+=y;
				}
			}
		} else {
			cin >> y;
			int it = lower_bound(vec.begin()+1, vec.end(), y)-vec.begin()-1;
			ans = sum*n+it*y-qs[it];
		}
		cout << ans << "\n";
	}

	return 0;
}
/*
8 7 1 10
300 100 50 90 150 200 600 300
1 2
2 3
3 4
4 5
5 6
6 7
7 8
1 5 60
1 1 10000
1 2 10000
1 3 10000
1 4 10000
1 5 10000
1 6 10000
1 7 10000
1 8 10000
2 10000
*/