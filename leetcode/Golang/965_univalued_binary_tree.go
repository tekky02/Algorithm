/*
 * @Author: tekky 
 * @Date: 2020-10-29 22:45:52 
 * @Last Modified by:   tekky 
 * @Last Modified time: 2020-10-29 22:45:52 
 */
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func isUnivalTree(root *TreeNode) bool {
    if root == nil { return true }
    return unival(root, root.Val)
}

func unival(root *TreeNode, target int) bool {
    if root != nil {
        if root.Val != target { return false }
        flag := unival(root.Left, target)
        if !flag { return false }
        return unival(root.Right, target)
    }
    return true
}
