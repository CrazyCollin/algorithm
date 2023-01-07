package leetcode

func generateMatrix(n int) [][]int {
	index := 1
	res := make([][]int, n)
	for i, _ := range res {
		res[i] = make([]int, n)
	}
	l, r, t, b := 0, n-1, 0, n-1
	for index <= n*n {
		for i := l; i <= r; i++ {
			res[t][i] = index
			index++
		}
		t++
		for i := t; i <= b; i++ {
			res[i][r] = index
			index++
		}
		r--
		for i := r; i >= l; i-- {
			res[b][i] = index
			index++
		}
		b--
		for i := b; i >= t; i-- {
			res[i][l] = index
			index++
		}
		l++
	}
	return res
}
