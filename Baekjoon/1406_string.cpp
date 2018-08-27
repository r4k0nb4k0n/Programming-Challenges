#include <iostream>
#include <string>
using namespace std;

string s;
char command, argument;
int N, cursor=0; // 커서의 오른쪽 글자의 인덱스 저장. X|O

int main(){
        cin >> s;
        cursor = s.length();
        cin >> N;
        while(N--){
                cin >> command;
                switch(command){
                        case 'L': // 커서를 왼쪽으로 한 칸 옮김 (커서가 문장의 맨 앞이면 무시됨)
                                cursor = (cursor == 0) ? cursor : cursor-1;
                                break;
                        case 'D': // 커서를 오른쪽으로 한 칸 옮김 (커서가 문장의 맨 뒤이면 무시됨)
                                cursor = (cursor == s.length()) ? cursor : cursor+1;
                                break;
                        case 'B': // 커서 왼쪽에 있는 문자를 삭제함.
                                if(cursor == 0) continue;
                                s.erase(s.begin()+cursor-1);
                                cursor = (cursor == 0) ? cursor : cursor-1;
                                break;
                        case 'P': // $라는 문자를 커서 왼쪽에 추가함
                                cin >> argument;
                                if(cursor == 0) s.insert(s.begin()+cursor, argument);
                                else s.insert(s.begin()+cursor, argument);
                                cursor = (cursor == s.length()) ? cursor : cursor+1;
                                break;
                }
        }
        cout << s;
        return 0;
}
