#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pii pair<int,int>
#define tpi tuple<int,int,int>
#define siz(x) (int)(x.size())
#define deb(x) cerr << "[" << #x << ": " << x << "]"

using namespace std;
using namespace __gnu_pbds;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//use schedule

const int N = 1e5+2, inf = 1e9;
ll sg[N<<2], lz[N<<2];

void psh(int i, int l, int r){
    sg[i]+=lz[i];
    if(l<r){
        lz[i<<1]+=lz[i];
        lz[i<<1|1]+=lz[i];
    }
    lz[i]=0;
}

void upd(int i, ll x, int l, int r, int ql, int qr){
    psh(i, l, r);
    if(l>qr || r<ql) return;
    if(l>=ql && r<=qr){
        lz[i]+=x;
        psh(i, l, r);
        return;
    }
    int m = l+r>>1;
    upd(i<<1, x, l, m, ql, qr);
    upd(i<<1|1, x, m+1, r, ql, qr);
    sg[i]=min(sg[i<<1], sg[i<<1|1]);
}

int qry(int i, int l, int r, int ql, int qr){
    psh(i, l, r);
    if(l>qr || r<ql) return inf;
    if(l>=ql && r<=qr) return sg[i];
    int m = l+r>>1;
    return min(qry(i<<1, l, m, ql, qr), qry(i<<1|1, m+1, r, ql, qr));
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,q; cin >> n >> q;
    int x, y, cmd;
    while(q--){
        cin >> cmd;
        if(cmd==1){
            cin >> x >> y;
            ++x;
            upd(1, 1, 1, n, x, y);
        } else if(cmd==2){
            cin >> x;
            ++x;
            int l=x, r=n;
            while(l<r){
                int m = l+r>>1, val = qry(1, 1, n, x, m);
                assert(val>=0);
                if(val>0) l = m+1;
                else r = m;
            }
            cout << l-1 << "\n";
        } else {
            cin >> x >> y;
            ++x;
            upd(1, -1, 1, n, x, y);
        }
    }

    return 0;
}