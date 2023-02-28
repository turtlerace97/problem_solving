/*
*   Time :
*   Subject : 완탐
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

int mn;
int mx;
vector<int> v;
int n;
const int inf = 1e9;
void dfs(int idx, vector<int> cnt, int cur)
{
	if (idx == n-1) {
		mn = min(mn, cur);
		mx = max(mx, cur);
		return;
	}
	int temp = cur;
	
	for (int i = 0; i < 4; i++) 
	{
		if (cnt[i])
		{
			cnt[i]--;
			switch (i)
			{
			case 0: // +
				cur += v[idx + 1];
				dfs(idx + 1, cnt, cur);
				cur = temp;
				break;
			case 1: // -
				cur -= v[idx + 1];
				dfs(idx + 1, cnt, cur);
				cur = temp;
				break;
			case 2: // * 
				cur *= v[idx + 1];
				dfs(idx + 1, cnt, cur);
				cur = temp;
				break;
			case 3: // /
				cur /= v[idx + 1];
				dfs(idx + 1, cnt, cur);
				cur = temp;
				break;
			}
			
			cnt[i]++;
		}
	}
}

void solve()
{
	mn = inf; mx = -inf;

	cin >> n;
	vector<int> cnt(4, 0);
	v = vector<int>(n);
	for (auto& u : v) cin >> u;
	
	for (int i = 0; i < 4; i++) cin >> cnt[i];
	dfs(0, cnt, v[0]);
	
	cout << mx << "\n" << mn << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


