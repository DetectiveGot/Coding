#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e4+2;
stack<int> st;
stack<char> op;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	string s; cin >> s;
	int n=s.size();
	auto cal = [](const int x, const char c)->int{
		if(c=='1') return 0.04*x+x;
		else if(c=='2') return 0.08*x+x;
		else return 0.16*x+x;
	};
	for(auto &e:s){
		if(e>='A' && e<='Z'){
			st.push(20);
			continue;
		}
		if(e==']'){
			while(!op.empty() && op.top()!='['){
				int x = st.top(); st.pop();
				int y = st.top(); st.pop();
				char c = op.top(); op.pop();
				st.push(cal(x+y, c));
			}
			op.pop();
		} else if(e=='[') op.push(e);
		else {
			while(!op.empty() && op.top()>='1' && op.top()<='3' && e<=op.top()){
				int x = st.top(); st.pop();
				int y = st.top(); st.pop();
				char c = op.top(); op.pop();
				st.push(cal(x+y,c));
			}
			op.push(e);
		}
	}
	while(!op.empty()){
		int x = st.top(); st.pop();
		int y = st.top(); st.pop();
		char c = op.top(); op.pop();
		st.push(cal(x+y,c));
	}
	cout << st.top();

	return 0;
}
