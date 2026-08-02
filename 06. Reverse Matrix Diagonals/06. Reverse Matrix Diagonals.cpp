#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void readMatrix(vector <vector<int>>& matrix, pair < unsigned int, unsigned int>& dimensions) {
	cin >> dimensions.first >> dimensions.second;
	matrix.resize(dimensions.first, vector <int>(dimensions.second, 0));

	for (unsigned int rows = 0; rows < dimensions.first; rows++) {
		for (unsigned int collums = 0; collums < dimensions.second; collums++) {
			cin >> matrix.at(rows).at(collums);
		}
	}
}

int main()
{
	pair < unsigned int, unsigned int> dimensions;
	vector <vector<int>> matrix;
	readMatrix(matrix, dimensions);

	for (int rowPrint = matrix.size() - 1, collumPrint = matrix[rowPrint].size() - 1; collumPrint >= 0; collumPrint--) {
		for (auto row = rowPrint, collum = collumPrint; row >= 0 and collum <= static_cast<int>(dimensions.second) - 1; row--, collum++) {
			cout << matrix.at(row).at(collum) << ' ';
		}
		cout << endl;
		if (collumPrint == 0 and rowPrint != 0) {
			rowPrint--;
			collumPrint = 1;
		}
	}
}