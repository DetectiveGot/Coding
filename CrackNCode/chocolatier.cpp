#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>

using namespace std;

const int mxM = 1e6+2, mxN = 1002, mxP = 1e5+2;
vector<int> row;
pii ar[mxM];
int dp[2][mxN];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int m,n,p; cin >> m >> n >> p;
	for(int i=0;i<p;i++){
		int x,y,w; cin >> x >> y >> w;
		row.push_back(x);
		ar[x]={y,w};
	}
	sort(row.begin(), row.end());
	int pr=0;
	for(int i=0;i<p;i++){
		int now=i%2, prv=(i+1)%2, rn=row[i];
		deque<pii> pq;
		int lim=rn-pr;
		for(int i=1;i<=lim+1;i++){
			while(!pq.empty() && pq.back().first<=dp[prv][i]) pq.pop_back();
			pq.push_back({dp[prv][i], i});
		}
		for(int i=1;i<=1000;i++){
			while(!pq.empty() && i-pq.front().second>lim) pq.pop_front();
			if(i+lim<=1000){
				while(!pq.empty() && pq.back().first<=dp[prv][i+lim]) pq.pop_back();
				pq.push_back({dp[prv][i+lim], i+lim});
			}
			if(ar[rn].first==i) dp[now][i]=pq.front().first+ar[rn].second;
			else dp[now][i]=pq.front().first;
		}
		memset(dp[prv], 0, sizeof(dp[prv]));
		pr=rn;
	}
	int mx=0;
	for(int i=1;i<=1000;i++) mx=max(mx, dp[(p-1)%2][i]);
	cout << mx;
	
	return 0;
}
