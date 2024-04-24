#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "
#define tpi tuple<ll,int,int>

using namespace std;

const int N = 11, M = 1e7+2;
int t[N], que[N], A[N];
ll qs[M], L[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m,x; cin >> n >> m >> x;
	for(int i=1;i<=n;i++) cin >> L[i];
	for(int i=1;i<=n;i++) cin >> A[i];
	for(int i=1;i<=m;i++) cin >> qs[i];
	for(int i=1;i<=m;i++) qs[i]+=qs[i-1];
	for(int i=1;i<=x;i++) cin >> t[i];
	sort(L+1, L+n+1, greater<ll>());
	sort(A+1, A+n+1);
	bool def=true;
	for(int i=1;i<=n;i++) L[i]-=A[i], def&=L[i]>0;
	que[n+1]=m+1;
	int lt, rt;
	ll w;
	for(int i=1;i<=x;i++){
		for(int j=1;j<=n;j++) cin >> que[j];
		if(!def){
			cout << "F\n";
			continue;
		}
		vector<pii> vec;
		for(int j=1;j<=n;j++) vec.emplace_back(qs[que[j+1]-1]-qs[que[j]-1], j);
		sort(vec.rbegin(), vec.rend());
		bool ok=def;
		for(int j=1;j<=n && ok;j++){
			w = vec[j-1].first, rt = que[vec[j-1].second+1], lt = que[vec[j-1].second];
			int cnt=0;
			--w;
			w/=L[j];
			++w;
			if(w>t[i]){
				ok=false;
				break;
			}
			while(lt<rt){
				lt = upper_bound(qs+lt, qs+rt, qs[lt-1]+L[j])-qs;
				if(++cnt>t[i]){
					ok=false;
					break;
				}
			}
		}
		if(ok) cout << "P\n";
		else cout << "F\n";
	}

	return 0;
}