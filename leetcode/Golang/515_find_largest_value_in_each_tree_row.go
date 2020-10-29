/*
 * @Author: tekky 
 * @Date: 2020-10-29 22:36:29 
 * @Last Modified by:   tekky 
 * @Last Modified time: 2020-10-29 22:36:29 
 */

 /**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func largestValues(root *TreeNode) (ans []int) {
    if root == nil { return }
    nodes := []*TreeNode{root}
    for len(nodes) > 0 {
        count := len(nodes)
        max := nodes[0].Val
        for ; count > 0; count-- {
            root = nodes[0]
            nodes = nodes[1:]
            if max < root.Val {
                max = root.Val
            }
            if root.Left != nil {
                nodes = append(nodes, root.Left)
            }
            if root.Right != nil {
                nodes = append(nodes, root.Right)
            }
        }
        ans = append(ans, max)
    }
    return
}