#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 15002;
pii a[N];
int dist[N];
priority_queue<int> pq;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,k; cin >> n >> k;
	for(int i=0;i<n;i++) cin >> a[i].first >> a[i].second;
	auto cal = [](const pii &x, const pii &y){
		return abs(x.first-y.first)+abs(x.second-y.second);
	};
	int ans=0;
	for(int i=1;i<=n;i++) dist[i]=1e9;
	for(int i=0;i<n-1;i++){
		int mn = 1e9, v = -1, dx;
		for(int j=i+1;j<n;j++){
			dx = cal(a[i], a[j]);
			dist[j]=min(dist[j], dx);
			if(mn>dist[j]) mn=dist[j], v = j;
		}
		if(v==-1) continue;
		pq.push(mn);
		ans+=mn;
		swap(a[i+1], a[v]);
		swap(dist[i+1], dist[v]);
	}
	--k;
	while(k--) ans-=pq.top(), pq.pop();
	cout << ans;
	
	return 0;
}

