def trinum(n): #꼬리재귀
    def loop(n, ans):
        if n > 0:
            return n + loop(n-1, n + ans)
        else:
            return 0
    return loop(n,0)

print(trinum(-2))

def trinum2(n): #while
    ans = 0
    while n > 0:
        ans = n + ans
        n = n - 1
    return ans
print(trinum2(3))

def trinum3(n): #재귀
    if n > 0:
        return n + trinum3(n-1)
    else:
        return 0
print(trinum3(2)) 