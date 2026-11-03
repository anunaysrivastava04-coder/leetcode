class Solution:
    def solve(self, board: list[list[str]]) -> None:
        row = len(board) 
        column = len(board[0])

        def dfs (r,c):
            if (r>= row or r<0) or (c>=column or c<0):
                return 
            if board[r][c] != 'O':
                return 
            board[r][c]='#'
            dfs(r+1 , c)
            dfs(r-1 , c)
            dfs(r , c+1)
            dfs(r , c-1)

        for r in range (row):
            for c in range (column):
                if (c==0 or c==column-1 or r==0 or r==row-1) and board[r][c] == 'O':
                    dfs(r,c)

        for r in range(row):
            for c in range(column):
                if board[r][c] == 'O':
                    board[r][c] = 'X'
                elif board[r][c] == '#':
                    board[r][c] = 'O'
            
        
        