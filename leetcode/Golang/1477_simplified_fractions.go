import "fmt"

/*
 * @Author: tekky
 * @Date: 2020-10-30 14:39:28
 * @Last Modified by:   tekky
 * @Last Modified time: 2020-10-30 14:39:28
 */
func simplifiedFractions(n int) (ans []string) {
	if n == 1 {
		return nil
	}
	for i := 1; i < n; i++ {
		for j := i + 1; j <= n; j++ {
			if gcd(i, j) > 1 {
				continue
			}
			ans = append(ans, fmt.Sprintf("%d/%d", i, j))
		}
	}
	return
}

func gcd(m, n int) int {
	q := n % m
	for q != 0 {
		n, m = m, q
		q = n % m
	}
	return m
}