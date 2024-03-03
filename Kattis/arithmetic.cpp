#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 6e5+1;
bool b[N];

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    string s,ans=""; cin >> s;
    int n=s.size();
    for(int i=0;i<n;i++){
        int d=s[i]-'0',c=0;
        while(d){
            b[3*i+2-c]=d&1;
            ++c;
            d>>=1;
        }
    }
    for(int i=3*n;i>0;i-=4){
        int d=0;
        for(int j=max(i-4, 0);j<i;++j) d=(d<<1)+b[j];
        if(d>=10) ans+=char('A'+d-10);
        else ans+=char(d+'0');
    }
    while(ans.size()>1 && ans.back()=='0') ans.pop_back();
    reverse(ans.begin(), ans.end());
    cout << ans;

    return 0;
}
