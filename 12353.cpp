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
		mother = inch + (feet * 12);
		scanf("%d'%d\"", &feet, &inch);
		father = inch + (feet * 12);
		bool sw;
		if ((father + mother) % 2 == 0) sw = false;
		else sw = true;
		double midf = (double)(father + mother);
		if (gender == 'B') midf += 5.0;
		else midf -= 5.0;
		midf /= (double)2;
		int mid = (int)midf;
		if(sw)
			printf("Case #%d: %d'%d\" to %d'%d\"\n", x, (mid - 4) / 12, (mid - 4) % 12, (mid + 4) / 12, (mid + 4) % 12);
		else
			printf("Case #%d: %d'%d\" to %d'%d\"\n", x, (mid - 3) / 12, (mid - 3) % 12, (mid + 4) / 12, (mid + 4) % 12);
	}
	return 0;
}
