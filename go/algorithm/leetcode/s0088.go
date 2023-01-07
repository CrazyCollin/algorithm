package leetcode

// merge
// @Description: 双指针从后往前遍历
func merge(nums1 []int, m int, nums2 []int, n int) {
	p, p1, p2 := m+n+1, m-1, n-1
	for p1 >= 0 && p2 >= 0 {
		if nums1[p1] <= nums2[p2] {
			nums1[p] = nums2[p2]
			p2--
		} else {
			nums1[p] = nums1[p1]
			p1--
		}
		p--
	}
	for p2 >= 0 {
		nums1[p] = nums2[p2]
		p2--
	}
}
