//credit: Khlui
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "
using namespace std;

char base[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	string str, ans; cin >> str;
	int baseX, baseY; cin >> baseX >> baseY;
	long long temp=0;
	if((baseX<2||baseX>36) or (baseY<2||baseY>36)) {
		cout << "error"; return 0;
	}
	for(int i=0;i<str.size(); i++) {
		if(str[i]>='0' and str[i]<='9') {
			if(str[i]>base[baseX-1]) {
				cout <<"error"; return 0;
			}
			temp+=pow(baseX, str.size()-i-1)*(str[i]-'0');
		} else if(str[i]>='A' and str[i]<='Z') {
			if(str[i]>base[baseX-1]) {
				cout << "error"; return 0;
			}
			temp+=pow(baseX, str.size()-i-1)*(str[i]-'A'+10);
		} else {
			cout << "error"; return 0;
		}
	}
	if(temp==0) {
		cout << '0'; return 0;
	}
	while(temp>0) {
		ans+=base[temp%baseY];
		temp/=baseY;
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
	return 0;
}
