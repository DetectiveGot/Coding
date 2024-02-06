#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N=1e6+2, lim=N-1;
int qs[N];
bool p[N];
vector<ll> v;

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	for(int i=1; 4*i+1<N; i++) {
		if(p[4*i+1]) continue;
		for(int j=8*i+2;j<N;j+=4*i+1) p[j]=1;
	}
	for(int i=1;4*i+1<N;i++) if(!p[4*i+1]) v.push_back(4*i+1);
	for(int i=0;i<v.size();i++){
		for(int j=i;j<v.size();j++){
			if(v[i]*v[j]>lim) break;
			qs[v[i]*v[j]]=1;
		}
	}
	for(int i=1;i<N;i++) qs[i]+=qs[i-1];
	int n;
	while(cin >> n && n!=0)  cout << n << " " << qs[n] << "\n";

	return 0;
}
