package leetcode

func lengthOfLongestSubstring(s string) int {
	num := len(s)
	if num <= 1 {
		return num
	}
	maxLen := 1
	left, right, win := 0, 0, make(map[byte]bool)
	for right < num {
		rightChar := s[right]
		for win[rightChar] {
			delete(win, s[left])
			left++
		}
		if right-left+1 > maxLen {
			maxLen = right - left + 1
		}
		win[rightChar] = true
		right++
	}
	return maxLen
}
