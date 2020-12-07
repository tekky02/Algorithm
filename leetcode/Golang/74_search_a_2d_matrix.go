/*
 * @Author: tekky
 * @Date: 2020-12-07 09:59:16
 * @Last Modified by:   tekky
 * @Last Modified time: 2020-12-07 09:59:16
 */
func searchMatrix(matrix [][]int, target int) bool {
	m := len(matrix)
	if m == 0 {
		return false
	}
	n := len(matrix[0])
	low, high := 0, m*n-1
	var mid int
	for low <= high {
		mid = low + (high-low)/2
		i, j := mid/n, mid%n
		if target < matrix[i][j] {
			high = mid - 1
		} else if target > matrix[i][j] {
			low = mid + 1
		} else {
			return true
		}
	}
	return false
}