#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	string s; cin >> s;
	int n; cin >> n;
	double sm=0,w,t,ww=0;
	while(n--){
		cin >> s >> w >> t;
		ww+=w;
		if(t>=90){
			cout << "A\n";
			sm+=4*w;
		} else if(t>=80){
			sm+=3*w;
			cout << "B\n";
		} else if(t>=70){
			sm+=2*w;
			cout << "C\n";
		} else if(t>=60){
			sm+=w;
			cout << "D\n";
		} else {
			cout << "F\n";
		}
	}
    sm/=ww;
	cout << fixed << setprecision(1) << sm;
	
	return 0;
}
