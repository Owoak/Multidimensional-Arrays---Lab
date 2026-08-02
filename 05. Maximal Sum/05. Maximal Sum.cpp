#include <iostream>
#include <vector>
#include <numeric>
#include <climits>
#include <utility>

using namespace std;

void readVector(pair <unsigned int, unsigned int>& dimensions, vector<vector <int>>& matrix) {
	cin >> dimensions.first >> dimensions.second;
	matrix.resize(dimensions.first, vector <int>(dimensions.second, 0));

	for (unsigned int rows = 0; rows < dimensions.first; rows++) {
		for (unsigned int collums = 0; collums < dimensions.second; collums++) {
			cin >> matrix[rows][collums];
		}
	}
}

int findSum(const vector<vector <int>>::size_type& rowRange, const vector <int>::size_type& collumRange, const vector<vector <int>>& matrix) {
	int sum = 0;
	//int rEnd = static_cast<int>(rowRange) - 2;
	//int cEnd = static_cast<int>(collumRange) - 2;
	for (int row = static_cast<int>(rowRange) - 2; row <= static_cast<int>(rowRange); row++) {
		//for (int collum = static_cast<int>(collumRange); collum >= cEnd; collum--) {
		//	sum += matrix.at(row).at(collum);
		//}
		sum += accumulate(
			matrix[row].begin() + (collumRange - 2),
			matrix[row].begin() + (collumRange + 1),
			0
		);
	}
	return sum;
}

int main()
{
	pair <unsigned int, unsigned int> dimensions;
	vector<vector <int>>matrix;
	readVector(dimensions, matrix);

	int maxSum = INT_MIN;
	pair < vector<vector <int>>::size_type, vector <int>::size_type> maxCordinates;

	for (vector<vector <int>>::size_type rows = 2; rows < matrix.size(); rows++) {
		for (vector <int>::size_type collums = 2; collums < matrix[rows].size(); collums++) {
			int sum = findSum(rows, collums, matrix);
			if (sum > maxSum) {
				maxSum = sum;
				maxCordinates = { rows ,collums };
			}
		}
	}

	// print biggest 3x3 combination

	cout << "Sum = " << maxSum << endl;

	for (int rows = static_cast<int>(maxCordinates.first) - 2; rows <= maxCordinates.first; rows++) {
		for (int collums = static_cast<int>(maxCordinates.second) - 2; collums <= maxCordinates.second; collums++) {
			cout << matrix.at(rows).at(collums) << ' ';
		}
		cout << endl;
	}

	return 0;
}