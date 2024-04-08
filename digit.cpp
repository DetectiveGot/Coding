#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << #x << ": " << x << " "

using namespace std;

const int N = 11, M = 101, mod = 1e9+7;
ll a[N], dp[M][11], cnt[N][M];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    int n,m,k; cin >> n >> s >> k;
    m=s.size();
    cnt[0][0]=1;
    for(int i=1;i<=s.size();i++) a[i]=s[m-i]-'0';
    for(int i=1;i<=n;i++){
        for(int d=0;d<=9;d++){
            if(d==k) continue;
            for(int j=0;j<=90;j++){
                (cnt[i][j+d]+=cnt[i-1][j])%=mod;
            }
        }
    }
    dp[0][0]=1;
    for(int i=1;i<=m;i++){
        for(int d=0;d<=9;d++){
            for(int j=0;j<=90;j++){
                if((d+j)%10!=a[i]) continue;
                (dp[i][(j+d)/10]+=dp[i-1][d]*cnt[n][j])%=mod;
            }
        }
    }
    cout << dp[m][0] << endl;
//    for(int i=1;i<=n;i++){
//        for(int j=0;j<=20;j++){
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }
    
    return 0;
}

//for each digit = each digit of m
//dp[i][j] digit i is j
