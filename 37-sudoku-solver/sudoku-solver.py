class Solution:
    def __init__(self):
        self.r = [0] * 9 # rows masks
        self.c = [0] * 9 # cols masks
        self.b = [0] * 9 # boxes masks
        self.solved = False

    def isSafe(self, i, j, pos) -> bool:
        mask = (1 << pos)
        if not (self.r[i] & mask) and not (self.c[j] & mask):
            box = (i // 3) * 3 + (j // 3)
            return not (self.b[box] & mask)
        else:
            return False
    def place(self, i, j, pos) -> None:
        mask = (1 << pos)
        self.r[i] = self.r[i] | mask
        self.c[j] = self.c[j] | mask
        box = (i // 3) * 3 + (j // 3)
        self.b[box] = self.b[box] | mask
    def unplace(self, i, j, pos) -> None:
        mask = (1 << pos)
        self.r[i] = self.r[i] ^ mask
        self.c[j] = self.c[j] ^ mask
        box = (i // 3) * 3 + (j // 3)
        self.b[box] = self.b[box] ^ mask
    def backtrack(self, board: list[list[str]], i, j) -> None:
        if i >= 9:
            self.solved = True
            return
        elif j >= 9:
            self.backtrack(board, i + 1, 0)
            return
        else:
            if board[i][j] == '.':
                for num in range(9):
                    if self.isSafe(i, j, num):
                        self.place(i, j, num)
                        board[i][j] = str(num + 1)

                        self.backtrack(board, i, j + 1)

                        if self.solved:
                            return 
                        else:
                            board[i][j] = '.'
                            self.unplace(i, j, num)
            else:
                self.backtrack(board, i, j + 1)
        

    def solveSudoku(self, board: List[List[str]]) -> None:
        for i in range(9):
            for j in range(9):
                if board[i][j] != '.':
                    mask = 1 << (int(board[i][j]) - 1)
                    self.r[i] = self.r[i] | mask
                    self.c[j] = self.c[j] | mask
                    box = (i // 3) * 3 + (j // 3)
                    self.b[box] = self.b[box] | mask
        
        self.backtrack(board, 0, 0)