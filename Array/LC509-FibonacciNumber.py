class Solution:
    def fib(self, N: int) -> int:
        # This is the Fibonacci sequence
        f = [0 for _ in range(31)]
        # Initialization
        f[0] = 0
        f[1] = 1
        # Loop through the Fibonacci sequence
        for i in range(2, N + 1):
            f[i] = f[i - 1] + f[i - 2]
        return f[N]
