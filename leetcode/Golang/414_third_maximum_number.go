/*
* @Author: Teddyky
* @Date:   2020-11-12 16:46:34
* @Last Modified by:   Teddyky
* @Last Modified time: 2020-11-12 16:46:42
*/
func thirdMax(nums []int) int {
    first, second, third := math.MinInt64, math.MinInt64, math.MinInt64
    
    for _, v := range nums {
        if v == first || v == second || v == third {
            continue
        }
        switch {
        case v > first:
            first, second, third = v, first, second
        case v > second:
            second, third = v, second
        case v > third:
            third = v
        }
    }
    if third == math.MinInt64 {
        return first
    }
    return third
}

