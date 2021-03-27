def mul(m, n):
    if n > 0:
        return m + mul(m, n-1)
    else:
        return 0

def mul2(m, n):
    def loop(n, ans):
        if n > 0:
            return m + loop(n-1, ans)
        else:
            return ans
    return loop(n, 0)

def mul3(m, n):
    ans = 0
    while n > 0:
        if n % 2 == 0:
            m, n, ans = m+m,n/2,ans
        else:
            m, n, ans = m, n-1, m+ans
    return ans

print(mul(3,6))
print(mul2(3,6))
print(mul3(2,5))
###############################################################################

def fastmult(m,n):
    if n > 0:
        if n % 2 == 0:
            return fastmult(m+m,n/2)
        else:
            return m + fastmult(m,n-1)
    else:
        return 0

def fastmult2(m,n):
    def loop(m,n,ans):
        if n > 0:
            if n % 2 == 0:
                return loop(m+m,n/2,ans)
            else:
                return loop(m,n-1,m+ans)
        else:
            return ans

    return loop(m,n,0)

def fastmult3(m,n):
    ans = 0
    while n > 0:
        if n % 2 == 0:
            m, n, ans = m+m,n/2,ans
        else:
            m, n, ans = m, n-1, m+ans

    return ans

print(fastmult(3,6))
print("------------------")

print(fastmult2(3,6))
print("------------------")

print(fastmult3(2,6))
print("------------------")