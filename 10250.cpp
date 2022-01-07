#include <iostream>
using namespace std;

int main() {
	int test;
	int height, width, number;
	int result;
	cin >> test;

	for (int i = 0; i < test; i++) {
		cin >> height >> width >> number;

		if (number%height == 0) {
			result = height * 100 + (number / height);
		}
		else {
			result = (number%height) * 100 + (number / height) + 1;
		}
		cout << result << endl;
	}
}