
def merge(arr:list,low,middle,high):
    index=low
    temp1=arr[low:middle]
    temp2=arr[middle:high]

    while temp1 and temp2:
        if temp1[0]<=temp2[0]:
            arr[index]=temp1.pop(0)
        else:
            arr[index]=temp2.pop(0)
        
        index+=1
    
    while temp1:
        arr[index]=temp1.pop(0)
        index+=1
    
    while temp2:
        arr[index]=temp2.pop(0)
        index+=1

        





def mergeSort(arr:list,low,high):
    middle=0

    if(high-low>1):
        middle=(low+high)//2
        mergeSort(arr,low,middle)
        mergeSort(arr,middle,high)
        merge(arr,low,middle,high)


    



arr=[5,3,1,12,10,4]
mergeSort(arr,0,len(arr))
print(arr)