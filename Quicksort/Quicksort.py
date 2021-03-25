arr = [1,4,324,56,7,456, 45, 34, 3267,768, 100]

def quicksort(l, r):
    if l < r:
        offset = split(l, r)
        quicksort(l, l+offset-1)
        quicksort(l+offset+1, r)

def split(l, r):
    offset = 0
    pivot = arr[r]
    for i in range(l, r):
        j = i
        run = True
        while run and j < r:
            if arr[j] < pivot:
                arr[i], arr[j] = arr[j], arr[i]
                offset += 1
                run = False
            j += 1
    arr[l+offset], arr[r] = arr[r], arr[l+offset]
    return offset

quicksort(0, len(arr)-1)
print(arr)