#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

struct DATA{
	double a,b;
	int i;
	bool operator < (const DATA &dt) const{
		return a<dt.a;
	}
};
/*
sol 2 -> if still more than don't push
if can't connect then push the prv answer that can connect
*/

const int N = 2e4+1;
int dp[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	double A,B;
	int n;
	while(cin >> A >> B >> n){
		vector<DATA> v(n);
		vector<int> pa(n, -1);
		vector<int> ans;
		for(int i=0;i<n;i++) cin >> v[i].a >> v[i].b, v[i].i=i;
		sort(v.begin(), v.end());
		int p = 0, mn = 1e9;
		for(int i=0;i<n;i++){
			dp[i]=1e9;
			if(v[i].a<=A){
				dp[i]=1;
			} else {
				for(int j=0;j<i;j++){
					if(v[i].a<=v[j].b && dp[i]>dp[j]+1){
						dp[i]=dp[j]+1;
						pa[i]=j;
					}
				}
			}
			if(v[i].b>=B && dp[i]<mn){
				mn=dp[i];
				p=i;
			}
		}
		if(mn==1e9) cout << "impossible\n";
		else {
			cout << mn << "\n";
			while(pa[p]!=-1){
				ans.push_back(v[p].i);
				p=pa[p];
			}
			reverse(ans.begin(), ans.end());
			cout << v[p].i << " ";
			for(auto &e:ans) cout << e << " ";
			cout << "\n";
		}
	}
	
	return 0;
}

