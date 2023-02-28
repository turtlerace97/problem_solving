/*
*   Time :
*   Subject : SP
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
const int inf = 1e9 + 7;
vector<pii> adj[maxn];
struct compare {
	bool operator()(pii a, pii b) {
		return a.second > b.second;
	}
};
void solve()
{
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({ v,w});
	}

	int st, ed; cin >> st >> ed;

	priority_queue<pii, vector<pii>, compare> pq;
	pq.push({ st,0 });
	vector<int> dist(n + 1, inf);
	
	while (!pq.empty()) {
		
		int v = pq.top().first;
		int cw = pq.top().second;
		pq.pop();
		

		if (dist[v] < cw) continue;
		
		for (auto nxt : adj[v]) {
			int nv = nxt.first;
			int nw = nxt.second;
			
			if (cw + nw < dist[nv]) {
				dist[nv] = cw + nw;
				pq.push({ nv,dist[nv] });
			}
		}
	}
	
	cout << dist[ed] << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


