#include <string>
#include <fstream>
#include <iostream>

// Yes, we all know it's bAd PrAcTiCe
// Spend some time thinking about why I don't care
// and learn to think critically about programming

using namespace std;

bool leftOnly(string word) {
	bool isTrue = true;
	static const char rightChars[] = {
		'y', 'u', 'i', 'o', 'p',
		'h', 'j', 'k', 'l',
		'n', 'm'
	};

	for (auto c : word) {
		if (find(begin(rightChars), end(rightChars), c) != end(rightChars))
			isTrue = false;
	}

	return isTrue;
}

bool rightOnly(string word) {
	bool isTrue = true;
	static const char leftChars[] = {
		'q', 'w', 'e', 'r', 't',
		'a', 's', 'd', 'f', 'g',
		'z', 'x', 'c', 'v', 'b'
	};

	for (auto c : word) {
		if (find(begin(leftChars), end(leftChars), c) != end(leftChars))
			isTrue = false;
	}

	return isTrue;
}

int main() {
	int left = 0;
	int right = 0;
	int wordCounter = 0;

	string word;
	ifstream file("wordlist.txt");

	while (getline(file, word)) {
		if (leftOnly(word))
			++left;
		else if (rightOnly(word))
			++right;
	}

	cout << "Left Hand Words: " << left << endl;
	cout << "Right Hand Words: " << right << endl;

	return 0;
}
