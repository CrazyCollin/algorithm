package leetcode

func sortedSquares(nums []int) []int {
	start, end, index := 0, len(nums)-1, len(nums)-1
	res := make([]int, len(nums))
	for start <= end {
		leftMax, rightMax := nums[start]*nums[start], nums[end]*nums[end]
		if leftMax > rightMax {
			res[index] = leftMax
			start++
			index--
		} else {
			res[index] = rightMax
			end--
			index--
		}
	}
	return res
}
