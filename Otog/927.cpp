#include<bits/stdc++.h>
#define db double
#define pdb pair<double,double>

using namespace std;

const int N = 1e5+1;
vector<pdb> v;
priority_queue<double, vector<double>, greater<double>> pq;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	db a,b,c,d,m1,m2;
	for(int i=0;i<n;i++){
		cin >> a >> b >> c >> d;
//		if(a==0) m1=1e9;
//		else m1=b/a;
//		if(c==0) m2=1e9;
//		else m2=d/c;
		m1=b/a,m2=d/c;
		v.push_back({max(m1,m2),min(m1,m2)});
	}
	sort(v.begin(), v.end());
	int ans=0;
	pq.push(v[0].first);
	for(int i=1;i<n;i++){
		if(!pq.empty() && v[i].second>pq.top()){
			pq.pop();
			pq.push(v[i].first);
		} else ans++;
	}
	cout << ans;
	
	return 0;
}
