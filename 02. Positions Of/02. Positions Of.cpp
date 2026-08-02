#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void readMatrix(vector<vector<int>>& matrix, pair <unsigned int, unsigned int>& dimensions) {
	cin >> dimensions.first >> dimensions.second;
	matrix.resize(dimensions.first, vector <int>(dimensions.second, 0));

	for (unsigned int rows = 0; rows < dimensions.first; rows++) {
		for (unsigned int collums = 0; collums < dimensions.second; collums++) {
			cin >> matrix[rows][collums];
		}
	}
}

void findNumber(const vector<vector<int>>& matrix, const int& wantedNumber) {
	bool isFound = false;
	for (vector<vector<int>>::size_type rows = 0; rows < matrix.size(); rows++) {
		for (vector<int>::size_type collums = 0; collums < matrix[rows].size(); collums++) {
			if (matrix[rows][collums] == wantedNumber) {
				cout << rows << ' ' << collums << endl;
				isFound = true;
			}
		}
	}
	if (!isFound) {
		cout << "not found";
	}
}

int main()
{
	vector<vector<int>>matrix;
	pair <unsigned int, unsigned int> dimensions;
	readMatrix(matrix, dimensions);
	int wantedNumber;
	cin >> wantedNumber;

	findNumber(matrix, wantedNumber);
}