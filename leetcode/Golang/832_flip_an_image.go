/*
* @Author: Teddyky
* @Date:   2020-11-11 10:16:38
* @Last Modified by:   Teddyky
* @Last Modified time: 2020-11-11 10:16:51
*/
func flipAndInvertImage(A [][]int) [][]int {
    m, n := len(A), len(A[0])
    for row := 0; row < m; row++ {
        for col := 0; col < (n+1)/2; col++ {
            A[row][col], A[row][n - col - 1] = 1 - A[row][n - col - 1], 1 - A[row][col]
        }
    }
    return A
}