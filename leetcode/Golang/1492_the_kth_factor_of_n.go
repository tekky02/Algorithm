/*
 * @Author: tekky
 * @Date: 2020-10-30 14:48:14
 * @Last Modified by:   tekky
 * @Last Modified time: 2020-10-30 14:48:14
 */
func kthFactor(n int, k int) int {
	var count int
	for i := 1; i <= n; i++ {
		if n%i == 0 {
			count++
		}
		if count == k {
			return i
		}
	}
	return -1
}

