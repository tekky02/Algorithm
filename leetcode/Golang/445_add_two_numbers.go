/*
 * @Author: tekky
 * @Date: 2020-11-08 16:11:25
 * @Last Modified by: tekky
 * @Last Modified time: 2020-11-08 16:11:58
 */
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var nums1, nums2 []int
	for l1 != nil {
		nums1 = append(nums1, l1.Val)
		l1 = l1.Next
	}
	for l2 != nil {
		nums2 = append(nums2, l2.Val)
		l2 = l2.Next
	}
	var head *ListNode
	r := 0
	for len(nums1) > 0 && len(nums2) > 0 {
		n1, n2 := nums1[len(nums1)-1], nums2[len(nums2)-1]
		nums1, nums2 = nums1[:len(nums1)-1], nums2[:len(nums2)-1]
		q := n1 + n2 + r
		r = q / 10
		head = &ListNode{
			Val:  q % 10,
			Next: head,
		}
	}
	var n int
	for len(nums1) > 0 {
		n, nums1 = nums1[len(nums1)-1], nums1[:len(nums1)-1]
		q := n + r
		r = q / 10
		head = &ListNode{q % 10, head}
	}
	for len(nums2) > 0 {
		n, nums2 = nums2[len(nums2)-1], nums2[:len(nums2)-1]
		q := n + r
		r = q / 10
		head = &ListNode{q % 10, head}
	}
	if r == 1 {
		head = &ListNode{r, head}
	}
	return head
}