#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int f() {
	static int i = 1;
	return i++;
}

int main() {
	std::vector<int> nums(100);
	std::generate(nums.begin(), nums.end(), f);
	std::random_shuffle(nums.begin(), nums.end());
	std::copy(nums.cbegin(), nums.cend(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	std::cout << "the second larges is: ";
	int second;
	int max = nums.front();
	for (auto item : nums) {
		if (max < item) {
			second = max;
			max = item;
		}
	}
	std::cout << second << std::endl;
	return 0;
}
