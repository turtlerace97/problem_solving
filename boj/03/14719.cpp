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
vector<int> height;
bool cmp(int a, int b) {
	return height[a] > height[b];
}
void solve()
{
	int h, w; cin >> h >> w;
	vector<vector<int>>v(h, vector<int>(w,0));
	height = vector<int> (w+1);
	int start = -1;
	for (int i = 0; i < w; i++) {
		cin >> height[i];
		if (height[i] > 0 && start == -1) start = i;
		for (int j = 0; j < height[i];j++) {
			v[j][i] = 1;
		}
	}
	
	int trend = -1;
	vector<int> pos;
	for (start; start < w; start++) {
		if (height[start] <= height[start + 1]) continue;
		else {
			break;
		}
	}
	pos.push_back(start);
	for (int i = start; i < w; i++) {

		if (trend == -1) {
			if (height[i] >= height[i + 1]) continue;
			else {
				trend *= -1;
			}
		}
		else {
			if (height[i] <= height[i + 1]) continue;
			else {
				trend *= -1;
				pos.push_back(i);
			}
		}
	}

	sort(pos.begin(), pos.end(), cmp);
	
	for (int i = 0; i < pos.size()-1; i++) {
		int lo = pos[i+1]; int hi = pos[i];
		
		int mh = min(height[lo], height[hi]);
		int a = min(lo, hi); int b = max(lo, hi);
		for (int j = 0; j < mh; j++) {
			for (int k = a; k <=b; k++) {
				if (v[j][k] == 0) {
					v[j][k] = 2;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			
			if (v[i][j] == 2) ans++;
		}
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


