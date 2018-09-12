#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
/*
union_find sets:

*/
using namespace std;


int find(vector<int>&s, int x)
{
	if (s[x] < 0)
		return x;
	else
	{
		return s[x] = find(s, s[x]);
	}

}
void union_f(vector<int> & s, int root1, int root2)
{
	if (find(s, root1) == find(s,root2))
		return;
	else
	{
		s[root2] = root1;
	}
}

int main() {
	int N,M;
	cin >> N>>M;
	vector<int> union_find(N+1, -1);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		union_f(union_find, a, b);
	}
	return 0;
}

