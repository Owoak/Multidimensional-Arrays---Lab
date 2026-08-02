#include <iostream>
#include <string>
using namespace std;

const int maxSize = 100;

void readMatrix(char matrix[maxSize][maxSize], const int& requiredSize) {
	for (int rows = 0; rows < requiredSize; rows++) {
		string input;
		getline(cin, input);
		for (int collums = 0; collums < requiredSize; collums++) {
			matrix[rows][collums] = input[collums];
		}
	}
}

int main()
{
	char matrix[maxSize][maxSize] = {};
	char wantedSymbol;
	int requiredSize;
	cin >> requiredSize;
	cin.ignore();
	readMatrix(matrix, requiredSize);
	cin >> wantedSymbol;

	for (int rows = 0; rows < requiredSize; rows++) {
		for (int collums = 0; collums < requiredSize; collums++) {
			char currentSymbol = matrix[rows][collums];
			if (currentSymbol == wantedSymbol) {
				cout << "(" << rows << ", " << collums << ")";
				return 0;
			}
		}
	}

	cout << wantedSymbol << " does not occur in the matrix";

	return 0;
}