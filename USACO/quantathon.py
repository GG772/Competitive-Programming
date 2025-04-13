def compute_sum(N):
    total = 0.0
    result = -100000000000000000
    for n in range(1, N + 1):
        # a = (n - 1) / n
        a = 1
        term = a**n - a**n / n - n * (a**(n+1)) / (n + 1)
        total += term
        result = max(result, total)

    return result

if __name__ == "__main__":
    try:
        N = int(input("Enter a positive integer N: "))
        if N < 1:
            raise ValueError("N must be at least 1.")
        
        result = compute_sum(N)
        print(f"The value of the sum for N={N} is: {result}")
    except ValueError as e:
        print(f"Error: {e}")
