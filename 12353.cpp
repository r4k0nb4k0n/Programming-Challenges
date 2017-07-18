#include <cstdio>

int main() {
	int c;
	scanf("%d", &c);
	for (int x = 1; x <= c; x++) {
		char gender;
		int feet, inch;
		int father, mother;
		getchar();
		scanf("%c", &gender);
		scanf("%d'%d\"",&feet,&inch);
		mother = inch + (feet * 12); // 인치로 변환
		scanf("%d'%d\"", &feet, &inch);
		father = inch + (feet * 12); // 인치로 변환
		bool sw;
		if ((father + mother) % 2 == 0) sw = false; // (아빠 키 + 엄마 키) 짝수일 때
		else sw = true; // (아빠 키 + 엄마 키) 홀수일 때
		double midf = (double)(father + mother);
		if (gender == 'B') midf += 5.0; // 남자아이는 + 5인치
		else midf -= 5.0; // 여자아이는 - 5인치
		midf /= (double)2;
		int mid = (int)midf;
		if(sw) // 합이 짝수일 때 그대로 출력
			printf("Case #%d: %d'%d\" to %d'%d\"\n", x, (mid - 4) / 12, (mid - 4) % 12, (mid + 4) / 12, (mid + 4) % 12);
		else // 합이 홀수일 때 최소값에 1인치를 더해주고 출력
			printf("Case #%d: %d'%d\" to %d'%d\"\n", x, (mid - 3) / 12, (mid - 3) % 12, (mid + 4) / 12, (mid + 4) % 12);
	}
	return 0;
}
