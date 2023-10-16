/*LANG: C++*/
#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 5;
int a[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a+3);
	unordered_map<char,int> mp;
	mp['A']=a[0];
	mp['B']=a[1];
	mp['C']=a[2];
	char x,y,z; cin >> x >> y >> z;
	cout << mp[x] << " " << mp[y] << " " << mp[z];
	
	return 0;
}
