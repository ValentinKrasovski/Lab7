#include <iostream>
#include <string>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	cout << "Введите число в шестеричной системе";
	char* str6 = new char[100];
	cin.getline(str6, 99);
	int l = strlen(str6);

	int d = 0;
	//перевод в десятичную
	int s6 = atoi(str6);
	int k = 0;
	while (s6) {
		d += (s6 % 10) * pow(6, k);
		s6 /= 10;
		k++;
	}

	char* str15 = new char[100];
	int i = 0;
	while (d) {
		str15[i] = '0' + (d % 15);
		i++;
		d /= 15;
	}

	for (int j = 0; j < i; j++) {
		switch (str15[j]) {
		case '0' + 10:
			str15[j] = 'A';
			break;
		case '0' + 11:
			str15[j] = 'B';
			break;
		case '0' + 12:
			str15[j] = 'C';
			break;
		case '0' + 13:
			str15[j] = 'D';
			break;
		case '0' + 14:
			str15[j] = 'E';
			break;
		}
	}
	for (int j = i - 1; j >= 0; j--) {
		cout << str15[j];
	}

	delete[] str6;
	delete[] str15;
	return 0;
}