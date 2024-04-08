#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e5+2;
int p[N][202], a[N], mp[1002]; // 1-1000, prime
vector<int> pr;
bool ch[N];

ll binpow(ll a, ll b, ll mod){
  ll res=1;
  while(b){
    if(b&1){
      res=(res*a)%mod;
    }
    a=(a*a)%mod;
    b>>=1;
  }
  return res;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,q,cc=0; cin >> n >> q;
	for(int i=2;i<=1000;i++){
		if(!ch[i]){
			for(int j=i*2;j<=1000;j+=i){
				ch[j]=1;
			}
	        mp[i]=cc++;
			pr.push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		cin >> a[i];
    	int t=a[i];
		for(auto&e:pr){
			if(e*e>t) break;
			while(t%e==0){
				t/=e;
				p[i][mp[e]]++;
			}
		}
		if(t>1) p[i][mp[t]]++;
    for(int j=0;j<cc;j++) p[i][j]+=p[i-1][j];
	}
  while(q--){
    ll l, r, mod, ans=1; cin >> l >> r >> mod;
    for(int i=0;i<cc;i++){
      if(p[r][i]-p[l-1][i]){
      	ans=(ans*binpow(pr[i], p[r][i]-p[l-1][i], mod))%mod;
	  }
    }
    cout << ans << "\n";
  }
	
	return 0;
}

