#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

const char filename[] = "-tema1.in";

void gen_random_string(char *s, const int len) {
	static const char alphanum[] =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz ";

	for (int i = 0; i < len; ++i) {
		s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
	}

	s[len] = 0;
}

void GenerateTest(int idx) {
	char *idxptr = new char;
	ofstream g(strcat(itoa(idx,idxptr,10), filename));

	int N = rand() % 5000;
	g << N << '\n';
	int cautbin_idx = rand() % N;
	char *cautbin = new char[40];
	char *productname = new char[40];
	for (int i = 0; i < N; ++i) {
		int len = rand() % 32 + 3;
		gen_random_string(productname, len);
		g << productname << '\n';
		int val = rand() % 10000;
		g << val << '\n';
		if (i == cautbin_idx)
			strcpy(cautbin, productname);
	}
	g << cautbin << '\n';
}

int main() {
	int test_count;
	cout << "Numarul de teste de generat : "; cin >> test_count;
	
	srand(time(NULL));
	for (int i = 0; i < test_count; ++i)
		GenerateTest(i);

	return 0;
}