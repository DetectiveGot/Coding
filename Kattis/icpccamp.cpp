#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define inf (int)1e9
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1001;
vector<int> a,b;
struct DATA{
	int l,r;
	bool operator < (const DATA &dt) const{
		return r>dt.r;
	}
};

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,p,q,s,t; cin >> n >> p >> q >> s;
	for(int i=0;i<p;i++){
		cin >> t;
		a.push_back(t);
	}
	for(int i=0;i<q;i++){
		cin >> t;
		b.push_back(t);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int l=0,r=s+1;
	while(l<r){
		int m = l+r>>1;
		vector<pii> tmp;
		for(auto &e:a) tmp.push_back({e-m, min(e+m, s-e)});
		sort(tmp.begin(), tmp.end());
		priority_queue<DATA> pq; //range l to r
		int j=0,cnt=0;
		for(int i=0;i<q;i++){
			while(j<p && tmp[j].first<=b[i]){
				pq.push({tmp[j].first, tmp[j].second});
				++j;
			}
			while(!pq.empty()){
				int rs = pq.top().r;
				pq.pop();
				if(rs>=b[i]){
					++cnt;
					break;
				}
			}
		}
		if(cnt<n) l=m+1;
		else r=m;
	}
	if(s<l) cout << -1;
	else cout << l;

	return 0;
}

