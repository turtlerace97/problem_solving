/*
*   Time :
*   Subject : kmp
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

vector<int> getFail(string t) {
	int m = t.size(), j = 0;
	vector<int> fail(m);

	fail[0] = 0;
	for (int i = 1; i < m; i++) {
		while (j > 0 && t[i] != t[j]) j = fail[j - 1];
		if (t[i] == t[j]) {
			fail[i] = j + 1;
			j++;
		}
	}

	return fail;
}

vector<int> kmp(string s, string t) {
	vector<int> ans;
	int n = s.size(), m = t.size();

	vector<int> fail = getFail(t);
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != t[j]) j = fail[j - 1];
		if (s[i] == t[j]) {
			if (j == m - 1) {
				ans.push_back(i - m+1);
				j = fail[j];
			}
			else j++;
		}
	}
	return ans;

}

void solve()
{
	string s, t; 
	getline(cin, s);
	getline(cin, t);

	vector<int> ans = kmp(s, t);
	cout << ans.size() << "\n";
	for (auto u : ans) {
		cout << u+1 << "\n";
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


