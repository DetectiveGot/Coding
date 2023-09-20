#include<bits/stdc++.h>

using namespace std;

const int N = 27;
int a[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	string add="";
	for(char&e:s) a[e-'A']++;
	int cnt=0;
	for(int i=0;i<=26;i++){
		if(a[i]&1){
			cnt++;
			add=(char)(i+'A');
		}
	}
	if(cnt>1) cout << "NO SOLUTION";
	else {
		string ans="";
		for(int i=0;i<=26;i++)
			for(int j=0;j<a[i]/2;j++)
				ans+=(char)(i+'A');
		cout << ans+add;
		reverse(ans.begin(), ans.end());
		cout << ans;
	}
	
	return 0;
}
