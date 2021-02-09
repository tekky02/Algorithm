/* definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
package solution

func maxPathSum(root *TreeNode) int {
	if root == nil {
		return 0
	}
	res := math.MinInt64
	var helper func(node *TreeNode) int
	helper = func(node *TreeNode) int {
		if node == nil {
			return 0
		}
		leftMax := helper(node.Left)
		rightMax := helper(node.Right)
		res = max(res, node.Val+leftMax+rightMax)
		return max(max(node.Val+leftMax, node.Val+rightMax), 0)
	}
	helper(root)
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
