arr = [8,5,32,9,0,23,12]

for i in range(len(arr), -1, -1):
    for j in range(i-1):
        if arr[j] > arr[j+1]:
            temp = arr[j]
            arr[j] = arr[j+1]
            arr[j+1] = temp

print(arr)
