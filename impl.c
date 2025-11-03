#include <stdio.h>
#include "frac.h"

Frac read_frac() {
    Frac f;
    scanf("%d / %d", &(f.n), &(f.d));
    return f;
}

int gcd(int a, int b) {
    int r;
    
    while (b!=0) {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

void reduce_fracs(Frac v[], int num_fracs) {
    int i;
    
    for (i=0; i<num_fracs; i++) {
        int g;
        g = gcd(v[i].n, v[i].d);
        v[i].n/=g;
        v[i].d/=g;
    }
}
