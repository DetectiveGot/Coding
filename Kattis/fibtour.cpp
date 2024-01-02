#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+1;
ll a[N], fb[N];
unordered_map<ll, int> mp;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m; cin >> n >> m;
	fb[1]=1;
	for(int i=2;i<=86;i++) fb[i]=fb[i-1]+fb[i-2];
	for(int i=1;i<=n;i++) cin >> a[i];
	
//	for(int i=1;i<=n;i++) cin >> a[i];
	
	return 0;
}
