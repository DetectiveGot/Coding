#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e6+1;
int a[N];
deque<int> mx,mn;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m,c; cin >> n >> m >> c;
	for(int i=0;i<n;i++) cin >> a[i];
	bool ok=false;
	for(int i=0;i<n;i++){
		while(!mx.empty() && i-mx.front()>=m) mx.pop_front();
		while(!mx.empty() && a[i]>=a[mx.back()]) mx.pop_back();
		while(!mn.empty() && i-mn.front()>=m) mn.pop_front();
		while(!mn.empty() && a[i]<=a[mn.back()]) mn.pop_back();
		mx.push_back(i);
		mn.push_back(i);
		if(i>=m-1 && a[mx.front()]-a[mn.front()]<=c){
			ok=true;
			cout << i-m+2 << "\n";
		}
	}
	if(!ok) cout << "NONE";

	return 0;
}

