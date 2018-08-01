#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
KMP algorithm
input:  target string
		pattern string
output: if matched return the first index where match
		else return 0
*/

void get_next( string pattern,vector<int>&next) {
	int k = -1;
	int j = 0;
	next[0] = -1;
	while (j < next.size() - 1) {
		if (k == -1 || pattern[j] == pattern[k])
			next[++j] = ++k;
		else
			k = next[k];
	}
}

int main() {
	//input
	string target,pattern;
	cin >> target>>pattern;
	vector<int> next(pattern.size(), 0);

	get_next(pattern, next);
	int result;
	int j = 0;
	int i =0;
		while(i<target.size()&&j<static_cast<int>(pattern.size())) {
			if (j==-1||pattern[j] == target[i])
			{
				++i;
				++j;
			}
			else
				j = next[j];
		}
		if (j == pattern.size())
			cout << i - j;
		else
			cout << 0;	
		return 0;
}