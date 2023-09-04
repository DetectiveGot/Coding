#include <bits/stdc++.h>

#ifdef  nuclear
   #include  "Nuclear.h"
#else
     using namespace std;
     #define debug(...) 42
#endif     

 #include <ext/pb_ds/assoc_container.hpp>
 #include <ext/pb_ds/tree_policy.hpp>
 using namespace __gnu_pbds;
 using ordered_set = tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>;
 

#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define allr(x)           (x).rbegin(),(x).rend()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define vi                vector<int>
#define vii               vector<pii>
#define mi                map<int,int>
#define mii               map<pii,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define el                '\n' 
#define inputa(arg)       for (auto& e : arg) cin >> e
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int lg(long long x){ return __builtin_clzll(1ll) - __builtin_clzll(x) +1ll; }
void google() { static int _gtest_ = 1; cout << "Case #" << _gtest_++ << ": "; }
const int mod=1e9+7;
//const int mod2=998244353; 
 
    
int dp[1005][1005][2];
int val[1005][1005];
int n,m;

 int ans=0;

bool valid(int i,int j){

      if(i>n||j>m||val[i][j])
        return false;
      else
        return true;
}

void pre(int i,int j){
   

    rep(i,1,n+1){

          rep(j,1,m+1){

              ans+=dp[i-1][j][1]+dp[i][j-1][0]+1;
              
              dp[i][j][0]=dp[i-1][j][1]+1;
              dp[i][j][1]=dp[i][j-1][0]+1;
          }
    }

}

void calc(int i ,int j, int k, int cnt, int dx ,int dy){

        while(valid(i+dx,j+dy)){

              ans+=cnt;
              
               dp[i+dx][j+dy][k]+=cnt;
    
               i+=dx;
               j+=dy;
                dx^=1;
                dy^=1;
                k^=1;
        }
}


void solve(){  
         
         int q;
       cin>>n>>m>>q;  


     pre(1,1);
       
       while(q--){

               int i,j;
               cin>>i>>j;

              if(val[i][j]){
                  val[i][j]=0;
                   
                  ans+=dp[i-1][j][1]+dp[i][j-1][0]+1;
                  dp[i][j][0]=dp[i-1][j][1]+1;
                  dp[i][j][1]=dp[i][j-1][0]+1;


                 calc(i,j,0,dp[i][j][1],1,0);
                 calc(i,j,1,dp[i][j][0],0,1);

              }
              else{
                  val[i][j]=1;

                  ans-=dp[i-1][j][1]+dp[i][j-1][0]+1;
                  dp[i][j][0]=0;
                  dp[i][j][1]=0;


                 calc(i,j,0,-(dp[i][j-1][0]+1),1,0);
                 calc(i,j,1,-(dp[i-1][j][1]+1),0,1);
              }
           cout<<ans<<el;
       } 
 
         
}
    

signed main(){   

    
    #ifdef nuclear
      freopen("Error.txt", "w", stderr);
    #endif 

     ios_base::sync_with_stdio(false);
     cin.tie(0); cout.tie(0);
  
   int t=1;

   //cin>>t;

   while(t--)solve();
   return 0;
}
