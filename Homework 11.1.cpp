#include <iostream>
using namespace std;

char shift (int first , int last, int sign, int key){
    if (key > 0){
        if (sign + key <= last){
            return (char)sign+key;
        }   else return (char)(first+(sign + key - last-1));
    }   else if (key < 0){
        if (sign + key >= first){
            return (char)sign + key;
        }   else return (char)(last - (first - (sign + key))+1);
    }
}

string encrypt_caesar (string text, int key){
    for (int i=0; i < text.length(); i++){
        if (text[i] >= 'A' && text[i] <= 'Z' ) {
            int sign = (int)text[i];
            text[i] = shift (65, 90, sign, key);
        } else if (text[i]>= 'a' && text[i] <= 'z'){
            int sign = (int)text[i];
            text[i] = shift (97, 122, sign, key);
        }
    }
    return text;
}

string decrypt_caesar (string text, int key){
    return encrypt_caesar (text,key);
}

int main() {
    string text;
    int number;

    cout << "Enter the text: " << endl;
    getline (cin, text);
    cout << "Enter the key: " << endl;
    cin >> number;

    int key = number % 26;

    cout << "Encrypt Caesar: " << encrypt_caesar (text, key) << endl;
    cout << endl;
    cout << "Decrypt Caesar: " << decrypt_caesar (encrypt_caesar(text,key), -1*key)<< endl;

}


