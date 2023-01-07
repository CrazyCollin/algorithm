package structures

type ListNode struct {
	Val  int
	Next *ListNode
}

func ListToInts(head *ListNode) []int {
	var res []int
	for head != nil {
		res = append(res, head.Val)
		head = head.Next
	}
	return res
}

func IntsToList(nums []int) *ListNode {
	if len(nums) == 0 {
		return nil
	}
	dummyNode := &ListNode{}
	curr := dummyNode
	for _, v := range nums {
		curr.Next = &ListNode{Val: v}
		curr = curr.Next
	}
	return dummyNode.Next
}
