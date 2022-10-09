n, m = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
c = [int(i) for i in input().split()]
 
arr = []
 
for x in a:
    if x not in c:
        arr.append(x)
 
P = 1
for i in a:
    P *= i
 
soma = 0
for i in arr:
    soma += P//i
 
d = 1
for i in c:
    d *= i
 
if soma == d:
    print("S")
else:
    print("N")
