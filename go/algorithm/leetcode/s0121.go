package leetcode

func maxProfit(prices []int) int {
	if len(prices) < 1 {
		return 0
	}
	min, res := prices[0], 0
	for i := 1; i < len(prices); i++ {
		if prices[i]-min > res {
			res = prices[i] - min
		}
		if prices[i] < min {
			min = prices[i]
		}
	}
	return res
}
