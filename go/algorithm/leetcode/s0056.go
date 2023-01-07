package leetcode

import "sort"

/*
如果cs的尾部小于当前区间的头，即不相交，添加到结果集，并将尾部指到当前区间的尾部。
如果cs的尾部小于当前区间的尾，即有重合区域，合并： 将当前区间尾赋到cs的尾。
*/

func merge_(intervals [][]int) [][]int {
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})
	var res [][]int
	var cs []int
	for _, interval := range intervals {
		if len(res) == 0 || cs[1] < interval[0] {
			res = append(res, interval)
			cs = interval
		} else if cs[1] < interval[1] {
			cs[1] = interval[1]
		}
	}
	return res
}
