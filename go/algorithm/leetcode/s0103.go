package leetcode

func zigzagLevelOrder(root *TreeNode) [][]int {
	if root == nil {
		return [][]int{}
	}
	queue := []*TreeNode{root}
	res := make([][]int, 0)
	flag := true
	for len(queue) > 0 {
		length := len(queue)
		tmp := make([]int, 0, length)
		for i := 0; i < length; i++ {
			if queue[i].Left != nil {
				queue = append(queue, queue[i].Left)
			}
			if queue[i].Right != nil {
				queue = append(queue, queue[i].Right)
			}
			if flag {
				tmp = append(tmp, queue[i].Val)
			} else {
				tmp = append(append([]int{queue[i].Val}), tmp...)
			}
		}
		flag = !flag
		queue = queue[length:]
		res = append(res, tmp)
	}
	return res
}
