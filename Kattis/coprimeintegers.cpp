#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e7+1;
bool p[N];
vector<int> v;

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);

	for(int i=2; i*i<N; i++) {
		if(p[i]) continue;
		for(int j=i*i; j<N; j+=i) p[j]=1;
	}
	p[0]=p[1]=1;
	v.push_back(2);
	for(int i=3; i<N; i+=2) if(!p[i]) v.push_back(i);
	ll a,b,c,d,ans=0;
	cin >> a >> b >> c >> d;
	if(b-a>d-c) swap(a,c), swap(b,d);
	for(int i=a; i<=b; i++) {
		int t=i,cnt=0;
		vector<int> ar;
		if(!p[i]) {
			ans+=d-c+1-(d/i-(c-1)/i);
		} else {
			for(auto &e:v) {
				if(e*e>t) break;
				if(t%e==0) {
					ar.push_back(e);
					while(t%e==0) t/=e;
				}
			}
			if(t>1) ar.push_back(t);
			int sz = ar.size();
			if(sz==1) {
				ans+=(d-c+1-(d/ar[0]-(c-1)/ar[0]));
			} else {
				ll mem=0;
				for(int j=1; j<1<<sz; j++) {
					cnt=0;
					int t2 = c-1;
					t=d;
					for(int k=0; k<sz; k++) {
						if(j&(1<<k)) {
							++cnt;
							t/=ar[k];
							t2/=ar[k];
						}
					}
					if(cnt&1) mem+=t, mem-=t2;
					else mem-=t,mem+=t2;
				}
				ans+=d-c+1-mem;
			}
		}
	}
	cout << ans;
	
	return 0;
}
