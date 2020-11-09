/*
* @Author: Teddyky
* @Date:   2020-11-09 20:26:34
* @Last Modified by:   Teddyky
* @Last Modified time: 2020-11-09 20:26:57
*/
func maxSubArray(nums []int) int {
    ans, sum := nums[0], nums[0]
    for i := 1; i < len(nums); i++ {
        if sum > 0 {
            sum += nums[i]
        } else {
            sum = nums[i]
        }
        if sum > ans {
            ans = sum
        }
    }
    return ans
}