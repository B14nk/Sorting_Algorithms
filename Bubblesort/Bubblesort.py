arr = [1,4,324,56,7,456, 45, 34, 3267,768]

for i in range(len(arr), -1, -1):
    for j in range(i-1):
        if arr[j] > arr[j+1]:
            temp = arr[j]
            arr[j] = arr[j+1]
            arr[j+1] = temp

print(arr)
