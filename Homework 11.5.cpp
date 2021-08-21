#include <iostream>
using namespace std;

string g_line1;
string g_line2;
string g_line3;

char sign(int x, int y){
    if (y == 0) return g_line1[x];
    if (y == 1) return g_line2[x];
    if (y == 2) return g_line3[x];
}

int win(char symbol){
    int find = 0;
    int win_count = 0;
    for (int x = 0 ; x < 3 ; ++x){
        for (int y = 0 ; y < 3 ; ++y){
            if (sign(x,y) == symbol) find++;
        }
        if (find == 3){
            win_count++;
            find = 0;
        }   else find = 0;
    }
    for (int y = 0 ; y < 3 ; ++y){
        for (int x = 0 ; x< 3 ; ++x){
            if (sign(x,y) == symbol) find++;
        }
        if (find == 3){
            win_count++;
            find = 0;
        }   else find = 0;
    }
    int findDown = 0;
    int findUp = 0;
    for (int x = 0 ; x < 3 ; ++x){
        if (sign(x,x) == symbol) findDown++;
        if (sign(x,2-x) == symbol) findUp++;
    }
    if (findDown == 3){
        win_count++;
    }
    if (findUp == 3){
        win_count++;
    }

    return win_count;
}

string matchResult(){
    int count_X = 0;
    int count_O = 0;
    for (int x = 0 ; x < 3 ; ++x){
        for (int y = 0 ; y < 3 ; ++y){
            if (sign(x,y) != 'X' && sign(x,y) != 'O' && sign(x,y) != '.'){
                return "Incorrect";
            }
            if (sign(x,y) == 'X') count_X++;
            if (sign(x,y) == 'O') count_O++;
        }
    }
    if ((count_X - count_O) > 1 || (count_O - count_X) >1) return "Incorrect";
    if (win('X') == 1){
        if (win('O') < 1 && count_X > count_O) {
            return "Petya won!";
        } else return "Incorrect";
    }
    if (win('O') == 1){
        if (win('X') < 1 && count_O == count_X){
            return "Vanya won!"; 
        } else return "Incorrect";
    }
    return "Nobody";
}

int main() {
     cout << "Enter a match table:" << endl;
     cin >> g_line1 >> g_line2 >> g_line3;

     cout << matchResult();
}
