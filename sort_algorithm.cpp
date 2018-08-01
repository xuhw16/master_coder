#include<iostream>
#include<vector>
using namespace std;
/*
input:  n //size of sorted numbers
		[x1,x2,x3..xn]//vector to be sort 
sort algorithm:
		bubble sort: o(n^2),stable sort.

*/
void bubble_sort( vector<int>&result) {
	int nums = result.size();
	for (int i = 0; i < nums - 1; i++) {
		for (int j = 0; j < nums - i-1; j++) {
			if (result[j] > result[j + 1])
				swap(result[j],result[j + 1]);
		}
	}

}

int main() {
	//input
	int n=0;
	cin >> n;
	vector<int>result(n,0);
	for (int i = 0; i < result.size(); i++)
		cin >> result[i];

	bubble_sort(result);

	//output
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
	return 0;
}