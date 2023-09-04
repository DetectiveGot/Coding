#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = (1 << 19) + 10, maxlg = 20;
 
int n, m, a[maxn], seg[maxn][maxlg], lazy[maxn], low, high, val;
 
void add(const int& id, const int& left, const int& right){
	for (int i = 0; i < maxlg; i++)
		seg[id][i] = seg[left][i] + seg[right][i];
	return;
}
 
void change(const int& id, const int& l, const int& mid, const int& r, const int& left, const int& right){
	if (!lazy[id]) return;
	lazy[left] ^= lazy[id], lazy[right] ^= lazy[id];
	for (int x = lazy[id], tmp = __builtin_ctz(x); x; x -= x & -x, tmp = __builtin_ctz(x)){
		seg[left][tmp] = mid - l - seg[left][tmp];
		seg[right][tmp] = r - mid - seg[right][tmp];
	}
	lazy[id] = 0;
	return;
}
 
void build(int id = 1, int l = 0, int r = n){
	if (r - l == 1){
		for (int x = a[l]; x; x -= x & -x)
			seg[id][__builtin_ctz(x)]++;
		return;
	}
 
	int mid = (l + r) >> 1, left = id << 1, right = left | 1;
	build(left, l, mid); build(right, mid, r); add(id, left, right);
	return;
}
 
void query(int id = 1, int l = 0, int r = n){
	if (r <= low || l >= high)
		return;
	if (l >= low && r <= high){
		lazy[id] ^= val;
		for (int x = val, tmp = __builtin_ctz(x); x; x -= x & -x, tmp = __builtin_ctz(x))
			seg[id][tmp] = r - l - seg[id][tmp];
		return;
	}
 
	int mid = (l + r) >> 1, left = id << 1, right = left | 1;
	change(id, l, mid, r, left, right);
	query(left, l, mid); query(right, mid, r); add(id, left, right);
	return;
}
 
ll get(int id = 1, int l = 0, int r = n){
	if (r <= low || l >= high)
		return 0;
	if (l >= low && r <= high){
		ll ans = 0;
		for (int i = 0; i < maxlg; i++)
			ans = ans + 1ll * seg[id][i] * (1 << i);
		return ans;
	}
 
	int mid = (l + r) >> 1, left = id << 1, right = left | 1;
	change(id, l, mid, r, left, right);
	return get(left, l, mid) + get(right, mid, r);
}
 
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	build();
 
	cin >> m;
	while (m--){
		int t;
		cin >> t >> low >> high;
		low--;
 
		if (t == 1)
			cout << get() << "\n";
		else{
			cin >> val;
			query();
		}
	}
 
	return 0;
}
