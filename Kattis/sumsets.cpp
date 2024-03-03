#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 4001;
ll a[N];
vector<tuple<ll,ll,ll>> ab,cd;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1, a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ab.emplace_back(a[i]+a[j], i, j);
			cd.emplace_back(a[j]-a[i], j, i);
		}
	}
	for(int d=n;d>=1;--d){
		for(int c=1;c<=n;c++){
			ll val = a[d]-a[c];
			auto fd = mp.find(val);
			if(fd!=mp.end()){
				int p = fd->second;
				if()
			}
		}
	}
	cout << "no solution";

	return 0;
}

