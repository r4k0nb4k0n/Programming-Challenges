#include <stdio.h>
 
// 전역 변수로 행렬 선언.
 
int A[101][101], B[101][101], C[101][101];
int A_R,A_C,B_R,B_C; // R : Row, C: Column
 
int main()
{
    int i, j, k;
    scanf("%d %d",&A_R,&A_C);
    for(i=1;i<=A_R;i++)
        for(j=1;j<=A_C;j++)
            scanf("%d",&A[i][j]); // A 행렬 입력받음.
    scanf("%d %d",&B_R,&B_C);
    for(i=1;i<=B_R;i++)
        for(j=1;j<=B_C;j++)
            scanf("%d",&B[i][j]); // B 행렬 입력받음.
 
    for(i=1;i<=A_R;i++)
        for(j=1;j<=B_C;j++)
            for(k=1;k<=A_C;k++)
                C[i][j] += (A[i][k] * B[k][j]);
 
    for(i=1;i<=A_R;i++)
    {
        for(j=1;j<=B_C;j++)
            printf("%d ",C[i][j]);
 
        printf("\n");
    }
 
    return 0;
}
