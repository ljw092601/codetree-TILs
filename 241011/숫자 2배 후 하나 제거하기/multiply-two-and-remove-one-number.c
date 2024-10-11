#include <stdio.h>

int is_found(int b, int e, int n) {
    for (int v = b; v <= e; v++) {
        if (v % n == 0) return 1;
    }
    return 0;
}

int main() {
    int b, e, n;
    int v;
    scanf("%d%d%d", &b, &e, &n);

    if (is_found(b, e, n))
        prinf("f\n");
    else
        printf("nf\n");

    for (v = b; v <= e && !(n % v == 0); v++)
        ;
    if (v <= e)
        prinf("f\n");
    else
        printf("nf\n");

    

    return 0;
}