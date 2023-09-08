#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int N = 100005;

int n, k, q, x;
int e[N], dist[N];
priority_queue<pii> pq;
vector<int> adj[N];

int main()
{
    scanf("%d %d %d %d", &n, &k, &q, &x);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &e[i]);
    }

    int a, b;
    for (int i = 0; i < k; i++)
    {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
    }

    // fill(dist, dist + n + 1, INT_MAX);
    for (int i = 0; i <= n; i++) dist[i] = INT_MAX;
    dist[x] = e[x];
    pq.push({dist[x], x});

    while (not pq.empty())
    {
        int now = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (dist[now] < w)
            continue;

        for (auto child : adj[now])
        {
            int nx = child;

            if (dist[nx] > dist[now] + e[nx])
            {
                dist[nx] = dist[now] + e[nx];
                pq.push({dist[nx], nx});
            }
        }
    }

    while (q--)
    {
        scanf("%d", &a);
        printf("ans: %d\n", dist[a]);
    }

    return 0;
}
