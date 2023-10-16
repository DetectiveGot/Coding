#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 31623;
bool p[N];
vector<int> v;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	for(int i=2;i*i<N;i++){
		if(p[i]) continue;
		for(int j=i*i;j<N;j+=i) p[j]=1;
	}
	v.push_back(2);
	for(int i=3;i<N;i+=2)
		if(!p[i]) v.push_back(i);
	int q,t; cin >> q;
	while(q--){
		cin >> t;
		int ans=1;
		for(auto &e:v){
			if(e*e>t) break;
			if(t%e==0){
				int cnt=0;
				while(t%e==0) t/=e,++cnt;
				ans=__gcd(ans, cnt);
			}
		}
		if(t>1 || ans==1) cout << "NO";
		else cout << ans;
		cout << "\n";
	}
	
	return 0;
}
