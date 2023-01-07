package sort

func heapSort(arr []int) []int {
	end := len(arr) - 1
	for i := end / 2; i >= 0; i-- {
		heapify(arr, i, end)
	}
	for end > 0 {
		arr[0], arr[end] = arr[end], arr[0]
		end--
		heapify(arr, 0, end)
	}
	return arr
}

// 大根堆
func heapify(arr []int, root, end int) {
	left, right := root*2+1, root*2+2
	for left <= end {
		max := left
		if right <= end && arr[right] > arr[left] {
			max = right
		}
		if arr[root] < arr[max] {
			arr[root], arr[max] = arr[max], arr[root]
			root = max
			left, right = root*2+1, root*2+2
		} else {
			break
		}
	}
}
