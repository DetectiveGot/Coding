#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 2e5+1;
int lis[N], a[N];
vector<int> g[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
		vector<int> ans;
		int cnt=0,p=0,x,num,t;
		for(int i=0;i<n;i++){
			cin >> a[i];
			p = lower_bound(lis, lis+cnt, a[i])-lis;
			if(p==cnt) ++cnt;
			lis[p]=a[i];
			g[p].push_back(i);
		}
		num=a[g[cnt-1][0]];
		ans.push_back(g[cnt-1][0]);
		for(int i=cnt-2;i>=0;--i){
			for(auto &e:g[i]){
				if(a[e]<num){
					num=a[e];
					ans.push_back(e);
					break;
				}
			}
		}
		reverse(ans.begin(), ans.end());
		cout << cnt << "\n";
		for(auto &e:ans) cout << e+1 << " ";
		cout << "\n";
	
	return 0;
}
/*
10
2 4 1 2 5 6 3 9 10 1
*/
