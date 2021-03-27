def fac(n):
    if n > 1:
        return fac(n-1) * n
    else:
        return 1

print(fac(3))

def fac2(n):
    def loop(n, ans):
        if n > 1:
            return loop(n-1, ans*n)
        else:
            return ans
    return loop(n, 1)

print(fac2(4))

def fac3(n):
    ans = 1
    while n > 1:
        n, ans = n-1, ans*n
    return ans

print(fac3(3))