/**
 * @ Author: tekky
 * @ Create Time: 2020-10-26 11:13:16
 * @ Modified by: tekky
 * @ Modified time: 2020-10-26 11:14:39
 * @ Description:
 */

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func nextLargerNodes(head *ListNode) []int {
	result := make([]int, 10000)
	count := 0
	for ; head.Next != nil; head = head.Next {
		p := head.Next
		for ; p != nil && head.Val >= p.Val; p = p.Next {
		}
		if p == nil {
			result[count] = 0
		} else {
			result[count] = p.Val
		}
		count++
	}
	result[count] = 0
	return result[:count+1]
}