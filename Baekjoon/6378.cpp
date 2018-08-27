#include <cstdio>
#include <cstring>
int main() {
	char s[1001];
	while (1) {
		int temp = 0;
		int answer = 10;
		scanf("%s", s);
		if (strcmp(s, "0") == 0) break;
		for (int i = 0; s[i] != '\0'; i++) {
			temp += (s[i] - '0');
		}
		answer = temp;
		while (answer >= 10) {
			temp = answer;
			answer = 0;
			while (temp>0) {
				answer += temp % 10;
				temp /= 10;
			}
		}
		printf("%d\n", answer);
	}
	return 0;
}
