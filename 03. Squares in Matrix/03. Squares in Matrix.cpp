#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void readMatrix(vector<vector<char>>& matrix, pair <unsigned int, unsigned int>& dimensions) {
	cin >> dimensions.first >> dimensions.second;
	matrix.resize(dimensions.first, vector <char>(dimensions.second, 0));

	for (unsigned int rows = 0; rows < dimensions.first; rows++) {
		for (unsigned int collums = 0; collums < dimensions.second; collums++) {
			char a;
			cin >> a;
			matrix[rows][collums] = a;
		}
	}
}
int main()
{
	vector<vector<char>>matrix;
	pair <unsigned int, unsigned int> dimensions;
	readMatrix(matrix, dimensions);

	unsigned int count = 0;

	for (vector<vector<char>>::size_type rows = 1; rows < matrix.size(); rows++) {
		for (vector<char>::size_type collums = 1; collums < matrix[rows].size(); collums++) {
			if (matrix[rows][collums] == matrix[rows][collums - 1] and matrix[rows][collums] == matrix[rows - 1][collums] and matrix[rows - 1][collums] == matrix[rows - 1][collums - 1]) {
				count++;
			}
		}
	}

	cout << count;
	return 0;
}