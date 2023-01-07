package leetcode

func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	dummyNode := &ListNode{Val: -1, Next: nil}
	curr := dummyNode
	for list1 != nil && list2 != nil {
		if list1.Val <= list2.Val {
			curr.Next = list1
			list1 = list1.Next
		} else {
			curr.Next = list2
			list2 = list2.Next
		}
		curr = curr.Next
	}
	if list1 != nil {
		curr.Next = list1
	} else {
		curr.Next = list2
	}
	return dummyNode.Next
}

func mergeTwoListsInRecurrence(list1 *ListNode, list2 *ListNode) *ListNode {
	if list1 == nil {
		return list2
	} else if list2 == nil {
		return list1
	}
	if list1.Val <= list2.Val {
		list1.Next = mergeTwoListsInRecurrence(list1.Next, list2)
		return list1
	}
	list2.Next = mergeTwoListsInRecurrence(list1, list2.Next)
	return list2
}
