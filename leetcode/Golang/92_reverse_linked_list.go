/*
 * @Author: tekky
 * @Date: 2020-12-06 16:50:35
 * @Last Modified by:   tekky
 * @Last Modified time: 2020-12-06 16:50:35
 */
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseBetween(head *ListNode, m int, n int) *ListNode {
	var previous, current *ListNode = nil, head
	help := &ListNode{Next: head}
	previous = help
	count := 0
	for count != m-1 && current != nil {
		previous, current = current, current.Next
		count++
	}
	before_m, mth_node := previous, current
	count = n - m
	for count != 0 {
		current = current.Next
		count--
	}
	after_n := current.Next
	current.Next = nil
	current = mth_node
	previous = nil
	var next *ListNode
	for current != nil {
		next = current.Next
		current.Next = previous
		previous = current
		current = next
	}

	before_m.Next, mth_node.Next = previous, after_n
	return help.Next
}