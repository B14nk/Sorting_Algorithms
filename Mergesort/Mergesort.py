arr = [1,4,324,56,7,456, 45, 34, 3267,768, 100]

def mergesort(arr):
    if len(arr) <= 1:
        return arr
    else:
        l = mergesort(arr[0:len(arr)/2])
        r = mergesort(arr[len(arr)/2:len(arr)])
        return merge(l, r)

def merge(l, r):
    if len(l) == 0:
        return r
    if len(r) == 0:
        return l
    i, j = 0, 0
    run = True
    output = []
    while run:
        if l[i] < r[j]:
            output.append(l[i])
            i += 1
        else:
            output.append(r[j])
            j += 1
        if i == len(l):
            output += r[j:]
            run = False
        if j == len(r):
            output += l[i:]
            run = False
    return output


print(mergesort(arr))