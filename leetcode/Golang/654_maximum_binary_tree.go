/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

// 654_maximum_binary_tree.go
// created by tekky on 2020.11.12.

func constructMaximumBinaryTree(nums []int) *TreeNode {
    return helper(nums)
}

func helper(nums []int) *TreeNode {
    if len(nums) == 0 {
        return nil
    }
    idx, max := 0, nums[0]
    for i, v := range nums {
        if max < v {
            idx, max = i, v
        }
    }
    return &TreeNode {
        Val: max, 
        Left: helper(nums[:idx]),
        Right: helper(nums[idx+1:]),
    }
}

