#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e5+2, LIM = sqrt(5e6)+5, mxN = 5e6+2;
bool p[LIM];
int a[N], cnt[mxN];
vector<int> v;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,ans=0,t; cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=2;i<=lim;i++){
		if(!p[i]){
			v.push_back(i);
			for(int j=2*i;j<=lim;j+=i){
				p[j]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		t=a[i];
		for(auto&e:v){
			if(e*e>t) break;
			int c=0;
			while(t%e==0){
				t/=e;
				c++;
			}
			cnt[e]=max(cnt[e], c);
		}
		if(t>1) cnt[t]=max(cnt[t], 1);
	}
	for(int i=1;i<5000000;i++) ans+=cnt[i];
	cout << ans;
	
	return 0;
}