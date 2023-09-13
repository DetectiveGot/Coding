#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 14;
ll fac[N], a[N];
bool used[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,k; cin >> n >> k;
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i;
	while(k--){
		ll ans=0;
		for(int i=1;i<=n;i++) cin >> a[i],used[i]=0;
		for(int i=1;i<=n;i++){
			ll c=0;
			for(int j=1;j<a[i];j++){
				if(!used[j]) c++;
			}
			ans+=c*fac[n-i];
			used[a[i]]=1;
		}
		cout << ans+1 << "\n";
	}
	
	return 0;
}
/*
4 8
1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 2 3
1 4 3 2
3 1 4 2
2 4 3 1

1 2 3 4 - 1
1 2 4 3 - 2
1 3 2 4 - 3
1 3 4 2 - 4
1 4 2 3 - 5
1 4 3 2 - 6
3 1 4 2 - 14
2 4 3 1 - 12
*/
