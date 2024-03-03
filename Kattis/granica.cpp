#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 101;
int a[N];
vector<int> v;

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	int n;
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	sort(a, a+n);
	int gd=a[1]-a[0];
	for(int i=2; i<n; i++) gd=__gcd(gd, a[i]-a[i-1]);
	for(int i=2; i<=sqrt(gd); i++) {
		for(int i=1; i<=sqrt(gd); i++) {
			if(gd%i==0) {
				if(i>1) cout << i << " ";
				if(i*i!=gd) v.push_back(gd/i);
			}
		}
	}
		for(auto &e:v) cout << e << " ";

		return 0;
	}
