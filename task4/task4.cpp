#include <iostream>
#include <string>

using namespace std;


string check() {
    string input;
    bool IsCorrect = true;
    while (IsCorrect) {
        getline(cin, input);
        if (input.size() > 32) {
            cout << "����� ������ �������� �� �����, ��� �� 32 ����\n";
        }
        else if (input.find_first_not_of("0123456789abcde") < input.size()) {
            cout << "������ �����.\n���������� ��� ���.\n";
        }
        else {
            IsCorrect = false;
        }
    }
    return input;
}

char element() {
    char n;
    do {
        cin >> n;
        if (n != '+' && n != '-') {
            cout << "��� ���� �����������! ���������� �����.\n";
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (n != '+' && n != '-');

    return n;
}

char convInt(int elem) {
    if (elem < 10)
        return char(elem + '0');
    else if (elem == 10)
        return 'a';
    else if (elem == 11)
        return 'b';
    else if (elem == 12)
        return 'c';
    else if (elem == 13)
        return 'd';
    else if (elem == 14)
        return 'e';
}

int convChar(char elem) {
    if (elem - '0' < 10)
        return elem - '0';
    else if (elem == 'A')
        return 10;
    else if (elem == 'B')
        return 11;
    else if (elem == 'C')
        return 12;
    else if (elem == 'D')
        return 13;
    else if (elem == 'E')
        return 14;
}

string Sum(string num1, string num2) {
    string sum = '0' + num1;
    int add = 0;
    for (int i = num1.size() - 1; i >= 0; i--) {

        if (convChar(num1[i]) + convChar(num2[i]) + add < 15) {
            sum[i + 1] = convInt(convChar(num1[i]) + convChar(num2[i]) + add);
            add = 0;
        }
        else {
            sum[i + 1] = convInt(convChar(num1[i]) + convChar(num2[i]) + add - 15);
            add = 1;
        }
    }
    if (add == 1) {
        sum[0] = '1';
    }
    return sum;
}

string Subt(string num1, string num2) {
    string subt = '0' + num1;
    int minus = 0;
    for (int i = num1.size() - 1; i >= 0; i--) {
        if (convChar(num1[i]) >= convChar(num2[i]) + minus) {
            subt[i + 1] = convInt(convChar(num1[i]) - convChar(num2[i]) - minus);
            minus = 0;
        }
        else {
            subt[i + 1] = convInt(convChar(num1[i]) + 17 - convChar(num2[i]) - minus);
            minus = 1;
        }
    }
    if (minus == 1) {
        subt[0] = '-';
    }
    return subt;
}


int main() {
    setlocale(LC_ALL, "rus");
    cout << "������� 2 �����, ��������� ����� ��� �� 10 ����\n";
    string num1 = check();
    string num2 = check();

    if (num1.size() < 32) {
        num1.insert(0, 32 - num1.size(), '0');
    }
    if (num2.size() < 32) {
        num2.insert(0, 32 - num2.size(), '0');
    }

    cout << "�������� �������� '+' ��� ��������� '-'\n";
    char operation = element();
    if (operation == '+') {
        cout << "��������� �������� : " << Sum(num1, num2);
    }
    else {
        cout << "��������� ���������: " << Subt(num1, num2);
    }
}