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
prime number;
input: n 
output: whether n is a prime number;

algorthm:
 1.naive(O(n) or O(sqrt(n)));
*/

bool naive_1(int n)
{
	int res = true;
	for (int i = 2; i < n; i++)
	{
		if (!(n % 2)) {
			res = false;
			break;
		}
	}
	return res;
}

bool naive_2(int n)
{
	bool res = true;
	for (int i = 2; i*i <= n; i++)
	{
		if (!(n%i))
		{
			res = false;
			break;
		}
	}
	return res;
}

int main() {
	bool result = false;
	int input=0;
	cin >> input;
	//result=naive_1(input);
	result = naive_2(input);
	cout << result << endl;
	return 0;
}

