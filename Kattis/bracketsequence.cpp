#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;
const int mod = 1e9+7;
stack<ll> st;
stack<char> op;
//stack<string> st;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	string s;
	bool sg=0;
	for(int i=0;i<n;i++){
		cin >> s;
		if(s=="("){
			sg^=1;
			op.push('(');
		} else if(s==")"){
			ll v=st.top();
			st.pop();
			op.pop();
			while(!op.empty() && op.top()!='('){
				if(sg) v*=st.top(), v%=mod;
				else v+=st.top(), v%=mod;
				st.pop();
				op.pop();
			}
			op.pop();
			sg^=1;
			st.push(v);
			op.push('a');
		} else {
			ll x=0;
			for(auto &e:s) x=x*10+e-'0';
			st.push(x);
			op.push('a');
		}
	}
	ll ans=0;
	while(!st.empty()) ans+=st.top(), ans%=mod, st.pop();
	cout << ans;

	return 0;
}

