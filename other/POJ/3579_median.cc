#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int *a;
int m, n;

bool test(int mid)
{
	int count = 0;
	for (int i = 0;i<n; i++)
	{
		count += n - (lower_bound(a, a + n, a[i] + mid) - a);
	}
	return count > m;
}
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		m = n * (n - 1) / 4;
		a = new int[n];
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		int L = 0, R = a[n - 1] - a[0];
		while (R > L + 1)
		{
			int mid = (R + L) >> 1;
			if (test(mid))
			{
				L = mid;
			}
			else
			{
				R = mid;
			}
			
		}
		delete a;
		printf("%d\n", L);
	}
	return 0;
}