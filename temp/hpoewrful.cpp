/*LANG: C++*/
#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int mxN = 5e6+1, N = sqrt(5e6)+1;
int p[mxN],hp[mxN];

//inline int prodex(int x){
//	int cnt=1;
//	for(auto &e:v){
//		if(e*e>x) break;
//		int c=0;
//		while(x%e==0) x/=e, c++;
//		if(c) cnt*=c;
//	}
//	return cnt;
//}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,q; cin >> n >> q;
//	for(int i=2;i*i<=sq;i++){
//		if(p[i]) continue;
//		for(int j=i*i;j<=sq;j+=i) p[j]=1;
//	}
//	v.push_back(2);
//	for(int i=3;i<=sq;i+=2)
//		if(!p[i]) v.push_back(i);
//	int mx=0;
//	for(int i=1;i<=n;i++){
//		int pdx=prodex(i);
//		if(pdx>mx) mx=pdx, hp[i]=i;
//		else hp[i]=hp[i-1];
//		mem[i]=pdx;
//	}
	p[1]=hp[1]=1;
	int mx=1;
	for(int i=2;i<=n;i++){
		if(!p[i]){
			for(int j=i;j<=n;j+=i){
				int t=j, c=0;
				if(!p[j]) p[j]=1;
				while(t%i==0){
					t/=i;
					c++;
				}
				p[j]*=c;
			}
		}
		hp[i]=hp[i-1];
		if(p[i]>mx) hp[i]=i,mx=p[i];
	}
	int t;
	while(q--){
		cin >> t;
		cout << p[t] << " " << hp[t] << "\n";
	}
	
	return 0;
}

/*
2^2 * 3^1 -> (1+2+4)*(1+3) = 28
*/
