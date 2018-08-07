#include<iostream>
#include<vector>
using namespace std;
/*
input:  n //size of sorted numbers
[x1,x2,x3..xn]//vector to be sort
sort algorithm:
bubble sort: o(n^2),stable sort.
insert sort: o(n^2),stable sort.
merge sort:o(nlog(n)),distable sort.
*/
//bubble sort
void bubble_sort(vector<int>&result) {
	int nums = result.size();
	for (int i = 0; i < nums - 1; i++) {
		for (int j = 0; j < nums - i - 1; j++) {
			if (result[j] > result[j + 1])
				swap(result[j], result[j + 1]);
		}
	}

}

//insert sort
void insert_sort(vector<int> &result) {
	int nums = result.size();
	for (int i = 1; i < nums; i++) {
		int tmp = result[i];
		int j = i - 1;
		while (j > 0 && tmp < result[j]) {
			result[j + 1] = result[j];
			--j;
		}
		result[j + 1] = tmp;
	}
}


//merge sort
void merge_all(vector<int>&result, vector<int>left_re, vector<int>right_re) {
	int n = result.size();
	int l = left_re.size();
	int r = right_re.size();
	int lr = 0, lf = 0;
	for (int i = 0; i < n; i++) {	
		while (lr < r&&lf < l) {
			if (left_re[lf] <= right_re[lr]) {
				result[i] = left_re[lf];
				++lf;
				++i;
			}
			else {
				result[i] = right_re[lr];
				++lr;
				++i;
			}

		}
		while (lr < r) {
			result[i] = right_re[lr];
			++lr;
			++i;
		}
		while(lf<l){
			result[i] = left_re[lf];
			++lf;
			++i;
		}
	}
}
void merge_sort(vector<int>&result) {
	int nums = result.size();
	if (nums == 1)return;
	vector<int>left_re(result.begin(), result.begin() + nums / 2);
	vector<int>right_re(result.begin() + nums / 2,result.end());
	merge_sort(left_re);
	merge_sort(right_re);
	merge_all(result, left_re, right_re);
}

int main() {
	//input
	int n = 0;
	cin >> n;
	vector<int>result(n, 0);
	for (int i = 0; i < result.size(); i++)
		cin >> result[i];
	merge_sort(result);
	//insert_sort(result);
	//bubble_sort(result);

	//output
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
	return 0;
}