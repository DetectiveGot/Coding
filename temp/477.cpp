#include<bits/stdc++.h>

using namespace std;

const int N = 1011;
int a[N];

inline void solve(string t, int b){
	int n=t.size();
	vector<int> v;
	for(int i=1;i<=n;i++) a[i]=t[i-1]-'0';
	while(n>=1){
		for(int i=n;i>=1;--i){
			if(a[i]<b) a[i]=0,--n;
			else a[i]/=b;
		}
		cout << a[n-i+1];
	}
	cout << "\n";
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	string s; cin >> s;
	for(int i=2;i<=9;i++){
		cout << i << " : ";
		solve(s, i);
	}
	
	return 0;
}
