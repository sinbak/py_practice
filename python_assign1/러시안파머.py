def russian_mult(m, n):
    def loop(m, n):
        if n > 1:
            if n % 2 == 0:
                return loop(m*2,n//2)
            else:
                return m + loop(m*2,n//2)
        else: #n == 1
            return m
    if n > 0:
        return loop(m, n)
    else:
        return 0

print(russian_mult(57,86))

def russian_mult1(m,n):
    def loop(m,n,a):
        print("loop(",m,n,a,")")
        if n>1:
            if n%2==0:
                return loop(2 * m, n // 2,a)
            else:

                return loop(2 * m, n // 2,a+m)
        else:
            return a+m
    if n>0:
        return loop(m,n,0)
    else:
        return 0

print(russian_mult1(57,86))

def russian_mult2(m,n):
    if n>0:
        a = 0
        while n>1:
            if n%2==0:
                m,n = 2 * m, n // 2
            else:
                m,n,a =2 * m, n // 2,a+m

        return m+a
    else:
        return 0

print(russian_mult2(57,86))