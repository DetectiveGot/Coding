#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 101;
int a[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m; cin >> n >> m;
	int l=0, r=1e9;
	for(int i=0;i<m;i++) cin >> a[i], l=max(l, a[i]);
	while(l<r){
		int md = l+r>>1, s=0, c=1;
		for(int i=0;i<m;i++){
			s+=a[i];
			if(s>md) s=a[i],++c; 
		}
		if(c>n) l=md+1;
		else r=md;
	}
	cout << l;

	return 0;
}

