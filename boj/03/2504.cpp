/*
*   Time :
*   Subject : 구현
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

string s;
int go(int st, int ed) {

	if (st + 1 == ed)
	{
		if (s[st] == '(') return 2;
		else return 3;
	}

	int ret = (s[st] == '(') ? 2 : 3;
	int start = st + 1;
	vector<pii> pos;
	stack<int> stk;
	for (int i = st + 1; i <= ed - 1; i++)
	{
		if (s[i] == '(' or s[i] == '[') stk.push(s[i]);
		else {
			stk.pop();
			if (stk.empty()) {
				pos.push_back({ start,i });
				start = i + 1;
			}
		}	
	}
	int temp = 0;
	for (auto u : pos) {
		temp += go(u.first, u.second);
	}
	return temp * ret;

}
void solve()
{
	cin >> s;
	vector<pii> pos;
	stack<char> stk;
	int start = 0;
	for(int i =0;i<s.size();i++)
	{
		
		if (s[i] == '(' or s[i] == '[') stk.push(s[i]);
		else {
			if (s[i] == ')')
			{
				if (stk.empty() or stk.top() == '[')
				{
					
					cout << "0\n";
					return;
				}
				else {
					stk.pop();
				}
			}
			else
			{
				if (stk.empty() or stk.top() == '(') {
					cout << "0\n";
					return;
				}
				else {
					stk.pop();
				}
			}
			if (stk.empty()) {
				pos.push_back({ start,i });
				start = i + 1;
			}
		}
	}

	int ans = 0;
	for (auto u : pos) {
		ans += go(u.first, u.second);
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


