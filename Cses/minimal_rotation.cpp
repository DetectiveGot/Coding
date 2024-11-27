#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4.2,avx,avx2,fma")
#include<iostream>
#include<utility>
#include<tuple>
#include<vector>
#include<algorithm>
#define pii pair<int,int>
#define tpi tuple<int,int,int>
 
using namespace std;

const int mxN = 1e6+5;
int fq[mxN];
 
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin >> s;
    const int n = s.size();
    vector<tpi> suf, nar(n);
    vector<int> cls(n);
    for(int i = 0; i < n; i++) suf.emplace_back(s[i] - 'a', 0, i);
    sort(suf.begin(), suf.end());
    for(int i = 1; i < n; i++){
        auto [cl, cr, np] = suf[i];
        auto [pl, pr, pp] = suf[i-1];
        cls[np] = cls[pp] + ((cl > pl) || (cl == pl && cr > pr));
	}
	vector<int> new_cls(n);
    for(int i = 1; i < n; i <<= 1){
        for(auto &[lh, rh, p] : suf){
            lh = cls[p];
            rh = cls[(p + i)%n];
        }
        int mx = 0;

        for(auto &[l, r, p] : suf) mx = max(mx, r);
        fill(fq, fq+mx+1, 0);
        for(auto &[l, r, p] : suf) fq[r]++;
        for (int j = 1; j <= mx; ++j) fq[j] += fq[j - 1];
        for(int i = n - 1; i >= 0; --i) nar[--fq[get<1>(suf[i])]] = suf[i];
        swap(suf, nar);
        mx = 0;
        
        for(auto &[l, r, p] : suf) mx = max(mx, l);
        fill(fq, fq+mx+1, 0);
        for(auto &[l, r, p] : suf) fq[l]++;
        for (int j = 1; j <= mx; ++j) fq[j] += fq[j - 1];
        for(int i = n - 1; i >= 0; --i) nar[--fq[get<0>(suf[i])]] = suf[i];
        swap(suf, nar);
        for(int i = 1; i < n; i++){
            auto [cl, cr, np] = suf[i];
            auto [pl, pr, pp] = suf[i-1];
            new_cls[np] = new_cls[pp] + ((cl > pl) || (cl == pl && cr > pr));
            if(i==1 && new_cls[np]==1){
                s=s+s;
                cout << s.substr(pp, n);
                return 0;
            }
        }
        swap(cls, new_cls);
    }
    s = s + s;
    cout << s.substr(get<2>(suf[0]), n) << "\n";
 
    return 0;
}