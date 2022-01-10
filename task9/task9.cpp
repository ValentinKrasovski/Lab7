#include <iostream>
#include <string>

using namespace std;

int element() {
	int n;
	bool isNotCorrect;
	do {
		isNotCorrect = false;
		cin >> n;
		if (cin.fail() || n > 10000 || n < 1) {
			cin.clear();
			cin.ignore(66666, '\n');
			cout << "Ошибка! Ваш ввод не корректен, попробуйте еще раз.\n";
			isNotCorrect = true;
		}
	} while (isNotCorrect);
	return n;
}


string conv_third(int num) {
	string s = "";
	num = abs(num);
	while (num >= 3) {
		s.insert(0, to_string(num % 3));
		num /= 3;
	}
	s.insert(0, to_string(num));
	return s;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n = element();
	string str = conv_third(n);

	for (int i = str.length() - 1; i > 0; i--) {
		int d = str[i] - '0';
		if (!d) {
			int j = i;
			do {
				j--;
			} while (str[j] == '0');

			str[j] = str[j] - 1;
			str[i] = '3';
		}
	}

	int i = 0;
	for (i; i < str.length(); i++) {
		if (str[i] != '0') {
			break;
		}
	}
	str = str.substr(i);
	cout << str;

	return 0;
}
