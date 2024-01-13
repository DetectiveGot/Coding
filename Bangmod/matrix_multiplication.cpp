#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1001;
int a[N][N], b[N][N], tmp[N][N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n=0,m=0;
	string s; cin >> s;
	int sz=s.size();
	int i=0;
	for(i=0;i<sz;i++){
		if(s[i]=='|') break;
		n=n*10+s[i]-'0';
	}
	for(i=i+1;i<sz;i++) m=m*10+s[i]-'0';
	int j=0,cc=0;
	char c;
	while(cin >> c && c!=';'){
		if(c>='0' && c<='9') a[j][cc]=a[j][cc]*10+c-'0';
		else if(c==',') ++cc;
		else if(c=='|') ++j,cc=0;
	}
	cin >> s;
	sz=s.size();
	i=0;
	int n2=0,m2=0;
	for(i=0;i<sz;i++){
		if(s[i]=='|') break;
		n2=n2*10+s[i]-'0';
	}
	for(i=i+1;i<sz;i++) m2=m2*10+s[i]-'0';
	j=0,cc=0;
	while(cin >> c && c!=';'){
		if(c>='0' && c<='9') b[j][cc]=b[j][cc]*10+c-'0';
		else if(c==',') ++cc;
		else if(c=='|') ++j,cc=0;
	}
//	deb(n), deb(m) << endl;
//	deb(n2), deb(m2) << endl;
//	for(int ro=0;ro<n2;ro++){
//		for(int co=0;co<m2;co++){
//			cout << b[ro][co] << " ";
//		}
//		cout << endl;
//	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m2;j++){
			tmp[i][j]=0;
			for(int k=0;k<n2;k++){
				tmp[i][j]+=a[i][k]*b[k][j];
			}
			cout << tmp[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}
/*
3|5
2, 9, 3, 2, 6, |6, 5, 9, 10, 5, |9, 10, 7, 2, 9, |;
5|3
3, 4, 8, |10, 3, 4, |9, 10, 9, |8, 9, 3, |9, 7, 7, |;
*/
