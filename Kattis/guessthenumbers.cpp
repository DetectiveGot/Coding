#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 10;
ll a[N],pr[300],val[300], n, res;
string s;

inline ll cal(const ll x, const ll y, const char op){
	if(op=='*') return x*y;
	else if(op=='/') return x/y;
	else if(op=='+') return x+y;
	else if(op=='-') return y-x;
	return 0;
}

inline bool brute(){
	stack<ll> st;
	stack<char> op;
	for(auto &e:s){
		if(e=='(') op.push(e);
		else if(e>='a' && e<='z') st.push(val[e]);
		else {
			if(e==')'){
				while(!op.empty() && op.top()!='('){
					ll x = st.top(); st.pop();
					ll y = st.top(); st.pop();
					char c = op.top(); op.pop();
					st.push(cal(x,y,c));
				}
				op.pop();
			} else {
				while(!op.empty() && pr[op.top()]>=pr[e]){
					ll x = st.top(); st.pop();
					ll y = st.top(); st.pop();
					char c = op.top(); op.pop();
					st.push(cal(x,y,c));
				}
				op.push(e);
			}
		}
	}
	while(!op.empty()){
		ll x = st.top(); st.pop();
		ll y = st.top(); st.pop();
		char c = op.top(); op.pop();
		st.push(cal(x,y,c));
	}
	return st.top()==res;
}

inline bool solve(){
	vector<char> vec;
	vector<bool> ch(26);
	for(auto &e:s) if(e>='a' && e<='z') ch[e-'a']=1;
	for(int i=0;i<26;i++) if(ch[i]) vec.push_back(char(i+'a'));
	assert(vec.size()==n);
	do {
		for(int i=0;i<n;i++) val[vec[i]]=a[i];
		if(brute()) return true;
	} while(next_permutation(vec.begin(), vec.end()));
	return false;
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	pr['(']=pr[')']=0;
	pr['*']=pr['/']=2;
	pr['+']=pr['-']=1;
	while(cin >> n && n!=0){
		assert(n<=5);
		for(int i=0;i<n;i++) cin >> a[i];
		cin >> res >> s;
		cout << (solve()?"YES\n":"NO\n");
	}

	return 0;
}
/*
3 2 3 4 14
((a+b)*c)
2 4 3 11
(a-b)
1 2 2
a
0 0
*/
