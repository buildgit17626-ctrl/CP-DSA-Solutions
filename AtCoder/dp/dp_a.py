import sys

def solve():
    input = sys.stdin.read
    data = input().split()
    
    if not data:
        return

    n = int(data[0])
    h = [int(x) for x in data[1:]]

    dp = [0] * n
    dp[1] = abs(h[1] - h[0])

    for i in range(2, n):
        cost_one = dp[i - 1] + abs(h[i] - h[i - 1])
        cost_two = dp[i - 2] + abs(h[i] - h[i - 2])
        dp[i] = min(cost_one, cost_two)

    print(dp[n - 1])

if __name__ == "__main__":
    solve()