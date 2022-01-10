#include <iostream>
#include <string>
using  namespace std;

string check() {
	string str;
	bool correct = true;
	while (correct) {
		getline(cin, str);
		if ((str.length() == 1 || str.length() > 32) && str.find_first_not_of("01") < str.length()) {
			cout << "Ошибка ввода! Попробуйте еще раз ";
		}
		else {
			correct = false;
		}
	}
	return str;
}

int main() {
	setlocale(LC_ALL, "rus");
	cout << "Введите дополнительный код";
	string num = check();

	num.insert(1, 32 - num.length(), '0');
	cout << "Дополнительный код: " << num << "\n";
	//перевод в обратный код
	for (int i = num.length() - 1; i > 0; i--) {
		if (num[i] == '1') {
			num[i] = '0';
			break;
		}
		else {
			num[i] = '1';
		}
	}
	cout << "Обратный код:  " << num;
	cout << endl;
	return 0;
}