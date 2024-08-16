#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e6+1;
ll ch[N], a[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int q; cin >> q;
	while(q--){
		ll n,k,t; cin >> n >> k;
		ll ans=(n*(n+1))/2,cnt=0;
		int l=1;
		for(int i=1;i<=n;i++){
			cin >> a[i];
			if(!ch[a[i]]) cnt++;
			ch[a[i]]++;
			while(l<i && cnt>=k){
				--ch[a[l]];
				if(!ch[a[l]]) --cnt;
				++l;
			}
			ans-=i-l+1;
		}
		cout << ans << "\n";
		memset(ch, 0, sizeof(ch));
	}
	
	return 0;
}