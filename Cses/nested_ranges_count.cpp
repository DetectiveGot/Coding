#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define tpi tuple<int,int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "
 
using namespace std;
 
const int N = 2e5+1;
int contain[N], is_contained[N], fw[N];
vector<int> com;

inline void upd(int i, int val){
	for(;i<N;i+=i&-i) fw[i]+=val;
}

inline int qry(int i){
	int res=0;
	for(;i>=1;i-=i&-i) res+=fw[i];
	return res;
}
 
int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,l,r; cin >> n;
	vector<tpi> v;
	for(int i=0;i<n;i++){
		cin >> l >> r;
		com.push_back(r);
		v.emplace_back(l,r,i);
	}
	sort(com.begin(), com.end());
	com.resize(unique(com.begin(), com.end())-com.begin());
	sort(v.begin(), v.end(), [](const tpi &x, const tpi &y){
		if(get<0>(x)==get<0>(y)) return get<1>(x)<get<1>(y);
		return get<0>(x)>get<0>(y);
	});
	vector<int> x;
	for(auto &[l, r, id]:v){
		int pos = lower_bound(com.begin(), com.end(), r)-com.begin()+1;
		contain[id] = qry(pos);
		upd(pos, 1);
	}
	memset(fw, 0, sizeof(fw));
	int cnt=0;
	sort(v.begin(), v.end(), [](const tpi &x, const tpi &y){
		if(get<0>(x)==get<0>(y)) return get<1>(x)>get<1>(y);
		return get<0>(x)<get<0>(y);
	});
	for(auto &[l, r, id]:v){
		int pos = lower_bound(com.begin(), com.end(), r)-com.begin()+1;
		is_contained[id] = cnt-qry(pos-1);
		upd(pos, 1);
		++cnt;
	}
	for(int i=0;i<n;i++) cout << contain[i] << " "; cout << "\n";
	for(int i=0;i<n;i++) cout << is_contained[i] << " ";
 
	return 0;
}
