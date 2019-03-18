#include<iostream>
#include<vector>
#define INT_MAX_ 2147438647
using namespace std;

int matrix_chain_order(vector<int> p)
{
	int n = p.size()-1;
	vector<vector<int>> s(n, vector<int>(n, 0)), m(n, vector<int>(n, INT_MAX_));
	for (int i = 0;i < n;i++)
		m[i][i] = 0;
	for (int l = 2;l <= n;l++)
	{
		for (int i = 0;i < n - l + 1;i++)
		{
			int j = i + l - 1;
			for (int k = i;k < j;k++)
			{
				int tmp = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
				if (tmp < m[i][j])
				{
					m[i][j] = tmp;
					s[i][j] = k;
				}
			}
		}
	}
	return m[0][n - 1];
}

int main()
{
	vector<int> p = {10,100,5,50};
	cout << matrix_chain_order(p) << endl;
	return 0;
}