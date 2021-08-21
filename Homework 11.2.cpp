#include <iostream>

using namespace std;

bool correct_email (string name){
    int at = 0;
    for (int i = 0; i < name.length(); ++i){
        if (name[i] == '@'){
            if (i == 0|| i > 64 || name.length() - i > 63 || at != 0){
                return false;
            }   else at = i;
        } else if (name [i] == '.'){
            if (i == 0 || i == name.length() - 1 || name [i+1] == '.') return false;
        }
    }
    if (at == 0) {
        return false;
    } else for (int i = 0; i < name.length(); ++i){
        if (!(name[i] >= '0' && name [i] <= '9') && !(name[i]>= 'A' && name[i] <= 'Z') && !(name[i] >= 'a' && name[i]<='z') \
        && name[i]!='@' && name[i]!='.' && name[i]!='-'){
        if (i > at){
            return false;
        } else if (name[i]!='!' && !(name[i] > '"' && name[i] < '(') && name[i]!='*' && name[i]!='+' && name[i]!='/' \
        && name[i]!='=' && name[i]!='?' && !(name[i] >= '^' && name[i]<'a') && !(name[i]>='{' && name[i]<='~') && name[i]!='@'){
        return false;
    }
}
}
    return true;
}

int main() {
    string name;

    cout << "Enter your email: " << endl;
    cin >> name;
    cout << "Correct email: " << (correct_email(name)? "Yes":"No") << endl;

    return 0;
}
