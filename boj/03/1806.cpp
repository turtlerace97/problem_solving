/*
*   Time :
*   Subject : two pointer
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
	int n, s; cin >> n >> s;
	vector<int> v(n);
	for (int& x : v) cin >> x;
	const int inf = 1e9 + 7;
	int l = 0, r = 0;
	int sum = v[r];
	int ans = inf;
	while (r < n and l <= r) {
		
		if (sum < s)
		{
			r++;
			if (r == n) break;
			sum += v[r];
		}
		else {
			//cout << l << " " << r << "\n";
			ans = min(ans, r - l+1);
			sum -= v[l];
			l++;
		}
		
	}
	
	if (ans == inf) cout << "0\n";
	else cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


