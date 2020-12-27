class NQueens:
    def setN(self, N):
        self.N = N
        self.case = 0
        self.col = [False]*self.N
        self.antiDiagonal = [False]*(2*self.N-1)
        self.diagonal = [False]*(2*self.N-1)
    def dfs(self, y):
        if y == self.N:
            self.case += 1
            return
        for x in range(self.N):
            if not (self.col[x] or self.antiDiagonal[x+y] or self.diagonal[self.N-1+x-y]):
                self.col[x] = self.antiDiagonal[x+y] = self.diagonal[self.N-1+x-y] = True
                self.dfs(y+1)
                self.col[x] = self.antiDiagonal[x+y] = self.diagonal[self.N-1+x-y] = False
nq = NQueens()
nq.setN(int(input()))
nq.dfs(0)
print(nq.case)