#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

void disp_animal(int animal_number, int distance)
{
	int i;
	if(animal_number == 1)
		printf("RABBIT : ");
	else if(animal_number == 2)
		printf("TURTLE : ");
	else if(animal_number == 3)
		printf("CAT : ");
	else
		printf("DOG : ");

	for(i=0;i<distance;i++)
		printf("*");
	printf("\n");
}

int main()
{
	int i;
	int rabbit_dist=0, turtle_dist=0, cat_dist=0, dog_dist=0;

	srand((unsigned)time(NULL));

	for(i=0;i<6;i++)
	{
		system("cls");
		rabbit_dist += (rand()%3)+3;
		turtle_dist += (rand()%2)+1;
		cat_dist += (rand()%3)+4;
		dog_dist += (rand()%3)+5;
		disp_animal(1, rabbit_dist);
		disp_animal(2, turtle_dist);
		disp_animal(3, cat_dist);
		disp_animal(4, dog_dist);
		getch();
	}
	return 0;
}

