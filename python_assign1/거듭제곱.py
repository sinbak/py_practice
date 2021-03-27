def power(b, n):
    if n > 0:
        return b * power(b, n-1)
    else:
        return 1

def power1(b, n):
    def loop(n,prod): #prod : 계산결과 누적기
        if n > 0:
            return loop(n-1,b*prod)
        else:
            return prod
    return loop(n,1)

def power2(b,n): #while
    prod = 1
    while n > 0:
        prod = b* prod
        n = n - 1
    return prod

def power3(b, n):
    if n > 0:
        if n%2 == 0:
            return power(b*b, n//2)
        else:
            return 1

def power4(b, n): #2 7 꼬리 재귀함수
    def loop(b,n,prod):
        if n > 0:
            if n % 2 == 0:
                return loop(b*b, n//2, prod)
            else:
                return loop(b, n-1, b*prod)
        else:
            return prod
    return loop(b,n,1)

def power5(b,n): #꼬리재귀를 while 문으로
    prod = 1
    while n > 0:
        if n % 2 == 0:
            b = b*b
            n = n//2
        else:
            n = n - 1
            prod = b * prod
    return prod

print(power(2,5))
print(power1(2,5))
print(power2(2,5))