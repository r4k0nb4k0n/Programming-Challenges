#include <stdio.h>
#include <iostream>
 
using namespace std;
 
int main(void)
{
    int T; // 학기의 수.
    int N; // 들었던 과목의 수.
    int sum = 0;
    double GPA = 0.0;
     
    cin >> T;
 
     
    for(int i=1;i<=T;i++)
    {
        sum = 0;
        GPA = 0.0;
        cin >> N;
        for(int j=1;j<=N;j++)
        {
            int C;
            double G;
            cin >> C;
            cin >> G;
             
            sum = sum + C;
            GPA = GPA + C * G;
        }
        GPA = GPA / sum;
         
        printf("%d %.1f\n",sum,GPA);
    }
    return 0;
}