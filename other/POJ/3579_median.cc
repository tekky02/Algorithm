// 3579_median.cc
// created by tekky on 2020.11.12.

#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

struct Solution {
	std::priority_queue<int> maxHeap;
	std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

	void addNum(int num) {
		if(maxHeap.empty())
            maxHeap.push(num);
        else if(maxHeap.size()>minHeap.size())
        {
            if(maxHeap.top()>num)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
            }
            else
                minHeap.push(num);       
        }
        else
        {
            if(minHeap.top()<num)
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
            }
            else
                maxHeap.push(num);
        }
		// maxHeap.push(num);
		// minHeap.push(maxHeap.top());
		// maxHeap.pop();
		// if (maxHeap.size() < minHeap.size()) {
		// 	maxHeap.push(minHeap.top());
		// 	minHeap.pop();
		// }
	}

	int median() {
		return maxHeap.top();
	}
};


int main(int argc, char const *argv[])
{
	// NOTE: TLE now...
	int count;
	std::vector<int> nums;
	while (~scanf("%d", &count)) {
		nums.resize(count);
		for (int i = 0; i < count; ++i) scanf("%d", &nums[i]);

		Solution s;
		std::vector<int> sequnce;
		for (int i = 0; i < nums.size() - 1; ++i) {
			for (int j = i + 1; j < nums.size(); ++j) {
				s.addNum(std::abs(nums[i] - nums[j]));
			}
		}
		// std::sort(sequnce.begin(), sequnce.end());
		printf("%d\n", s.median());
	}
	return 0;
}