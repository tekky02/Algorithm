/**
 * @ Author: tekky
 * @ Create Time: 2020-10-26 11:31:48
 * @ Modified by: tekky
 * @ Modified time: 2020-10-26 11:43:11
 */

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

var ans []int

func preorderTraversal(root *TreeNode) []int {
	ans = ans[:0]
	handler(root)
	return ans
}

func handler(root *TreeNode) {
	if root != nil {
		ans = append(ans, root.Val)
		handler(root.Left)
		handler(root.Right)
	}
}