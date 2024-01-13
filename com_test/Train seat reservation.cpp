#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 10;
bool a[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	string s; cin >> s;
	int n=s.size();
	for(int i=0;i<n;){
		if(s[i]=='-'){
			a[s[i+1]-'0']=0;
			i+=2;
		} else {
			a[s[i]-'0']=1;
			i++;
		}
	}
	for(int i=1;i<=9;i++){
		if(a[i]) cout << "1 ";
		else cout << "- ";
	}
	
	return 0;
}
