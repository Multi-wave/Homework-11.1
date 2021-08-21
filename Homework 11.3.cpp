#include <iostream>
using namespace std;

bool numberCorrect (string number){
    int result = 0;
    if ((number[0] == '0' && number.length() >1) || number.length() >3 || number.length() == 0){
        return false;
    }
    for (int i=0; i< number.length(); ++i){
        if (number[i] >= '0' && number[i] <= '9'){
            result = result*10 + number[i] - 48;
        } else return false;
    }
    if (result > 255) return false;
    return true;
}

bool correct_IP(string text){
    string number;
    int count = 0;
    int length = text.length();

    if (length < 7 || length > 15 || text [0] == '.' || text[length-1] == '.'){
        return false;
    }
    for (int i = 0 ; i < length ; ++i){
        if (text[i] == '.'){
            if (numberCorrect(number)){
                number.clear();
                count++;
            } else return false;
        }else number += text[i];
    }
    if (count == 3 && numberCorrect(number)) {
        return true;
    }   else return false;
}

int main() {
    string adress;

    cout << "Enter IPv4 adress: " << endl;
    cin >> adress;

    cout << "Correct adress: " << (correct_IP(adress) ? "Yes" : "No") << endl;
}
