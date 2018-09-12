#include <iostream>
#include <vector>
#include <string>
using namespace std;

char board[5][5];   // Boggle game board.
int C;  // The number of test cases.
int N;  // The number of words in a test case. 
vector<string> words;

// Up, down, left, right, left_up, left_down, right_up, right_down.
int move_r[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
int move_c[8] = {0, 0, -1, 1, -1, -1, 1, 1};

bool is_inside(int r, int c){
    if(0 <= r && r < 5 && 0 <= c && c < 5){
        return true;
    }
    else{
        return false;
    }
}


bool does_exist(int r, int c, string w){
    bool ret = false;
    if(board[r][c] != w[0]){
        ret = false;
    }
    else{
        if(w.length() == 1){
            ret = true;
        }
        else{
           for (int i=0; i<8; i++){
                int next_r = r + move_r[i];
                int next_c = c + move_c[i];
                if(is_inside(next_r, next_c)){
                    ret = ret || does_exist(next_r, next_c, w.substr(1));
                }
           }
        }
    }
    return ret;
}

int main(){
    cin >> C;
    while(C--){
        // Write boggle game board.
        for (int r=0; r<5; r++){
            for (int c=0; c<5; c++){
                cin >> board[r][c];
            }
        }
        // Get words.
        cin >> N;
        words.clear();
        words.resize(N);
        for (int i=0; i<N; i++){
            cin >> words[i];
        }
        // Judge if the word exists or not.
        for (auto w : words){
            // Search the start point.
            int r=0, c=0;
            while(r<5 && c<5){
                if(board[r][c] == w[0]){
                    bool result = does_exist(r, c, w);
                    if(result == true){
                        cout << w << " " << "YES\n";
                        break;
                    }
                }
                if(r<5 && c==4){
                    r++;
                    c=0;
                }
                else{
                    c++;
                }
            }
            if(r==5 && c==0){
                cout << w << " " << "NO\n";
            }
        }
    }
    return 0;
}
