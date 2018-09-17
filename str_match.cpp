

#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<set>
#include<sstream>
#include<cstring>
#include <iomanip>
using namespace std;


/*
input: 
	string s,p;
1. '.'match one char
2. '*'mean zero or more of before char

output:
	whethear str,pattern are matched.

algorithm:(dp)

dp[i][j]:
	i :length of pattern
	j :length of str
dp=((p[i - 1] == '.' || p[i - 1] == s[j - 1]) && dp[i - 1][j - 1])||
 (p[i - 1] == '*' && (dp[i - 2][j] || ((p[i - 2] == '.' || p[i - 2] == s[j - 1]) && dp[i][j - 1])))
*/
bool isMatch(string s, string p) {

	int ns = s.size();
	int np = p.size();
	if (ns < 1 || np < 1)return false;
	vector<vector<int> > dp(np + 1, vector<int>(ns + 1, false));
	dp[0][0] = 1;
	if (p[0] == '*')dp[1][0] = 1;
	for (int i = 2; i < np + 1; i++)
	{
		if (p[i - 1] == '*'&&dp[i - 2][0])
			dp[i][0] = 1;
	}
	for (int i = 1; i < np + 1; i++)
	{
		for (int j = 1; j < ns + 1; j++)
		{
			bool tmp = 0;
			if ((p[i - 1] == '.' || p[i - 1] == s[j - 1]) && dp[i - 1][j - 1]) {
				dp[i][j] = 1;
				continue;
			}
			else if (i > 1) {
				if (p[i - 1] == '*' && (dp[i - 2][j] || ((p[i - 2] == '.' || p[i - 2] == s[j - 1]) && dp[i][j - 1])))
					dp[i][j] = 1;
			}

		}
		
	}
	return dp[np][ns];
}

int main() {
	string a, b;
	cin >> a >> b;
	int result= isMatch(a, b);
	cout << result << endl;
	return 0;
}

