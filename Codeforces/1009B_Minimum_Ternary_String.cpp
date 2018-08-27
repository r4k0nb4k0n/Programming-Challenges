#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string s;
int main(){
	cin >> s;
	int sz = s.length();
	for(int i=0; i<sz-1; i++){
		for(int j=i+1; j<sz; j++){
			if(s[i] == '0'){
				break;
			}
			else if(s[i] == '1'){
				if(s[j] == '0'){
					continue;
				}
				else if(s[j] == '2' && i != j-1){
					swap(s[i], s[j-1]);
					i = (i == j-1) ? j-1 : j-2; 
					break;
				}
				else{
					break;
				}
			}
			else{
				if(s[j] == '0'){
					swap(s[i], s[j-1]);
					i = (i == j-1) ? j-1 : j-2; 
					break;
				}
				else if(s[j] == '1'){
					swap(s[i], s[j]);
					// i = (i == j-1) ? j-1 : j-2; 
					break;
				}
				else{
					continue;
				}
			}
		}
		// cout << i << " : " << s << endl;
	}
	cout << s;
	return 0;
}
