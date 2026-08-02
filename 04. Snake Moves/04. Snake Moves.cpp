#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<string> result;
	string snake;
	unsigned short int width, lenght;
	cin >> width >> lenght >> snake;

	int letter = 0;
	for (unsigned short int row = 0; row < width; row++) {
		string input;
		while (input.size() < lenght) {
			if (row % 2 == 0) {
				input.push_back(snake[letter]);
			}
			else {
				input.insert(input.begin(), snake.at(letter));
			}
			letter++;
			if (letter == snake.size()) {
				letter = 0;
			}
		}
		result.push_back(input);
	}


	for (auto it = result.begin(); it != result.end(); it++) {
		cout << *it << endl;
	}

	return 0;
}