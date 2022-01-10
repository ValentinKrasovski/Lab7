#include <iostream>
using namespace std;

int element() {
	int n;
	bool isNotCorrect;
	do {
		isNotCorrect = false;
		cin >> n;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(66666, '\n');
			cout << "������! ��� ���� �� ���������, ���������� ��� ���.\n";
			isNotCorrect = true;
		}
	} while (isNotCorrect);
	return n;
}


void divs(long long n, int k) {
	bool check = false;
	n = abs(n);
	long long d = k;
	while (k <= n) {
		if (n == k) {
			cout << "����� ������� �� " << d << endl;
			check = true;
		}
		k += d;
	}
	if (!check) {
		cout << "����� �� ������� �� " << d << endl;
	}

}

int main() {
	setlocale(LC_ALL, "rus");

	int n = element();
	divs(n, 5);
	divs(n, 47);
	divs(n, 89);

	return 0;
}