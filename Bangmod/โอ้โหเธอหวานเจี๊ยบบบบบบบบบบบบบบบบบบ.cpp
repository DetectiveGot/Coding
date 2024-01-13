#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+1;
int a[N], qs[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int q; cin >> q;
	while(q--){
		int n,l,r,mx=0,ans=INT_MIN; cin >> n >> l >> r;
		deque<int> dq;
		for(int i=1;i<=n;i++) cin >> a[i], qs[i]=qs[i-1]+a[i];
		dq.push_back(0);
		for(int i=1;i<=n;i++){
			while(!dq.empty() && i-dq.front()>r) dq.pop_front();
			while(!dq.empty() && i-dq.front()>l && qs[i-l]<=qs[dq.back()]) dq.pop_back();
			if(i-l>0) dq.push_back(i-l);
			if(i-dq.front()>=l) ans=max(ans, qs[i]-qs[dq.front()]);
		}
		cout << ans << "\n";
	}
	
	return 0;
}
/*
1
5
2 4
-3 -8 -8 -6 8
*/
