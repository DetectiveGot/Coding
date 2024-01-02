#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 62501;
int pos[N], a[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int tc,u,v,cs=0; cin >> tc;
	while(tc--){
		int n,p,q,t; cin >> n >> p >> q;
		for(int i=1;i<=p;i++) cin >> a[i], pos[a[i]]=i;
		vector<int> v;
		for(int i=1;i<=q;i++){
			cin >> t;
			if(!pos[t]) continue;
			auto it = lower_bound(v.begin(), v.end(), pos[t]);
			if(it==v.end()) v.push_back(pos[t]);
			else *it = pos[t];
		}
		cout << "Case " << ++cs << ": " << q-v.size() << "\n";
	}
	
	return 0;
}
