#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define ppi pair<pii, int>
#define deb(x) cout << #x << ": " << x << " "

using namespace std;
const int N = 2e5+1;
ll qs[N], a[N];
struct DATA{
	ll val;
	int i , p;
	bool operator < (const DATA &dt) const{
		return val<dt.val;
	}
};
priority_queue<DATA> pq;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	ll mx=0;
	DATA tmp;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		qs[i]=qs[i-1]+a[i];
		while(!pq.empty() && pq.top().i^i){
			tmp=pq.top();
			pq.pop();
			int l=tmp.i, p=tmp.p;
			pq.push({tmp.val+a[l]*p-a[i]*p, i, p});
		}
		if(!pq.empty()){
//			int p=pq.top().p, y=pq.top().val;
			mx=max(mx, pq.top().val-qs[i-1]+a[i]*i);
//			deb(i); deb(x); deb(y); deb(p) << endl;
		}
		pq.push({-a[i]*i+qs[i-1], i, i});
	}
	cout << mx;
	
	return 0;
}
/*
7
10 1 5 9 4 9 3
*/