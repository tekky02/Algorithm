// 1608_parencodings.cc
// created by tekky on 2020.11.5.

#include <cstdio>
#include <vector>
#include <iostream>

int main() {
	int n;
	std::vector<int> sequnce;
	std::cin >> n;
	
	for (int i = 0; i < n; ++i) {
		int count;
		std::cin >> count;
		sequnce.resize(count);
		for (int i = 0; i < count; ++i)
			std::scanf("%d", &sequnce[i]);
		
	}
}
