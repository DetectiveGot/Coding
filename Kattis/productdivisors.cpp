#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e6+1, mod = 1e9+7;
bool p[N];
vector<int> v;
int mp[N],cnt[N], id=0;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	for(int i=2;i*i<N;i++){
		if(p[i]) continue;
		for(int j=i*i;j<N;j+=i) p[j]=1;
	}
	v.push_back(2); mp[2]=id++;
	for(int i=3;i<N;i+=2) if(!p[i]) v.push_back(i), mp[i]=id++;
	int n,t; cin >> n;
	for(int i=1;i<=n;i++){
		cin >> t;
		for(auto &e:v){
			if(e*e>t) break;
			while(t%e==0){
				cnt[mp[e]]++;
				t/=e;
			}
		}
		if(t>1) cnt[mp[t]]++;
	}
	ll ans=1;
	for(int i=0;i<id;i++) if(cnt[i]) ans=ans*(cnt[i]+1)%mod;
	cout << ans;
	
	return 0;
}
