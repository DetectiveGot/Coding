#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

stack<char> op;
stack<double> num;
map<char,int> mp;

double cal(double a, double b, char cmd){
	if(cmd=='+') return a+b;
	else if(cmd=='-') return b-a;
	else if(cmd=='*') return a*b;
	else if(cmd=='/')return b/a;
}

int main(){
//	cin.tie(nullptr)->sync_with_stdio(0);
	string s; cin >> s;
	int n=s.size();
	mp['+']=mp['-']=1, mp['*']=mp['/']=2, mp['(']=mp[')']=3;
	for(int i=0;i<n;i++){
		if(s[i]=='(') op.push(s[i]);
		else if(s[i]==')'){
			while(!op.empty() && op.top()!='('){
				double t1=num.top(); num.pop();
				double t2=num.top(); num.pop();
				num.push(cal(t1,t2,op.top()));
				op.pop();
			}
			op.pop();
		} else if(s[i]>='0' && s[i]<='9'){
			int j=i;
			double tmp=0;
			while(s[j]>='0' && s[j]<='9') tmp = tmp*10+s[j++]-'0';
			i=j-1;
			num.push(tmp);
		} else {
			while(!op.empty() && mp[op.top()]>=mp[s[i]]){
				if(op.top()=='(') break;
				double t1=num.top(); num.pop();
				double t2=num.top(); num.pop();
				num.push(cal(t1,t2,op.top()));
				op.pop();
			}
			op.push(s[i]);
		}
	}
	while(!op.empty()){
		double t1=num.top(); num.pop();
		double t2=num.top(); num.pop();
		num.push(cal(t1,t2,op.top()));
		op.pop();
	}
	cout << fixed << setprecision(1) << num.top();
	
	return 0;
}
