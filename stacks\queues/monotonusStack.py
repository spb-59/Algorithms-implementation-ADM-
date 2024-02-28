from collections import deque

def contiguousIncreasing(arr):
    stack=deque()
    stack.append(0)
    inc=[arr[0]]


    for i in range(1,len(arr)):
        
        if arr[stack[-1]]<arr[i]:
            stack.append(i)         
            inc.append(arr[i])
        
    print(inc)
            
        
        


arr=[3,5,4,6,2,8]
contiguousIncreasing(arr)





    


