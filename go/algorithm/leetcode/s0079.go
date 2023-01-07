package leetcode

func exist(board [][]byte, word string) bool {
	//初始化visited表
	visited := make([][]bool, len(board))
	for i := 0; i < len(board); i++ {
		visited[i] = make([]bool, len(board[0]))
	}
	for i := 0; i < len(board); i++ {
		for j := 0; j < len(board[0]); j++ {
			if searchWord(board, visited, word, 0, i, j) {
				return true
			}
		}
	}
	return false
}

func searchWord(board [][]byte, isVisited [][]bool, word string, index, x, y int) bool {
	if index >= len(word) {
		return true
	}
	if x < 0 || x >= len(board) || y < 0 || y >= len(board[0]) || board[x][y] != word[index] || isVisited[x][y] {
		return false
	}
	isVisited[x][y] = true
	res := searchWord(board, isVisited, word, index+1, x+1, y) || searchWord(board, isVisited, word, index+1, x-1, y) || searchWord(board, isVisited, word, index+1, x, y+1) || searchWord(board, isVisited, word, index+1, x, y-1)
	if res {
		return true
	} else {
		isVisited[x][y] = false
		return false
	}
}
