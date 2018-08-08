#include<iostream>
#include<vector>
using namespace std;
/*
input:  n //size of  numbers
[x1,x2,x3..xn]//vector to be sum
divide and conquer algorithm:O(nlog(n))

*/
int max_array_cross(vector<int>& result, int left, int mid, int right) {
	int left_max = -2147483647;
	int right_max = -2147483647;
	int sum = 0;
	for (int i = mid; i >= left; i--) {
		sum += result[i];
		if (sum > left_max) {
			left_max = sum;
		}
	}
	sum = 0;
	for (int i = mid+1; i <=right; i++) {
		sum += result[i];
		if (sum > right_max) {
			right_max = sum;
		}
	}
	return left_max + right_max;
}

int max_array(vector<int>& result, int left, int right) {
	if (left == right)return result[left];
	int mid = (left+right)/2;
	int left_re = max_array(result, left, mid);
	int right_re = max_array(result,  mid+1,right);
	int cross_re = max_array_cross(result, left, mid, right);
	if (left_re >= right_re&&left_re >= cross_re)return left_re;
	else if (right_re >= left_re&&right_re >= cross_re)return right_re;
	else return cross_re;	
}
int main() {
	//input
	int n = 0;
	cin >> n;
	vector<int>result(n, 0);
	for (int i = 0; i < result.size(); i++)
		cin >> result[i];
	int res=max_array(result, 0, result.size() - 1);

	//output
	cout << res<< " ";
	return 0;
}