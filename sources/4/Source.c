#include <stdio.h>
#include "timer.h"

int main()
{
    int n, v[100], i;
	
	FILE *f = fopen("CautareLiniara.in", "r");
	FILE *g = fopen("CautareLiniara.out", "w");
	
	starton();
    fscanf(f, "%d", &n);
    for ( i = 1; i <= n; ++i)
        fscanf(f, "%d", &v[i]);
    int val;
    fscanf(f, "%d", &val);

    for ( i = 1; i <= n; ++i)
        if (v[i] == val) {
            fprintf(g, "%d", i);
            return 0;
        }
	
    fprintf(g,"-1");
	startoff();
    return 0;
}
