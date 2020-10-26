/**
 * @ Author: tekky
 * @ Create Time: 2020-10-26 11:48:43
 * @ Modified by: tekky
 * @ Modified time: 2020-10-26 11:49:04
 * @ Description:
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

func postorderTraversal(root *TreeNode) []int {
	ans = ans[:0]
	handler(root)
	return ans
}

func handler(root *TreeNode) {
	if root != nil {
		handler(root.Left)
		handler(root.Right)
		ans = append(ans, root.Val)
	}
}