#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nume[37];
	int cod;
} elem;

elem v[5005];
elem pare[5005];
elem imp[5005];
int N, P, I;
char caut[37];

void Read() {
	FILE *f = fopen("tema1.in", "r");
	fscanf(f, "%d\n", &N);
	int i;
	for (i = 0; i < N; ++i) {
		fgets(v[i].nume, 35, f);
		v[i].nume[strlen(v[i].nume) - 1] = '\0';
		fscanf(f, "%d\n", &v[i].cod);
		if (v[i].cod % 2)
			imp[I++] = v[i];
		else
			pare[P++] = v[i];
	}
	fgets(caut, 35, f);
	if(caut[strlen(caut) - 1] == '\n')
		caut[strlen(caut) - 1] = '\0';
}

void Print(elem v[], int N, FILE *g) {
	int i;
	for (i = 0; i < N; ++i)
		fprintf(g,"%s\n%d\n", v[i].nume, v[i].cod);
}

void Sort(elem v[], int N) {
	int i, j;
	for(i = 0; i < N; ++i)
		for ( j = i+1; j < N; j++)
			if (strcmp(v[i].nume, v[j].nume) > 0) {
				elem aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
}

void SortCod(elem v[], int N, int dir) {
	int i, j;
	for (i = 0; i < N; ++i)
		for (j = i + 1; j < N; j++)
			if ((v[i].cod - v[j].cod) * dir > 0) {
				elem aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
}

int Cautare() {
	int i;
	for (i = 0; i < N; ++i)
		if (!strcmp(v[i].nume, caut))
			return v[i].cod;
	return -1;
}

int main() {
	FILE *g = fopen("tema1.out", "w");
	Read();
	Sort(v,N);
	Print(v,N,g);
	fprintf(g, "%d\n", Cautare());
	SortCod(imp, I, -1);
	SortCod(pare, P, 1);
	Print(pare, P, g);
	Print(imp, I, g);
}