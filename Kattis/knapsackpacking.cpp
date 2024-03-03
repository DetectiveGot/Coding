#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 19;
vector<ll> ans;
ll a[1<<N];
vector<ll> dp;
unordered_map<ll,int> mp;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int sz; cin >> sz;
	int n=1<<sz;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1, a+n+1);
	int ly=0;
	if(a[1]!=0){
		cout << "impossible";
		return 0;
	}
	for(int i=2;i<=n;i++){
		if(mp[a[i]]) mp[a[i]]--;
		else {
			++ly;
			ans.push_back(a[i]);
			vector<ll> tmp;
			for(auto &e:dp) tmp.push_back(e+a[i]);
			for(auto &e:tmp) dp.push_back(e), mp[e]++;
			dp.push_back(a[i]);
		}
		if(ly>sz){
			cout << "impossible";
			return 0;
		}
	}
	for(auto &e:ans) cout << e << "\n";
	
	return 0;
}

