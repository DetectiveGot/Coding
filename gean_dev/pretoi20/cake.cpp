#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define tpi tuple<int,int,int>
#define siz(x) (int)(x.size())
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+1;
int a[N], pa[N];
unordered_set<int> lst[N];
vector<pii> ask;

inline int fp(int x){
	if(pa[x]==x) return x;
	return pa[x]=fp(pa[x]);
}

inline void mrg(int u, int v){
	u = fp(u), v = fp(v);
	if(u==v) return;
	if(siz(lst[u])<siz(lst[v])) swap(u, v);
	pa[v]=u;
	for(auto &e:lst[v]) lst[u].insert(e);
	unordered_set<int>().swap(lst[v]);
}
vector<int> cut;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,q,cmd,x; cin >> n >> q;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		lst[i].insert(a[i]);
		pa[i]=i;
	}
	for(int i=0;i<q;i++){
		cin >> cmd >> x;
		ask.push_back({cmd, x});
		if(cmd==1) cut.push_back(x);
	}
	cut.push_back(0);
	cut.push_back(n);
	sort(cut.begin(), cut.end());
	cut.resize(unique(cut.begin(), cut.end())-cut.begin());
	int sz = siz(cut);
	for(int i=1;i<sz;i++){
		int l = cut[i-1]+1, r = cut[i];
		for(int i=l;i<=r;i++) mrg(l, i);
	}
	reverse(ask.begin(), ask.end());
	vector<int> ans;
	for(auto &[cc, p]:ask){
		if(cc==1) mrg(p, p+1);
		else {
			p = fp(p);
			ans.push_back(siz(lst[p]));
		}
	}
	reverse(ans.begin(), ans.end());
	for(auto &e:ans) cout << e << "\n";

	return 0;
}
