#include <iostream>

using namespace std;

int main() {
	cout << "\n";

	for (char i = 'f'; i < 'i'; ++i) {
		for (int j = 1; j < 9; ++j) {
			if (i == 'f' && j < 6) {
				continue;
			} else {
				cout << i << j << "\n";
			}
		}
	}
}