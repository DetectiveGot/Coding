#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ":" << x << "] "

using namespace std;

bool ch[10];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	string s; cin >> s;
	int n=s.size();
	ll sl=0, sr=0, ss=0, srr=0;
	bool ok = false;
	for(auto &e:s) ch[e-'0']=1 ,ss=ss*10+e-'0';
	for(int i=0;i<10;i++) if(!ch[i]) ok=true;
	if(!ok){
		cout << "Impossible";
		return 0;
	}
	
	for(int i=s[0]-'0'-1;i>0;--i){
		if(!ch[i]){
			sl=sl*10+i;
			break;
		}
	}
	for(int i=1;i<n;i++){
		for(int j=9;j>=0;--j){
			if(!ch[j]){
				sl=sl*10+j;
				break;
			}
		}
	}
	for(int i=s[0]-'0'+1;i<=9;++i){
		if(!ch[i]){
			sr=sr*10+i;
			break;
		}
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<=9;++j){
			if(!ch[j]){
				sr=sr*10+j;
				break;
			}
		}
	}
	for(int i=1;i<=9;i++){
		if(!ch[i]){
			srr=i;
			break;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<=9;j++){
			if(!ch[j]){
				srr=srr*10+j;
				break;
			}
		}
	}
	ll d1=abs(ss-sl), d2=min(abs(sr-ss), abs(srr-ss));
	if(abs(sr-ss)>abs(srr-ss)) sr=srr;
	if(d1==d2 && sl!=sr) cout << sl << " " << sr;
	else if(d1<d2) cout << sl;
	else cout << sr;
	
	cerr << endl;
	deb(sl), deb(sr), deb(srr);
	
	return 0;
}
