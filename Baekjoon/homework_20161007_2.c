#include <stdio.h>

int main()
{
    long long input; // I declare long long type variable, because there is no limitation of input number.
    printf("Input the POSITIVE INTEGER you want to reverse=> ");
    scanf("%lld",&input);
    
    printf("The result is ");

    while(input != 0) // Loop Condition
    {
        printf("%lld",input%10); // Print the end of the number.
        input = input/10; // Reassign to 'input'.
    }
    
    printf(".\n");
    return 0;
}
