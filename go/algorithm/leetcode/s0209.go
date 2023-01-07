package leetcode

func minSubArrayLen(target int, nums []int) int {
	start, res, sum := 0, len(nums)+1, 0
	for i := 0; i < len(nums); i++ {
		sum += nums[i]
		// 达到条件，开始缩小窗口
		for sum >= target {
			subLength := i - start + 1
			if subLength < res {
				res = subLength
			}
			sum -= nums[start]
			start++
		}
	}
	if res == len(nums)+1 {
		return 0
	}
	return res
}
