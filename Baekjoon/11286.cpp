#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;

struct abs_heap{ // a < b
	int value;
	int is_negative;

	bool operator < (const abs_heap &other) const{
		if(value == other.value)
			return is_negative < other.is_negative;
		else
			return value < other.value;
	}
	bool operator > (const abs_heap &other) const{
		if(value == other.value)
			return is_negative > other.is_negative;
		else
			return value > other.value;
	}
	bool operator == (const abs_heap &other) const{
		return (value == other.value) && (is_negative == other.is_negative);
	}
	abs_heap operator + (const abs_heap &other) const{ // 
		abs_heap temp;
		temp.value = value + other.value;
		temp.is_negative = 1;
		return temp;
	}
};

int main() {
	int n;
	abs_heap input;
	priority_queue<abs_heap> pq;
	scanf("%d",&n);
	for (int i = 0; i < n;i++){
		scanf("%d",&input.value);
		if (input.value == 0) { // 0일 때 절대값이 가장 작은 값을 출력
			if (!pq.empty()) {
				if (!pq.top().is_negative) {
					printf("%d\n",-pq.top().value);
					//cout << "positive\n";
				}
				else {
					printf("%d\n",pq.top().value);
					//cout << "negative\n";
				}
				pq.pop();
			}
			else
				printf("0\n");
		}
		else { // 0이 아닐 때는
			if (input.value < 0)
				input.is_negative = 1;
			else
				input.is_negative = 0;
			input.value = -abs(input.value);
			pq.push(input);
		}
	}
	return 0;
}
