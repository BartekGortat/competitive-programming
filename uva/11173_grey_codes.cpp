// https://onlinejudge.org/external/111/11173.pdf

#include <cstdio>

int main()
{
    int N, n, k;
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d %d", &n, &k);
        int x = k ^ (k >> 1);
        printf("%d\n", x);
    }
    return 0;
}