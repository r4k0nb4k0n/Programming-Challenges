#include <iostream>
#include <bitset>

using namespace std;

unsigned int a = 0xFF000000;
unsigned int b = 0x00FF0000;
unsigned int c = 0x0000FF00;
unsigned int d = 0x000000FF;
int n;


int main(){
    cin >> n;
    while(n--){
        unsigned int in;
        cin >> in;
        unsigned int first = in & a;
        unsigned int second = in & b;
        unsigned int third = in & c;
        unsigned int fourth= in & d;
        
        unsigned int out = 0;
        out += (first >> 24);
        out += (second >> 8);
        out += (third << 8);
        out += (fourth << 24);
        
        cout << out << "\n";
    }
    return 0;
}