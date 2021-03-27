def sumrange(m, n):
    if m <= n:
        return m + sumrange(m+1, n)
    else:
        return 0

def sumrange1(m, n):
    def loop(m, total):
        if m<= n:
            return loop(m+1, total+m)
        else:
            return total
    return loop(m, 0)

def sumrange2(m, n):
    total = 0
    while m <= n:
        total = total + m
        m = m + 1
    return total

print(sumrange(3,2)) #0
print(sumrange(3,3)) #3
print(sumrange(3,4)) #7
print(sumrange(3,6)) #18
print(sumrange(1,10)) #55
print(sumrange(-5,-2))
print("////////////////")
print(sumrange1(3,2))
print(sumrange1(3,3))
print(sumrange1(3,4))
print(sumrange1(3,6))
print(sumrange1(1,10))
print(sumrange1(-5,-2))
print("..........")
print(sumrange2(3,2))
print(sumrange2(3,3))
print(sumrange2(3,4))
print(sumrange2(3,6))
print(sumrange2(1,10))
print(sumrange2(-5,-2))