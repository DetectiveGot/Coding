#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define siz(x) (int)(x.size())
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int mxN = 4e5+5;
vector<int> u;
vector<pii> g;
ll qs[mxN][4];


int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int m,n,x,l,r; cin >> m >> n;
	for(int i=0;i<m;i++){
		cin >> x >> l >> r, ++l, ++r;
		u.push_back(l);
		u.push_back(r+1);
		g.emplace_back(l, x);
		g.emplace_back(r+1, -x);
	}
	u.push_back(1);
	u.push_back(n+1);
	sort(u.begin(), u.end());
	u.resize(unique(u.begin(), u.end())-u.begin());
	for(auto &e:g){
		int it = lower_bound(u.begin(), u.end(), e.first)-u.begin();
		int t = e.second, ad=1;
		if(t<0) ad=-1, t=-t;
		while(t%2==0) t>>=1, qs[it][0]+=ad;
		while(t%3==0) t/=3, qs[it][1]+=ad;
		while(t%5==0) t/=5, qs[it][2]+=ad;
		while(t%7==0) t/=7, qs[it][3]+=ad;
	}
	int sz = siz(u);
	ll ans1=0, ans2=0, cal=0;
	for(int i=0;i<sz-1;i++){
		qs[i+1][0]+=qs[i][0];
		qs[i+1][1]+=qs[i][1];
		qs[i+1][2]+=qs[i][2];
		qs[i+1][3]+=qs[i][3];
		cal = (qs[i][0]+1)*(qs[i][1]+1)*(qs[i][2]+1)*(qs[i][3]+1);
		if(ans1<cal) ans1=cal, ans2=u[i+1]-u[i];
		else if(ans1==cal) ans2+=u[i+1]-u[i];
	}
	cout << ans1 << " " << ans2;

	return 0;
}
