#include<iostream>
#include<vector>
using namespace std;
/*
	1   2   3   4
	5   6   7   8 
	9  10  11  12
	13 14  15  16
	counterclock  print matrixs.
	left_top to right_top->right_top to right_bottom->
	->right_bottom to left_bottom->left_bottom to left_top
*/
void print(vector<vector<int>>& mat, int start, vector<int>&result) {
	int rows = mat.size();
	int cols = mat[0].size();
	int endx = cols - 1 - start;
	int endy = rows - 1 - start;
	//left_top to right_top
	for (int i = start; i <= endx; i++)
		result.push_back(mat[start][i]);
    //right_top to right_bottom 
	//at least 2 cols
	if (endy > start) {
		for (int i = start + 1; i <= endy; i++)
			result.push_back(mat[i][endx]);
	}
	//right_bottom to left_bottom
	//at least 2 cols 2 rows
	if (endx > start  && endy > start) {
		for (int i = endx - 1; i >= start; i--)
			result.push_back(mat[endy][i]);
	}
	//left_bottom to left_top
	//at least 2 cols 3 rows
	if (endy > start + 1 && endx > start) {
		for (int i = endy - 1; i >= start+1; i--)
			result.push_back(mat[i][start]);
	}

}

int main() {
	vector<vector<int>> mat(4, vector<int>(4, 0));
	//input 
	for (int i = 0; i < mat.size(); i++) {
		for (int j = 0; j < mat[0].size(); j++) {
			cin >> mat[i][j];
		}
	}

	int start = 0;
	vector<int> res;
	while (2 * start < mat.size() && 2 * start < mat[0].size()) {
		print(mat, start++, res);
	}

	//output
	for (int i = 0; i < res.size(); i++) {
			cout <<res[i]<<" ";
	}
	system("pause");
}
