def permultation(n, k):
    if k > 0:
        return n * permultation(n-1, k-1)
    else:
        return 1

def permultation2(n, k):
  def loop(n, k, a):
    if k > 0:
      return loop(n-1, k-1, a*n)
    else:
      return a
  return loop(n, k, 1)

def permultation3(n, k):
    ans = 1
    while k>0:
        n, k, ans = n-1, k-1, n*ans
    return ans


print(permultation(1, 1))
print(permultation(4, 4))
print(permultation(3, 2))

print(permultation2(1, 1))
print(permultation2(4, 4))
print(permultation3(3, 2))