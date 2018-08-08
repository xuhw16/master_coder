#include<iostream>
#include<vector>
using namespace std;
/*
input:  n //size of sorted numbers
[x1,x2,x3..xn]//vector to be sort
sort algorithm:
bubble sort: o(n^2),stable sort.
insert sort: o(n^2),stable sort.
merge sort:o(nlog(n)),distable sort.(not in place)
heap sort:o(nlog(n)),distable sort. (in place)
quick_sort:o(nlog(n)),distable sort. (in place)
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

//heap_sort
void heap_keep(vector<int> &result, int i,int last) {
	int target = i;
	if (2 * i + 1 <= last&&result[2 * i + 1] > result[i])
		target = 2 * i + 1;
	if (2 * i + 2 <= last&&result[2 * i + 2] > result[target])
		target = 2 * i + 2;
	if (target != i) {
		swap(result[target], result[i]);
		heap_keep(result, target,last);
	}
}
void heap_create(vector<int>&result) {
	int nums = result.size();
	for (int i = nums/ 2; i >= 0; i--) {
		heap_keep(result, i,nums-1);
	}
}
void heap_sort(vector<int>&result) {
	int nums = result.size();
	heap_create(result);
	int j = nums - 1;
	for (int i = nums - 1; i >= 0; i--) {
		swap(result[0], result[j]);
		j--;
		heap_keep(result, 0,j);
	}
}

//quick_sort
int sort_partion(vector<int>&result, int left, int right) {
	int x = result[right];
	int i = left - 1;
	for (int j = left; j < right; j++) {
		if (result[j] < x) {
			i++;
			swap(result[i], result[j]);
		}
	}
	swap(result[i + 1], result[right]);
	return i + 1;
}
void quick_sort(vector<int>&result,int left,int right) {
	if (left < right) {
		int q = sort_partion(result, left, right);
		quick_sort(result, left, q - 1);
		quick_sort(result, q + 1, right);
	}
}

int main() {
	//input
	int n = 0;
	cin >> n;
	vector<int>result(n, 0);
	for (int i = 0; i < result.size(); i++)
		cin >> result[i];
	quick_sort(result,0,result.size()-1);
	//heap_sort(result);
	//merge_sort(result);
	//insert_sort(result);
	//bubble_sort(result);

	//output
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
	return 0;
}