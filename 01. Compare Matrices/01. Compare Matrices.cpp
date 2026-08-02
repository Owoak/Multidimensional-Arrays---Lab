#include <iostream>
#include <sstream>
#include <utility>

using namespace std;

const int maxRows = 10;
const int maxCollums = 10;

void ReadMatrix(pair <unsigned short int, unsigned short int>& dimensions, int matrix[maxRows][maxCollums]) {
	cin >> dimensions.first;
	cin.ignore();

	for (unsigned short int rows = 0; rows < dimensions.first; rows++) {
		string input;
		getline(cin, input);
		istringstream buffer(input);

		int collumINput;
		unsigned short int collums = 0;
		for (; buffer >> collumINput; collums++) {
			matrix[rows][collums] = collumINput;
		}
		dimensions.second = collums;
	}
}

bool isEqual(const int firstMatrix[maxRows][maxCollums], const int secondMatrix[maxRows][maxCollums], const pair <unsigned short int, unsigned short int>& dimensionsFirst, const pair <unsigned short int, unsigned short int>& dimensionsSecond) {
	if (dimensionsFirst != dimensionsSecond) {
		return false;
	}

	for (unsigned short int rows = 0; rows < dimensionsFirst.first; rows++) {
		for (unsigned short int collums = 0; collums < dimensionsFirst.second; collums++) {
			if (firstMatrix[rows][collums] != secondMatrix[rows][collums]) {
				return false;
			}
		}
	}
	return true;
}

int main()
{
	pair <unsigned short int, unsigned short int> dimensionsFirst;
	pair <unsigned short int, unsigned short int> dimensionsSecond;

	int firstMatrix[maxRows][maxCollums] = {};
	ReadMatrix(dimensionsFirst, firstMatrix);
	int secondMatrix[maxRows][maxCollums] = {};
	ReadMatrix(dimensionsSecond, secondMatrix);

	if (isEqual(firstMatrix, secondMatrix, dimensionsFirst, dimensionsSecond)) {
		cout << "equal";
	}
	else {
		cout << "not equal";
	}

	return 0;
}