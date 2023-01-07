package leetcode

func removeElements(head *ListNode, val int) *ListNode {
	if head == nil {
		return head
	}
	dummy := &ListNode{
		Val:  -1,
		Next: head,
	}
	curr := head
	for curr != nil && curr.Next != nil {
		if curr.Next.Val == val {
			curr.Next = curr.Next.Next
		} else {
			curr = curr.Next
		}
	}
	return dummy.Next
}
