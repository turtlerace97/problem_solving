/*
*   Time :
*   Subject : greedy
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

void solve()
{
	int n, k; cin >> n >> k;
	vector<int> v(k);
	vector<int> tap(n);
	map<int, bool> used;
	for (int& x : v) {
		cin >> x;
		used[x] = false;
	}
	int ans = 0;
	for (int i = 0; i < k; i++) {

		if (used[v[i]]) continue;
		int idx = -1;
		for (int j = 0; j < n; j++)
		{
			if (tap[j] == 0) {
				idx = j;
				break;
			}
		}
		if (idx != -1) {
			tap[idx] = v[i];
			used[v[i]] = true;
			continue;
		}

		
		
		idx = -1; 
		int last_idx = -1;

		for (int j = 0; j < n; j++) {
			//tap[j]
			int tar = -1;
			for (int l = i+1; l < k; l++) {
				if (tap[j] == v[l]) {
					tar = l;
					break;
				}
			}
			if (tar == -1) tar = k;
			if (tar > last_idx) {
				last_idx = tar;
				idx = j;
			}
		}
		
		used[tap[idx]] = false;
		tap[idx] = v[i];
		used[v[i]] = true;

		ans++;
	}

	cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


