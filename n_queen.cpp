#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
/*
n queen questions:
input: n 
output: the numbers of solutions.

solution1:
	iteratives
*/

using namespace std;
bool in_queen(vector<int>&tmp, int i,int j)
{
	bool result = true;
	for (int k = 0; k < i; k++)
	{
		int a = tmp[k];
		if (a == j || abs(i - k) == abs(j - tmp[k]))
			result = false;
	}
	return result;
}

void find_queen(vector<vector<int>> &res, vector<int> tmp, int n,int i)
{
	if (i >= n) {
		res.push_back(tmp);
		return;
	}
	for (int k = 0; k < n; k++)
	{
		if (in_queen(tmp, i, k))
		{
			tmp[i] = k;
			find_queen(res, tmp, n, i+1);
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> res;
	vector<int>tmp(n,0);
	find_queen(res, tmp,n,0);
	cout << res.size()<<endl;
	return 0;
}

