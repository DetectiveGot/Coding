#include<iostream>
#include<algorithm>
#define ll long long

using namespace std;

const int N = 11, M = 1e7+2;
int a[N], st[M], t[N], que[N], A[N];
ll qs[M], L[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m,x; cin >> n >> m >> x;
	for(int i=1;i<=n;i++) cin >> L[i];
	for(int i=1;i<=n;i++) cin >> A[i];
	for(int i=1;i<=m;i++) cin >> st[i], qs[i]=qs[i-1]+st[i];
	for(int i=1;i<=x;i++) cin >> t[i];
	sort(A+1, A+n+1);
	sort(L+1, L+n+1);
	que[n]=m;
	for(int i=1;i<=x;i++){
		for(int j=0;j<n;j++) cin >> que[j], a[j+1]=A[j+1];
		int lt,rt;
		bool ok=true;
		do {
			ok=true;
			for(int j=1;j<=n && ok;j++){
				lt = que[j-1], rt = que[j];
				int cnt=0;
				ll all = L[j]-a[j];
				while(lt<rt){
					lt = upper_bound(qs+lt, qs+rt, qs[lt-1]+all)-qs;
					++cnt;
					if(cnt>t[i]){
						ok = false;
						break;
					}
				}
			}
		} while(!ok && next_permutation(a+1, a+n+1));
		if(ok) cout << "P\n";
		else cout << "F\n";
	}

	return 0;
}