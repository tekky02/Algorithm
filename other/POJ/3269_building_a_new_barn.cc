// 3269_building_a_new_barn.cc
// created by tekky on 2020.11.12.

#include <cstdio>
#include <cmath>

int main(int argc, char const *argv[])
{
	int count;
	scanf("%d", &count);
	int X[10000];
	int Y[10000];

	int Xc[10000];
	int Yc[10000];

	int ans1 = 0;
	int i, j;
	int ans2 = 1;

	for (int i = 0; i < count; ++i) {
		scanf("%d%d", &X[i], &Y[i]);
		Xc[i] = X[i];
		Yc[i] = Y[i];
	}

	for (i = 0; i <= count / 2; ++i) {
		for (j = count - 1; j > i; --j) {
			if (X[j] < X[j-1]) {
				int temp = X[j];
				X[j] = X[j-1];
				X[j-1] = temp;
			}
		}
	}

	for (int k = 0; k < count; ++k) {
		ans1 += abs(X[i-1]-Xc[k]);
	}

	for (i = 0; i <= count / 2; ++i) {
		for (j = count - 1; j > i; --j) {
			if (Y[j] < Y[j-1]) {
				int temp = X[j];
				Y[j] = Y[j-1];
				Y[j-1] = temp;
			}
		}
	}

	// if (count % 2 == 0) {
	// 	if (X[i-2] != X[i-1]) ans2 *= 2;
	// 	if (Y[i-2] != Y[i-1]) ans2 *= 2;
	// }

	for (int k = 0; k < count; ++k) {
		ans1 += abs(Y[i-1]-Yc[k]);
	}

	printf("%d %d\n", ans1, ans2);
	return 0;
}