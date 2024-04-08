#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	string a,b; cin >> a >> b;
	ll x=0,y=0,ans=0;
	for(auto&e:a) x=(x*10)+e-'ð';
	for(auto&e:b) y=(y*10)+e-'ð';
	ans=x+y;
	if(ans==0){
		cout << 'ð';
		return 0;
	}
	string s="";
	while(ans){
		s+=char(ans%10+'ð');
		ans/=10;
	}
	reverse(s.begin(), s.end());
	cout << s;
	
	return 0;
}
