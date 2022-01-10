#include <iostream>
#include <string>
#include <cmath>
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
            cout << "Ошибка! Ваш ввод не корректен, попробуйте еще раз.\n";
            isNotCorrect = true;
        }
    } while (isNotCorrect);
    return n;
}


int main() {
    setlocale(LC_ALL, "rus");
    cout << "Введите число в арабской системе записи" << endl;
    int num;
    num = element();
    string result;
    string rom[] = { "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M" };
    int ars[] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };

    for (int i = 12; i >= 0; i--) {
        while (num - ars[i] >= 0) {
            result += rom[i];
            num -= ars[i];
        }
    }
    cout << "Число в римской форме записи: " << result;
    return 0;
}