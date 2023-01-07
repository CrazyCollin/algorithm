package leetcode

type myNode struct {
	val  int
	prev *myNode
	next *myNode
}

type MyLinkedList struct {
	size int
	head *myNode
	tail *myNode
}

func Constructor_() MyLinkedList {
	head, tail := &myNode{}, &myNode{}
	head.next = tail
	tail.prev = head
	return MyLinkedList{
		size: 0,
		head: head,
		tail: tail,
	}
}

func (l *MyLinkedList) Get(index int) int {
	if index < 0 || index >= l.size {
		return -1
	}
	var curr *myNode
	if index < l.size-index {
		curr = l.head
		for i := 0; i < index; i++ {
			curr = curr.next
		}
		return curr.next.val
	} else {
		curr = l.tail
		for i := 0; i < l.size-index; i++ {
			curr = curr.prev
		}
		return curr.val
	}
}

func (l *MyLinkedList) AddAtHead(val int) {
	l.AddAtIndex(0, val)
}

func (l *MyLinkedList) AddAtTail(val int) {
	l.AddAtIndex(l.size, val)
}

func (l *MyLinkedList) AddAtIndex(index int, val int) {
	if index > l.size {
		return
	}
	var prev, next *myNode
	var curr *myNode
	if index < l.size-index {
		curr = l.head
		for i := 0; i < index; i++ {
			curr = curr.next
		}
		prev = curr
		next = curr.next
	} else {
		curr = l.tail
		for i := 0; i < l.size-index; i++ {
			curr = curr.prev
		}
		prev = curr.prev
		next = curr
	}
	newNode := &myNode{
		val:  val,
		prev: prev,
		next: next,
	}
	prev.next = newNode
	next.prev = newNode
	l.size++
}

func (l *MyLinkedList) DeleteAtIndex(index int) {
	if index < 0 || index >= l.size {
		return
	}
	var prev, next *myNode
	var curr *myNode
	if index < l.size-index {
		curr = l.head
		for i := 0; i < index; i++ {
			curr = curr.next
		}
		prev = curr
		next = curr.next.next
	} else {
		curr = l.tail
		for i := 0; i < l.size-index; i++ {
			curr = curr.prev
		}
		prev = curr.prev
		next = curr.next
	}
	prev.next = next
	next.prev = prev
	l.size--
}
