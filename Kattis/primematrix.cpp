#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 51, mxN = 3001;
ll a[N];

inline bool prime(ll x){
	for(int i=2;i*i<=x;i++)
		if(x%i==0) return false;
	return true;
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	ll b,sm=0;
	int n; cin >> n >> b;
	for(int i=1;i<=n;i++) a[i]=i, sm+=i;
	int k=n;
	for(int i=sm;!prime(i);i++){
		a[k--]++;
		if(!k) k=n;
	}
	if(a[n]>b){
		cout << "impossible\n";
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cout << a[(i+j-2)%n+1] << " ";
		cout << "\n";
	}

	return 0;
}

