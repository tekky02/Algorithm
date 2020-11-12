// 2366_sacrament_of_the_sum.cc
// created by tekky on 2020.11.12.

#include <iostream>
#include <vector>

bool binary_search(std::vector<int> const& v, int target) {
	int left = 0;
	int right = v.size();
	while (left <= right) {
		int mid = (right - left) / 2 + left;
		if (v[mid] == target) return true;
		if (v[mid] > target) right = mid - 1;
		if (v[mid] < target) left = mid + 1;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int n;
	const int Sum = 10000;
	std::cin >> n;
	std::vector<int> nums1(n);
	for (int i = 0; i < n; ++i) 
		std::cin >> nums1[i];
	std::cin >> n;
	// std::vector<int> nums2(n);
	int num;
	bool find = false;
	for (int i = 0; i < n; ++i) {
		std::cin >> num;
		if (binary_search(nums1, Sum-num)) {
			find = true;
		}
	}
	std::cout << (find ? "YES" : "NO") << std::endl;
	// for every item in nums1, find if there is an item (Sum - item) in nums2
	// bool find = false;
	// for (int i = 0; i < nums1.size(); ++i) {
	// 	if (binary_search(nums2, Sum - nums1[i])) {
	// 		find = true;
	// 		break;
	// 	}
	// }
	// std::cout << (find ? "YES" : "NO") << std::endl;
	return 0;
}