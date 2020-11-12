// 3579_median.cc
// created by tekky on 2020.11.12.

#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Solution {
	std::priority_queue<int> maxHeap;
	std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

	void addNum(int num) {
		maxHeap.push(num);
		minHeap.push(maxHeap.top());
		maxHeap.pop();
		if (maxHeap.size() < minHeap.size()) {
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
	}

	int median() {
		return maxHeap.top();
	}
};


int main(int argc, char const *argv[])
{
	

	int count;
	std::vector<int> nums;
	while (std::cin >> count) {
		nums.resize(count);
		for (int i = 0; i < count; ++i) {
			std::cin >> nums[i];
		}

		Solution s;
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = i + 1; j < nums.size(); ++j) {
				s.addNum(std::abs(nums[i] - nums[j]));
			}
		}
		std::cout << s.median() << std::endl;
	}
	return 0;
}