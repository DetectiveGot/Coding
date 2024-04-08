#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+1;
ll qs[N];
int n;
vector<ll> v;
struct Node {
	ll val;
	Node *l, *r;
	Node() : val(0), l(nullptr), r(nullptr) {
		l=this;
		r=this;
	}
	Node(ll x): val(x), l(nullptr), r(nullptr) {}
	Node(Node *lt, Node *rt): val(0), l(lt), r(rt) {}
};

Node *build(int l=1, int r=n) {
	if(l==r) return new Node(0);
	int mid = (l+r)/2;
	return new Node(build(l, mid), build(mid+1, r));
}
/*
Node *upd(Node *node, int val, int pos, int l=1, int r=n) {
	if(l==r) return new Node(val);
	int mid = (l+r)/2;
	if(pos<=mid) return new Node(upd(node->l, val, pos, l, mid), node->r);
	else return new Node(node->l, upd(node->r, val, pos, mid+1, r));
}

ll qry(Node *node, int ql, int qr, int l=1, int r=n) {
	if(l>qr || r<ql) return 0;
	if(l>=ql && r<=qr) return node->val;
	int mid = (l+r)/2;
	return qry(node->l, ql, qr, l, mid) + qry(node->r, ql, qr, mid+1, r);
}
*/
Node *upd(Node *node, ll v, int p, int l, int r) {
	if(l==r) return new Node(v);
	int m=(l+r)/2;
	if(p>m) return new Node(node->l, upd(node->r,v,p,m+1,r));
	else    return new Node(upd(node->l,v,p,l,m), node->r);
}

ll qry(Node *node, int a, int b, int l, int r) {
	if(l>b || r<a) return 0;
	if(l>=a && r<=b) return node->val;
	int m=(l+r)/2;
	return qry(node->l,a,b,l,m)+qry(node->r,a,b,m+1,r);
}

Node *root[N<<2];

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	int k;
	cin >> n >> k;
	for(int i=1; i<=n; i++) {
		cin >> qs[i];
		qs[i]+=qs[i-1];
		v.push_back(qs[i]);
	}
	v.push_back(0);
	sort(v.begin(), v.end());
	root[0] = new Node();//build(1, n+1);
	int x = lower_bound(v.begin(), v.end(), 0)-v.begin()+1;
	root[1]=upd(root[0], 1, x, 1, n+1);
	for(int i=1; i<=n; i++) {
		int pos = lower_bound(v.begin(), v.end(), qs[i])-v.begin()+1;
		root[i+1]=upd(root[i], 1, pos, 1, n+1);
		cout<<pos<<"  pos\n";
	}
	ll ans=0;
	for(int i=1; i<=n; i++) {
		int idx = upper_bound(v.begin(), v.end(), qs[i]-k)-v.begin();
		ans+=qry(root[n], 1, idx, 1, n+1);
		deb(ans) << endl;
	}
	cout << ans;

	return 0;
}
