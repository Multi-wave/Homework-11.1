#include <iostream>
using namespace std;

bool rightNumber(string number) {
    bool correct = false;
    int dot = 0;

    for (int i = 0; i < number.length(); ++i) {
        if (number[i] >= '0' && number[i] <= '9') {
            correct = true;
            break;
        }
    }
    for (int i = 0; i < number.length() && correct; i++) {
        if ((number[i] >= '0' && number[i] <= '9') || number[i] == '-' || number[i] == '.') {
            if (number[i] == '-' && i != 0) {
                correct = false;
            }
            else if (number[i] == '.') {
                if (dot == 0) {
                    dot++;
                }
                else correct = false;
            }
        }
        else correct = false;
    }
    return correct;
}

string partNumber(string number, int part) {
    string result;
    bool zero = true;
    int i = 0;
    int dot = 0;
    if (number[0] == '-') i = 1;
    for (i; i < number.length(); ++i) {
        if (number[i] == '.') dot = i;
    }
    if (dot == 0 && number[0] != '.') {
        dot = number.length();
    }
    else if (number[0] == '.') dot = 0;
    if (number[0] == '-') {
        i = 1;
    }
    else i = 0;
    if (part == 0) {
        for (i; i < dot; ++i) {
            if (number[i] != '0' && zero) zero = false;
            if (!zero) result += number[i];
        }
        return result;
    }
    else {
        for (i = dot + 1; i < number.length(); ++i) {
            if (number[i] != '0') zero = false;
            result += number[i];
        }
        if (zero) {
            return "!";
        }
        else return result;
    }

}

string compareNumbers(string number1, string number2) {
    bool negative = false;
    if (number1[0] == '-' && number2[0] != '-') return "Less";
    if (number2[0] == '-' && number1[0] != '-') return "More";
    if (number1[0] == '-' && number2[0] == '-') negative = true;
    string integer1 = partNumber(number1, 0);
    string integer2 = partNumber(number2, 0);
    if (integer1.length() > integer2.length()) {
        if (negative) {
            return "Less";
        }
        else return "More";
    }
    else if (integer1.length() != integer2.length()) {
        if (negative) {
            return "More";
        }
        else return "Less";
    }
    for (int i = 0; i < integer1.length(); ++i) {
        if (integer1[i] > integer2[i]) {
            if (negative) {
                return "Less";
            }
            else return "More";
        }
        else if (integer2[i] > integer1[i]) {
            if (negative) {
                return "More";
            }
            else return "Less";
        }
    }
    string fractional1 = partNumber(number1, 1);
    string fractional2 = partNumber(number2, 1);
    int length = (fractional1.length() <= fractional2.length() ? fractional1.length() : fractional2.length());
    if (length == 0 && fractional1.length() == 0) {
        if (negative) {
            return "More";
        }
        else return "Less";
    }
    if (length == 0 && fractional2.length() == 0) {
        if (negative) {
            return "Less";
        }
        else return "More";
    }
    for (int i = 0; i < length; ++i) {
        if (fractional1[i] > fractional2[i]) {
            if (negative) {
                return "Less";
            }
            else return "More";
        }
        else if (fractional2[i] > fractional1[i]) {
            if (negative) {
                return "More";
            }
            else return "Less";
        }
    }
    return "Equal";

}

int main()
{
    string number1;
    string number2;
    cout << "Enter a two numbers: ";
    cin >> number1;
    cin >> number2;


    if (rightNumber(number1) && rightNumber(number2)) {
        cout << compareNumbers (number1,number2);
    }   else cout << "Number is not correct!";

}

