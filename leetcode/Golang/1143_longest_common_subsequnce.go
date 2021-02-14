/*
* @Author: Teddyky
* @Date:   2020-11-12 20:02:23
* @Last Modified by:   Teddyky
* @Last Modified time: 2020-11-12 20:02:36
*/
func longestCommonSubsequence(text1 string, text2 string) (ans int) {
    bytes1, bytes2 := []byte(text1), []byte(text2)
    C := make([][]int, len(bytes1) + 1)
    for i, _ := range C {
        C[i] = make([]int, len(bytes2) + 1)
    }
    
    i, j := 1, 1
    for ; i <= len(bytes1); i++ {
        for j = 1; j <= len(bytes2); j++ {
            C[i][j] = max(C[i-1][j], C[i][j-1], C[i-1][j-1]+t(bytes1[i-1], bytes2[j-1]))
        }
    }
    return C[i-1][j-1]
}

func t(a, b byte) int {
    if a == b { return 1 }
    return 0
}

func max(a, b, c int) (max int) {
    max = a
    if max < b { max = b }
    if max < c { max = c }
    return
}

