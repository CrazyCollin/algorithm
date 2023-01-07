package sort

func quickSort(arr []int, l, r int) {
	if l >= r {
		return
	}
	pivot := arr[(l+r)>>1]
	arr[l], arr[(l+r)>>1] = arr[(l+r)>>1], arr[l]
	i, j := l, r
	for i < j {
		for i < j && arr[j] >= pivot {
			j--
		}
		arr[i] = arr[j]
		for i < j && arr[i] <= pivot {
			i++
		}
		arr[j] = arr[i]
	}
	arr[i] = pivot
	quickSort(arr, l, i-1)
	quickSort(arr, i+1, r)
}
