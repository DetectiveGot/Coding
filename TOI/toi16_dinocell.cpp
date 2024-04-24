#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e6+1;
int qs[N];
bool p[N];
vector<int> v,pos,g;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int z,k,n; cin >> z >> k >> n;
	int x;
	for(int i=0;i<n;i++){
		cin >> x;
		pos.push_back(x);
	}
	for(int i=2;i*i<=k;i++){
		if(p[i]) continue;
		for(int j=i*i;j<=k;j+=i) p[j]=1;
	}
	if(k>=2) v.push_back(2);
	for(int i=3;i<=k;i+=2) if(!p[i]) v.push_back(i);
	for(auto &e:v){
		if(e*e>k) break;
		if(k%e==0){
			g.push_back(e);
			while(k%e==0) k/=e;
		}
	}
	if(k>1) g.push_back(k);
	
	int l=0,r=0, sz = g.size();
	int qs=0, mn=0, mx=0, ans=0;
	for(int i=1;i<n;i++){
		l=pos[i-1]-1, r=pos[i];
		int cnt=0;
		for(int mask=1;mask<1<<sz;mask++){
			int c=0, tl = l, tr = r;
			for(int j=0;j<sz;j++){
				if(mask&1<<j){
					++c;
					tl/=g[j], tr/=g[j];
				}
			}
			if(c&1) cnt+=tr-tl;
			else cnt-=tr-tl;
		}
		if(pos[i-1]==1) --cnt;
		qs+=cnt-(r-l-cnt);
		ans=max({ans, abs(qs-mx), abs(qs-mn)});
		mx=max(mx, qs);
		mn=min(mn, qs);
	}
	cout << ans;

	return 0;
}
