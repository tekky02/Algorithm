/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func findTilt(root *TreeNode) (ans int) {
    helper(root, &ans)
    return
}

func absDiff(a, b int) int {
    num := a - b
    if num > 0 {
        return num
    }
    return -num
}

func helper(root *TreeNode, ans *int) int {
    if root == nil {
        return 0
    }
    left, right := helper(root.Left, ans), helper(root.Right, ans)
    *ans += absDiff(left, right)
    return left + right + root.Val
}