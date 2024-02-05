
#include <stdio.h>

void ToH(int n, char source, char spare, char dest);
static int step=0;

int main() {
    int n;
    printf("Enter the number of rings:");
    scanf("%d",&n);
    ToH(n,'A','B','C');
    return 0;
}

void ToH(int n, char A, char B, char C)
{
    if(n==1)
        printf("\nStep %d: Move %d from %c to %c",++step,n,A,C);
    else
    {
        ToH(n-1,A,C,B);
        ToH(1,A,B,C);
        ToH(n-1,B,A,C);
    }
}
