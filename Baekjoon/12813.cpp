#include <iostream>
#include <bitset>

using namespace std;

bitset<100000> A, B;

int main()
{
	cin >> A >> B;
	cout << (A&B).to_string() << endl;
	cout << (A|B).to_string() << endl;
	cout << (A^B).to_string() << endl;
	cout << (~A).to_string() << endl;
	cout << (~B).to_string() << endl;
	return 0;
}
