#include <stdio.h>

int sum_(int num)
{
	if (num <= 1)
	{
		return 1;
	}
	else
	{
		return (num + sum_(num - 1));
	}
}
int main(void){
    int n, i, j;
    int sum=0;
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        sum += i;
    }
    printf("%d\n", sum);
    return 0;
}
