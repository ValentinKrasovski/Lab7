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

string conv_sec(int num) {
	string s = "";
	while (num >= 2) {
		s.insert(0, to_string(num % 2));
		num /= 2;
	}
	s.insert(0, to_string(num));
	return s;
}

bool two_decimal(int num) {
	string str = conv_sec(num);
	string Num = to_string(num);

	for (int i = str.length() - 1; i >= 0; i--) {
		if (Num == str.substr(i)) {
			return true;
		}
	}
	return false;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n = element();
	int k = 0;
	while (n != 0) {
		k++;
		if (two_decimal(k)) {
			n--;
		}
	}
	cout << k;
	return 0;
}