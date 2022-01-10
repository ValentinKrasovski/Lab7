#include <iostream>
#include <string>

using namespace std;

int element_t() {
    int t;
    bool isNotCorrect;
    do {
        isNotCorrect = false;
        cin >> t;
        if (cin.fail() || t > 1000 || t < 1) {
            cin.clear();
            cin.ignore(66666, '\n');
            cout << "Ошибка! Ваш ввод не корректен, попробуйте еще раз.\n";
            isNotCorrect = true;
        }
    } while (isNotCorrect);
    return t;
}

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
    unsigned int num, t;
    t = element_t();
    unsigned int* arr = new unsigned int[t];
    for (int i = 0; i < t; i++) {
        arr[i] = element();
    }
    for (int i = 0; i < t; i++) {
        if (arr[i] % 10 == 9) {
            cout << arr[i] / 10 + 1 << endl;
        }
        else {
            cout << arr[i] / 10 << endl;
        }
    }
    delete[] arr;


    return 0;
}