#include <iostream>
using namespace std;

const int rows = 100;
const int collums = 100;

void readMatrix(int matrix[][collums], const int& RequiredRows, const int& RequiredColums) {
	for (int row = 0; row < RequiredRows; row++) {
		for (int collum = 0; collum < RequiredColums; collum++) {
			cin >> matrix[row][collum];
		}
	}
}

int main()
{
	int RequiredRows, RequiredColumms;
	cin >> RequiredRows >> RequiredColumms;
	int matrix[rows][collums] = {};

	readMatrix(matrix, RequiredRows, RequiredColumms);

	for (int collum = 0; collum < RequiredColumms; collum++) {
		int sum = 0;
		for (int row = 0; row < RequiredRows; row++) {
			sum += matrix[row][collum];
		}
		cout << sum << endl;
	}

	return 0;
}