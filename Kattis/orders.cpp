#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 3e4+1;
ll dp[N];
int pa[N], id[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m,t; cin >> n;
	dp[0]=1;
	for(int i=1;i<=n;i++){
		cin >> t;
		for(int j=t;j<N;++j){
			if(dp[j-t]){
				dp[j]+=dp[j-t];
				pa[j]=j-t;
				id[j]=i;
			}
		}
	}
	cin >> m;
	for(int i=0;i<m;i++){
		cin >> t;
		if(!dp[t]) cout << "Impossible\n";
		else if(dp[t]>1) cout << "Ambiguous\n";
		else {
			int u=t;
			vector<int> v;
			while(u){
				v.push_back(id[u]);
				u=pa[u];
			}
			reverse(v.begin(), v.end());
			for(auto &e:v) cout << e << " ";
			cout << "\n";
		}
	}
	
	return 0;
}
