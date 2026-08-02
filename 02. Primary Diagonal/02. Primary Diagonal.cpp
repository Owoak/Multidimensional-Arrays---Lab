#include <iostream>
#include <sstream>

using namespace std;

const int maxRows = 100;
const int maxCollums = 100;

void readMatrix(int squareMartix[][maxCollums], const int& sizeSquareMatrix) {
	for (int rows = 0; rows < sizeSquareMatrix; rows++) {
		string input;
		getline(cin, input);
		istringstream buffer(input);
		for (int collums = 0; collums < sizeSquareMatrix; collums++) {
			buffer >> squareMartix[rows][collums];
		}
	}
}

int main()
{
	int sizeSquareMatrix;
	cin >> sizeSquareMatrix;
	cin.ignore();
	int squareMartix[maxRows][maxCollums] = {};
	readMatrix(squareMartix, sizeSquareMatrix);

	int sum = 0;

	for (int rows = 0, collums = 0; rows < sizeSquareMatrix and collums < sizeSquareMatrix; collums++, rows++) {
		sum += squareMartix[rows][collums];
	}

	cout << sum;
	return 0;
}