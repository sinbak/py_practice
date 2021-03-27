def square(n):
    if n == 0:
        return 0
    else:
        return 2*(abs(n)-1)+1 + square(abs(n)-1)

def square1(n): #꼬리재귀
    def loop(n, ans):
        if n == 0:
            return 0
        else:
            return 2*(abs(n)-1)+1 + loop(abs(n)-1, ans + 2*(abs(n)-1)+1)
    return loop(n, 0)

def square2(n):
    ans = 0
    while abs(n) > 0:
        n, ans = abs(n)-1, 2*abs(n)-1 + ans
            
    return ans


print(square(0))
print(square(1))
print(square(-2))
print(square(3))
print(square(5))
print(square(-4))
print("///////////")
print(square1(0))
print(square1(1))
print(square1(-2))
print(square1(3))
print(square1(5))
print(square1(-4))
print("mmmmmmmm")
print(square2(0))
print(square2(1))
print(square2(-2))
print(square2(3))
print(square2(5))
print(square2(-4))