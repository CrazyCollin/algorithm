package leetcode

var res [][]int
var visited map[int]int

func permute(nums []int) [][]int {
	res = [][]int{}
	visited = make(map[int]int)
	backTrack(nums, 0, []int{})
	return res
}

func backTrack(nums []int, lens int, path []int) {
	if len(nums) == len(path) {
		tmp := make([]int, len(path))
		copy(tmp, path)
		res = append(res, tmp)
	}
	for _, num := range nums {
		if visited[num] == 1 {
			continue
		}
		path = append(path, num)
		visited[num] = 1
		backTrack(nums, lens, path)
		visited[num] = 0
		path = path[:len(path)-1]
	}
}
