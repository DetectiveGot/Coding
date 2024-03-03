#include<bits/stdc++.h>
#define ll long long
#define db double
#define pii pair<int,int>
#define pdb pair<db, db>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

struct DATA{
	db mn;
	pdb p1, p2;
};
vector<pdb> v;

inline db cal(const pdb &a, const pdb &b){
	db res=(a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
	return sqrt(res);
}

inline DATA solve(int l, int r){
	if(r-l<=3){
		db mn = 1e18;
		pdb p1, p2;
		for(int i=l;i<=r;i++){
			for(int j=i+1;j<=r;j++){
				db dx=cal(v[i], v[j]);
				if(dx<mn){
					mn=dx;
					p1=v[i], p2=v[j];
				}
			}
		}
		return {mn, p1, p2};
	}
	int m=(l+r)>>1;
	DATA mnn;
	mnn.mn=min(solve(l, m).mn, solve(m+1, r).mn);
	vector<pdb> tmp;
	for(int i=l;i<=r;i++)
		if(abs(v[i].first-v[m].first)<mnn.mn) tmp.emplace_back(v[i]);
	sort(tmp.begin(), tmp.end(), [&](const pdb &a, const pdb &b)->bool{
		return a.second<b.second;
	});
	for(int i=0;i<tmp.size();i++){
		for(int j=i+1;j<tmp.size();j++){
			db dx = cal(tmp[i], tmp[j]);
			pdb p1,p2;
			if(mnn.mn>dx){
				mnn.mn=dx;
				mnn.p1=tmp[i], mnn.p2=tmp[j];
			} else break;
		}
	}
	return mnn;
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n;
	while(cin >> n){
		if(n==0) break;
		db x,y;
		v.clear();
		for(int i=0;i<n;i++){
			cin >> x >> y;
			v.emplace_back(x,y);
		}
		sort(v.begin(), v.end());
		DATA ans=solve(0,n-1);
		cout << ans.p1.first << " " << ans.p1.second << " " << ans.p2.first << " " << ans.p2.second << "\n";
	}
	
	return 0;
}
