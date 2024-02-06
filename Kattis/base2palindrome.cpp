#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int lim = 15;
vector<ll> v{1};
string s="1";

inline void make(int i) {
	if(i>lim) return;
//	deb(s) << endl;
	string tmp="";
	//even sz
	tmp=s;
	for(int i=s.size()-1; i>=0; --i) tmp+=s[i];
	ll cal=0;
	for(auto &e:tmp) cal = cal*2+e-'0';
	v.push_back(cal);
	//odd sz
	tmp=s;
	tmp+='0';
	for(int i=s.size()-1; i>=0; --i) tmp+=s[i];
	cal=0;
	for(auto &e:tmp) cal = cal*2+e-'0';
	v.push_back(cal);
	tmp[s.size()]='1';
	v.push_back(cal^(1ll<<(ll)s.size()));

	s+='0';
	make(i+1);
	s.pop_back();
	s+='1';
	make(i+1);
	s.pop_back();

}

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	int n;
	cin >> n;
	if(n==0){
		cout << 0;
		return 0;
	}
	make(1);
	sort(v.begin(), v.end());
//	v.resize(unique(v.begin(), v.end())-v.begin());
	cout << v[n-1];

	return 0;
}
