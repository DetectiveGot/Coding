#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 25;
ll dg[N], qs[N], sum[N];
//dg i digit

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	ll tc,a,b,c;
	cin >> tc;
	ll x;
	while(tc--) {
		cin >> a >> b >> c >> x;
		memset(dg, 0, sizeof(dg));
		memset(qs, 0, sizeof(qs));
		memset(sum,0,sizeof(sum));
		int d = floor(log10((double)a))+1;
		ll tp=0;
		// for(int i=0; i<d-1; i++) tp=tp*10+9;
		int i=d;
		tp = pow(10, d)-1;
		for(i=d;; i++) {
			sum[i]=tp/a;
			dg[i]=tp/a-sum[i-1];
			qs[i]=qs[i-1]+dg[i]*i;
//			deb(i), deb(dg[i]) << "\n";
			if(qs[i]>=x) break;
			tp=tp*10+9;
		}

		ll st = ((ll)pow(10, i-1)-1)/a*a+a;
//		deb(st) << "\n";
//		deb(x-qs[i-1]) << "\n";
		if((x-qs[i-1])%i==0) {
			ll y = (x-qs[i-1])/i;
			cout << (st+a*(y-1))%10 << "\n";
		} else {
			ll y=(x-qs[i-1])/i;
			ll cal = (st+a*y);
			string tmp = to_string(cal);
//			deb(cal) << endl;
			cout << tmp[(x-qs[i-1])%i-1] << "\n";
		}
	}

	return 0;
}
/*
1
10 10 10 1000000
*/
