#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 101, mxN = 1e5+1;
int hh[mxN], bb[mxN];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int h,b,t,s=0; cin >> h;
	for(int i=1;i<mxN;i++) hh[i]=bb[i]=1e9;
	for(int i=0;i<h;i++){
		cin >> t,s+=t;
		for(int j=s;j>=t;--j) hh[j]=min(hh[j], hh[j-t]+1);
	}z
	cin >> b;
	for(int i=0;i<b;i++){
		cin >> t;
		for(int j=s;j>=t;--j) bb[j]=min(bb[j], bb[j-t]+1);
	}
	int ans=INT_MAX;
	for(int i=1;i<=s;i++) if(hh[i]!=1e9 && bb[i]!=1e9) ans=min(ans, hh[i]+bb[i]);
	if(ans==INT_MAX) cout << "impossible";
	else cout << ans;
		
	return 0;
}
