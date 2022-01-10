#include <iostream>
#include <string>

using namespace  std;

string check() {
	string str;
	bool correct = true;
	while (correct) {
		getline(cin, str);
		if ((str.length() == 1 || str.length() > 32) && str.find_first_not_of("01") < str.length()) {
			cout << "Ошибка ввода!Попробуйте еще раз ";
		}
		else {
			correct = false;
		}
	}
	return str;
}

void rev_c(string& a) {
	if (a[0] == '1') {
		for (int i = 1; i < a.length(); i++) {
			if (a[i] == '0') {
				a[i] = '1';
			}
			else {
				a[i] = '0';
			}
		}
	}
}

void Sum(string& a, string& b, string& sum) {
	for (int i = sum.length() - 1; i > 0; i--) {
		sum[i] += a[i] + b[i] - '0';
		if (sum[i] > '1') {
			sum[i] -= 2;
			sum[i - 1]++;
		}
	}
	sum[0] += a[0] + b[0] - '0';
	if (sum[0] > '1') {
		sum[0] -= 2;
		for (int i = sum.length() - 1; i > 0; i--) {

			if (sum[i] == '1') {
				sum[i] = '0';
			}
			else {
				sum[i] = '1';
				break;
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	string a, b;
	cout << "Введите первое число: ";
	a = check();
	cout << "Введите второе число: ";
	b = check();

	cout << endl;

	a.insert(1, 32 - a.size(), '0');
	b.insert(1, 32 - b.size(), '0');
	cout << "Первое число: " << a << "\n";
	cout << "Второе число: " << b << "\n";

	rev_c(a);
	rev_c(b);

	string sum;
	sum.resize(32);
	for (int i = 0; i < 32; i++) {
		sum[i] = '\0';
	}

	Sum(a, b, sum);
	//прямой код
	if (a[0] == '0' && b[0] == '0' && sum[0] == '1' || a[0] == '1' && b[0] == '1' && sum[0] == '0') {
		cout << "Переполнение!\n";
	}
	else {
		if (sum[0] == '1') {

			for (int i = 1; i < sum.length(); i++) {
				if (sum[i] == '0') {
					sum[i] = '1';
				}
				else {
					sum[i] = '0';
				}
			}

		}
		cout << "sum: " << sum << endl;
	}
	return 0;
}