#include<bits/stdc++.h>

using namespace std;

map<int,int> dp;
struct DATA{
	int l,r,c;
	bool operator < (const DATA &dt) const{
		return r<dt.r;
	}
};
vector<DATA> v;

int main(){
	int n,l,r,c,ans=0; cin >> n;
	for(int i=1;i<=n;i++){
		cin >> l >> r >> c;
		v.push_back({l,r,c});
	}
	sort(v.begin(), v.end());
	dp[0]=0;
	for(auto &e:v){
		auto it = dp.lower_bound(e.l);
		--it;
		ans=max(ans, it->second+e.c);
		dp[e.r]=ans;
	}
	cout << ans;
	
	return 0;
}
