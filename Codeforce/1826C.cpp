#include<bits/stdc++.h>

using namespace std;

const int N = 1e6+2;
int p[N];

void solve(){
	int n,m; cin >> n >> m;
	if(p[n]>m || n==1 || m==1) cout << "YES\n";
	else cout << "NO\n";
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	for(int i=2;i<=(int)1e6;i++){
		if(!p[i]){
			for(int j=i;j<=(int)1e6;j+=i)
				if(!p[j]) p[j]=i;
		}
	}
	int n; cin >> n;
	while(n--) solve();
	
	return 0;
}
