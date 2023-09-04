#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 2e5+2;
ll a[N], qs[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,k; cin >> n >> k;
	ll l=0, r=1e18;
	for(int i=1;i<=n;i++) cin >> a[i], qs[i]+=qs[i-1]+a[i], l=max(l, a[i]);
	while(l<r){
		ll mid=(l+r+1)/2, sum=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(sum+a[i]>=mid){
				sum=a[i];
				cnt++;
			} else sum+=a[i];
		}
		if(cnt>=k) l=mid;
		else r=mid-1;
	}
	cout << l;
	
	return 0;
}
