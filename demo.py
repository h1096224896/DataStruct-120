# // 递归折半查找
def binary_search(data, target, low, high):
    if low > high:
        return False
    else:
        mid = (low + high) // 2
        if target == data[mid]:
            return mid
        elif target < data[mid]:
            return binary_search(data, target, low, mid-1)
        else:
            return binary_search(data, target, mid+1, high)
        
data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
target = 5
low = 0
high = len(data) - 1
print(binary_search(data, target, low, high))
