/*
*   Time :
*   Subject :
*
*   Coded by soonyubing
*/

#include <bits/stdc++.h>
#define ll long long
#define pii  pair<int, int>
#define pll pair<ll, ll>
// INT_MAX INT_MIN LLONG_MAX LLONG_MIN
using namespace std;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }

const int maxn = 1111;
vector<int> adj[maxn];
bool visited[maxn];

void dfs(int v) 
{
	visited[v] = true;
	cout << v << " ";
	for (auto nv : adj[v])
	{
		if (!visited[nv])
		{
			dfs(nv);
		}
	}

}

void bfs(int x)
{
	queue<int> q;
	q.push(x);
	visited[x] = true;
	while (!q.empty())
	{
		int v = q.front(); q.pop();

		cout << v << " ";
		for (auto nv : adj[v])
		{
			if (!visited[nv])
			{
				visited[nv] = true;
				q.push(nv);
			}
		}
	}
}

void solve()
{
	int n, m, st;
	cin >> n >> m >> st;
	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
	{
		sort(adj[i].begin(), adj[i].end());
	}

	dfs(st); cout << "\n";
	memset(visited, false, sizeof(visited));
	bfs(st);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


