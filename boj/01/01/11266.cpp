
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


#define UNVISITED 0
#define EXPLORED 1

const int VERTEX = 1e6 + 1;
vector<int> adj[VERTEX];

int dfs_num[VERTEX];
int dfs_low[VERTEX];
int dfs_par[VERTEX];
bool articulation_vertex[VERTEX];
set<pii> articulation_edge;

int cnt = 1; // dfs 방문 순서 

int dfsRoot;
int rootChildren;

// 절단점 : dfs_low[u] >= dfs_num[v] ( v : cur, u : nxt )
// 절단선 : dfs_low[u] > dfs_num[v] ( v : cur, u : nxt )


void CutVertex(int v)
{
	dfs_low[v] = dfs_num[v] = cnt++;
	for (auto nv : adj[v])
	{
		if (dfs_num[nv] == UNVISITED)
		{
			dfs_par[nv] = v;
			if (v == dfsRoot) rootChildren++;

			CutVertex(nv);
			if (dfs_low[nv] >= dfs_num[v]) articulation_vertex[v] = true;
			if (dfs_low[nv] > dfs_num[v])
			{
				int x, y; x = v; y = nv;
				if (x > y) swap(x, y);
				articulation_edge.insert({ x,y });
			}
			dfs_low[v] = min(dfs_low[v], dfs_low[nv]);
		}
		else if (nv != dfs_par[v])
		{
			dfs_low[v] = min(dfs_low[v], dfs_num[nv]);
		}
	}

}


void solve()
{
	int n,m; cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
	{
		if (dfs_num[i] == UNVISITED)
		{
			dfsRoot = i;
			rootChildren = 0;
			CutVertex(i);
			articulation_vertex[dfsRoot] = (rootChildren > 1);
		}
	}
	cout << articulation_edge.size() << "\n";
	for (auto u : articulation_edge)
	{
		cout << u.first << " " << u.second << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


