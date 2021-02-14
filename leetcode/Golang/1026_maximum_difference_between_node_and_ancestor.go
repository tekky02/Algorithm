/*
* @Author: Teddyky
* @Date:   2020-11-10 13:32:32
* @Last Modified by:   Teddyky
* @Last Modified time: 2020-11-10 13:32:42
*/
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxAncestorDiff(root *TreeNode) (ans int) {
    helper(root, root.Val, &ans)
    // temp := max(abs(root.Val - minv), abs(root.Val - maxv))
    // ans = max(ans, temp)
    return
}

func min(a, b int) int {
    if a < b { return a }
    return b
}

func max(a, b int) int {
    if a > b { return a }
    return b
}

func abs(num int) int {
    if num < 0 { return -num }
    return num
}

func helper(root *TreeNode, val int, ans *int) (int, int) {
    if root != nil {
        leftMin, leftMax := helper(root.Left, root.Val, ans)
        rightMin, rightMax := helper(root.Right, root.Val, ans)
        minv, maxv := min(leftMin, rightMin), max(leftMax, rightMax)
        minv, maxv = min(minv, val), max(maxv, val)
        temp := max(abs(val - minv), abs(val - maxv))
        *ans = max(*ans, temp)
        return minv, maxv
    }
    return val, val
} 

