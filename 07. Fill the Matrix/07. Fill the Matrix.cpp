#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

void methodA(const size_t& size) {
	for (int collum = 1; collum <= size; collum++) {
		for (int row = collum, cycles = 0; cycles < size; cycles++, row += size) {
			cout << row << ' ';
		}
		cout << endl;
	}
}
void methodB(vector <vector <int >>& matrix) {
	int sum = 1;
	for (int collums = 0; collums < matrix[0].size(); collums++) {
		if (collums % 2 == 0) {
			for (int row = 0; row < matrix.size(); row++, sum++) {
				matrix[row][collums] = sum;
			}
		}
		else {
			for (int row = matrix.size() - 1; row >= 0; row--, sum++) {
				matrix[row][collums] = sum;
			}
		}
	}

	// print matrix

	for (int row = 0; row < matrix[0].size(); row++) {
		for (int collums = 0; collums < matrix.size(); collums++) {
			cout << matrix[row][collums] << ' ';
		}
		cout << endl;
	}
}

int main()
{
	vector <vector <int >> matrix;
	size_t size;
	string input, method;
	getline(cin, input);
	istringstream buffer(input);
	buffer >> size;
	getline(buffer, method);
	matrix.resize(size, vector<int>(size, 0));

	if (method == ", A") {
		methodA(size);
	}
	else {
		methodB(matrix);
	}

	return 0;
}