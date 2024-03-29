/*
 * PAT_B1001 害死人不偿命的(3n+1)猜想 (15 分)
 */
#include <cstdio>

int main()
{
    int n, step = 0;
    scanf("%d", &n);
    while(n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        }
        else {
            n = (3 * n + 1) / 2;
        }
        step++;
    }
    printf("%d", step);
    return 0;
}