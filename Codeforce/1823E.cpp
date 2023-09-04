//Sprague-Grundy number
//Solution (Didn't do yet)

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    vector < vector <int> > g(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int res=0, size;
    vector <int> used(n);

    function <void(int)> dfs = [&] (int v) {
        used[v] = true;
        size++;
        for (int to : g[v]) {
            if (!used[to])
                dfs(to);
        }
    };

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            size = 0;
            dfs(i);
            if (size <= l + r - 1) {
                res ^= size / l;
            }
        }
    }

    if (res)
        cout << "Alice\n";
    else
        cout << "Bob\n";

    return 0;
}
