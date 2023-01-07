package leetcode

func twoSum(nums []int, target int) []int {
	numMap := make(map[int]int)
	for k, v := range nums {
		if idx, ok := numMap[target-v]; ok {
			return []int{idx, k}
		}
		numMap[v] = k
	}
	return nil
}
