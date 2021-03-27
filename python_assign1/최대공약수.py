def gcd(m, n): #꼬리 재귀
    if n != 0:
        return gcd(n, m%n)
    else:
        return m


#while
def gcd2(m, n):
    while n != 0:
        m, n = n, m%n

    return m

print(gcd(48,18))   #6
print(gcd(0,11))    #11
print(gcd(18, 57))
print(gcd2(48,18))   #6
print(gcd2(0,11))    #11
print(gcd2(18, 57))
# 분할정복 재귀버전
def even(n):
    return n % 2 == 0

def odd(n):
    return n % 2 == 1

def gcd3(m, n):
    if m != 0 and n != 0:
        if even(m) and even(n):  # m, n 짝수일 때
            return 2 * gcd(m//2, n//2)
        elif even(m) and odd(n):  # m 짝수, n 홀수일 때
            return gcd(m//2, n)
        elif odd(m) and even(n):  # m홀수, n 짝수일 때
            return gcd(m, n//2)
        elif m <= n:              # 둘 다 홀수일 때
            return gcd(m, (n-m)//2)
        else:
            return gcd(n, (m-n)//2)

    else:
        if m == 0:
            return n
        else:
            return m

def even1(n):
    return n % 2 == 0

def odd1(n):
    return n % 2 == 1

def gcd4(m, n):
    def loop(m, n, k):
        if m != 0 and n != 0:
            if even(m) and even(n):
                return loop(m//2, n//2, 2 * k)
            elif even(m) and odd(n):
                return loop(m//2, n, k)
            elif odd(m) and even(n):
                return loop(m, n//2, k)
            elif m <= n:
                return loop(m, (n-m)//2, k)
            else:
                return loop(n, (m-n)//2, k)
        else:
            if m == 0:
                return n * k
            else:       # n == 0
                return m * k
    return loop(m, n, 1)


#while(나눠풀기)
def gcd(m, n):
    k = 1
    while m != 0 and n != 0:
        if even(m) and even(n):
            m, n, k = m//2, n//2, 2* k
        elif even(m) and odd(n):
            m = m//2
        elif odd(m) and even(n):
            n = n//2
        elif m <= n:
            n = (n-m)//2
        else:
            m, n = n, (m-n)//2

    if m == 0:
        return n * k
    else:     # n == 0
        return m * k


print(gcd(48,18))   #6
print(gcd(0,11))    #11
print(gcd(18, 57))
print(gcd2(48,18))   #6
print(gcd2(0,11))    #11
print(gcd2(18, 57))