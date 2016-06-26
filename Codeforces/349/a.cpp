#include <iostream>
#include <string>
#include <set>

using namespace std;

bool dp[10010][2];
set<string> ans;

int main()
{
    freopen("in", "r", stdin);
	string s;
	cin >> s;
	int n = s.length();
	for (int i = n - 1; i >= 5; --i)
	{
		if (i + 2 <= n)
		{
			if (i + 2 == n || dp[i + 2][1] || (dp[i + 2][0] && s.substr(i + 2, 2) != s.substr(i, 2)))
			{
				dp[i][0] = true;
				ans.insert(s.substr(i, 2));
			}
		}
		if (i + 3 <= n)
		{
			if (i + 3 == n || dp[i + 3][0] || (dp[i + 3][1] && s.substr(i + 3, 3) != s.substr(i, 3)))
			{
				dp[i][1] = true;
				ans.insert(s.substr(i, 3));
			}
		}
	}
	cout << ans.size() << endl;
	for (const string &t: ans)
		cout << t << endl;
	return 0;
}
