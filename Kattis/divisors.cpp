#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 432;
bool p[N];
vector<ll> v;
ll cnt[N],mp[N],id=0;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	for(int i=2;i*i<N;i++){
		if(p[i]) continue;
		for(int j=i*i;j<N;j+=i) p[j]=1;
	}
	v.push_back(2); mp[2]=id++;
	for(int i=3;i<N;i+=2){
		if(!p[i]) v.push_back(i), mp[i]=id++;
	}
	ll n,k,x;
	while(cin >> n >> k){
		for(auto &e:v){
			ll pw=e;
			if(pw>n) break;
			while(n>=pw){
				cnt[mp[e]]+=n/pw;
				pw*=e;
			}
		}
		for(auto &e:v){
			ll pw=e;
			if(pw>k) break;
			while(k>=pw){
				cnt[mp[e]]-=k/pw;
				pw*=e;
			}
		}
		x=n-k;
		for(auto &e:v){
			ll pw=e;
			if(pw>x) break;
			while(x>=pw){
				cnt[mp[e]]-=x/pw;
				pw*=e;
			}
		}
		ll ans=1;
		for(int i=0;i<id;i++)
			if(cnt[i]) ans*=(cnt[i]+1);
		cout << ans << "\n";
		memset(cnt, 0, sizeof(cnt));
	}
	
	return 0;
}
