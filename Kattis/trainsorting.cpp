#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 2001;
int a[N], lis[N], lds[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,ans=0; cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		lis[i]=lds[i]=1;
	}
	for(int i=n;i;--i){
		for(int j=n;j>i;--j){
			if(a[j]>a[i]) lis[i]=max(lis[i], lis[j]+1);
			if(a[j]<a[i]) lds[i]=max(lds[i], lds[j]+1);
		}
		ans=max(ans, lis[i]+lds[i]-1);
	}
	cout << ans;
	
	return 0;
}
