package leetcode

type MyQueue struct {
	s1, s2 []int
}

func Constructor() MyQueue {
	return MyQueue{}
}

func (this *MyQueue) Push(x int) {
	this.s1 = append(this.s1, x)
}

func (this *MyQueue) Pop() int {
	this.in2out()
	res := this.s2[len(this.s2)-1]
	this.s2 = this.s2[:len(this.s2)-1]
	this.out2in()
	return res
}

func (this *MyQueue) Peek() int {
	this.in2out()
	res := this.s2[len(this.s2)-1]
	this.out2in()
	return res
}

func (this *MyQueue) Empty() bool {
	if len(this.s1) == 0 && len(this.s2) == 0 {
		return true
	}
	return false
}

func (this *MyQueue) in2out() {
	for _, i := range this.s1 {
		this.s2 = append(this.s2, i)
	}
	this.s1 = []int{}
}

func (this *MyQueue) out2in() {
	for _, i := range this.s2 {
		this.s1 = append(this.s1, i)
	}
	this.s2 = []int{}
}
