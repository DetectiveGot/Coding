#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+1;
struct DATA{
	int x,y,r;
};
vector<DATA> ask;
vector<pii> gob;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int g,x,y,r; cin >> g;
	for(int i=0;i<g;i++){
		cin >> x >> y;
		gob.emplace_back(x,y);
	}
	int m; cin >> m;
	while(m--){
		cin >> x >> y >> r;
		ask.push_back({x,y,r});
	}
	for(auto &e:gob){
		for(auto &q:ask){
			int cx=e.first-q.x, cy=e.second-q.y;
			cx*=cx, cy*=cy;
			if(cx+cy<=q.r*q.r){
				--g;
				break;
			}
		}
	}
	cout << g;

	return 0;
}

