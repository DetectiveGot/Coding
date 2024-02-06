#include<bits/stdc++.h>
#define ll long long
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e6+1, mod = 1e9+7, p = 41;
map<int, vector<int>> mp;
int a[N];

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,m; cin >> n >> m;
    int k=n;
    string s; cin >> s;
    s=s+s;
    n=s.size();
    ll hs=0, fr=1;
    for(int i=0;i<m;i++){
        hs=hs*p%mod+s[i]-'a', hs%=mod;
        fr=fr*p%mod;
    }
    mp[hs].push_back(m-1);
    for(int i=m;i<k+m-1;i++){
        hs=hs*p%mod+s[i]-'a';
        hs-=fr*(s[i-m]-'a')%mod;
        hs%=mod, hs+=mod, hs%=mod;
        mp[hs].push_back(i);
    }
    int mx=0;
    string ans="";
    for(auto &e:mp){
        int cnt=0, sz=e.second.size();
        vector<int> dp(sz);
        for(int i=0;i<sz;i++){
            int pos = e.second[i]-m+1;
            a[i]=e.second[i];
            dp[i]=1;
            for(int j=0;j<i;j++){
            	int nl=(pos%k+k)%k, nr=e.second[i]%k;
                int pl=(a[j]%k-m+1+k)%k, pr=a[j]%k;
                bool b1=(pr>pl && nr>nl && nl>pr);
                bool b2=(pr>pl && nr<nl && nr<pl);
                if(b1||b2){
                	if(dp[i]<dp[j]+1) dp[i]=dp[j]+1, a[i]=a[j];
				}
			}
            cnt=max(cnt, dp[i]);
        }
        if(mx<cnt){
            mx=cnt;
            ans=s.substr(e.second[0]-m+1, m);
        } else if(mx==cnt){
            string tmp=s.substr(e.second[0]-m+1, m);
            if(ans>tmp) ans=tmp;
        }
    }
    cout << ans << " ";
    
    return 0;
}



