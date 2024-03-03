#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1000;
int a[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,k; cin >> n >> k;
	string s;
	for(int i=0;i<n;i++){
		cin >> s;
		for(auto &e:s) a[i]=(a[i]<<1)+(e=='T');
	}
	int ans=0;
	for(int i=0;i<1<<k;i++){
		int mn=1e9;
		for(int j=0;j<n;j++){
			int c=0;
			for(int x=0;x<k;x++)
				if((a[j]&(1<<x))==(i&(1<<x))) ++c;
			mn=min(mn, c);
		}
		ans=max(ans, mn);
	}
	cout << ans;

	return 0;
}

