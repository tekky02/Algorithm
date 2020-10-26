/**
 * @ Author: tekky
 * @ Create Time: 2020-10-26 09:13:14
 * @ Modified by: tekky
 * @ Modified time: 2020-10-26 11:14:43
 * @ Description: find the majority element in an array
 * @ Note: it is guaranteed an element appears more than n/2 times.
 */

func majorityElement(nums []int) (ans int) {
	major := make(map[int]int)
	for _, v := range nums {
		major[v]++
	}
	for i, v := range major {
		if v > len(nums)/2 {
			// there is one element occurs more than n/2 times.
			// that is the answer.
			ans = i
			break
		}
	}
	return
}