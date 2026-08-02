#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

const int maxSize = 100;

void readMatrix(int matrix[][maxSize], const size_t sizeOfSquareMatrix) {
	for (int row = 0; row < sizeOfSquareMatrix; row++) {
		for (int collum = 0; collum < sizeOfSquareMatrix; collum++) {
			cin >> matrix[row][collum];
		}
	}
}

int main()
{
	int matrix[maxSize][maxSize] = {};
	size_t sizeOfSquareMatrix;
	cin >> sizeOfSquareMatrix;
	cin.ignore();
	readMatrix(matrix, sizeOfSquareMatrix);

	// first diagonal sum
	int firstDiagonalSum = 0;
	for (int i = 0; i < sizeOfSquareMatrix; i++) {
		firstDiagonalSum += matrix[i][i];
	}

	// second diagonal sum
	int secondDiagonalSum = 0;
	for (int row = 0, collum = sizeOfSquareMatrix - 1; row < sizeOfSquareMatrix and collum >= 0; collum--, row++) {
		secondDiagonalSum += matrix[row][collum];
	}

	cout << abs(firstDiagonalSum - secondDiagonalSum);

	return 0;
}