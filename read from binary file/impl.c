#include "frac.h"
#include <stdio.h>

int read_frac(FILE *f, Frac *frac) {
	char s;
	int n_read;
	n_read = fread(&s, sizeof(char), 1, f);
	if (n_read!=1) { return 0; }
	n_read = fread(&(frac->n), sizeof(int), 1, f);
	if (n_read!=1) { return 0; }
	n_read = fread(&(frac->d), sizeof(int), 1, f);
	if (n_read!=1) { return 0; }
	if (s<0) {
		frac->n = -frac->n;
	}
	return 1;
}

Frac find_largest(FILE *f) {
	Frac cur, largest;
	int n_read;
	n_read = read_frac(f, &largest);
	while ((n_read=read_frac(f, &cur))==1) {
		if (((double)cur.n)/cur.d > ((double)largest.n)/largest.d) {
			largest = cur;
		}
	}
	return largest;
}

