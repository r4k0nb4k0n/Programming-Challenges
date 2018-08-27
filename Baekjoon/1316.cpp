#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n, cnt=0;
string s;

int main(){
    cin >> n;
    while(n--){
        cin >> s;
        int i;
        int len = s.length();
        bool hasAppeared['z'-'a'+1];
        memset(hasAppeared, false, sizeof(hasAppeared));
        hasAppeared[s[0]-'a'] = true;
        for(i=1; i<len; i++){
            if(hasAppeared[s[i]-'a']){
                if(s[i-1] == s[i]) continue;
                else break;
            } else hasAppeared[s[i]-'a'] = true;
        }
        if(i==len) cnt++;
    }
    cout << cnt;
    return 0;
}
