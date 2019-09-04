#include <cstdio>
#include <iostream>

using namespace std;
int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        printf("Case #%d: ", i + 1);
        if (a + b > c) 
            printf("true\n");
        else
            printf("false\n");
    }
    return 0;
}