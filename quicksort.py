def quicksort(s):
    if len(s)<=1:
        return s
    elem=s[0]
    left=list(filter(lambda x: x<elem,s))
    center=[i for i in s if i==elem]
    right=list(filter(lambda x: x> elem,s))

    return quicksort(left)+center+quicksort(right)
answer=[int(x) for x in input().split()]
print(quicksort(answer))
