package sort

func mergeSort(arr []int, l, r int) {
	if l < r {
		m := (l + r) >> 1
		mergeSort(arr, l, m)
		mergeSort(arr, m+1, r)
		merge(arr, l, m, r)
	}
}

func merge(arr []int, l, m, r int) {
	i, j := l, m+1
	var tmp []int
	for i <= m && j <= r {
		if arr[i] <= arr[j] {
			tmp = append(tmp, arr[i])
			i++
		} else {
			tmp = append(tmp, arr[j])
			j++
		}
	}
	if i <= m {
		tmp = append(tmp, arr[i:m+1]...)
	} else {
		tmp = append(tmp, arr[j:r+1]...)
	}
	copy(arr[l:r+1], tmp)
}
