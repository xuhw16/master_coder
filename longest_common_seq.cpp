#include <iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


int main()
{
	string a, b;
	cin >> a >> b;
	int n = a.size(), m = b.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1,0));
	vector<vector<int>> dire(n + 1, vector<int>(m + 1,-1));
	for (int i = 1;i < n + 1;i++)
	{
		for (int j = 1;j < m + 1;j++)
		{
			
			if (a[i - 1] == b[j - 1] && dp[i][j] < dp[i - 1][j - 1] + 1)
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				dire[i][j] = 0;
			}
			if (dp[i][j] < dp[i - 1][j])
			{
				dp[i][j] = dp[i - 1][j];
				dire[i][j] = 1;
			}
			if (dp[i][j] < dp[i][j-1])
			{
				dp[i][j] = dp[i][j-1];
				dire[i][j] = 2;
			}
		}
	}
	string  res;
	int i = n, j = m;
	while (i > 0 && j > 0)
	{
		int tmp = dire[i][j];
		if (tmp == 0)
		{
			res.push_back(a[i-1]);
			i--;
			j--;
		}
		if (tmp == 1)
			i--;
		if (tmp == 2)
			j--;
	}
	reverse(begin(res),end(res));
	cout << res << endl;
	return 0;
}