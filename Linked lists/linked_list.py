
class Node:
    def __init__(self, data) -> None:
        self.data = data
        self.next = None


class LinkedList:

    def __init__(self) -> None:
        self.head = None

    def insertBeg(self, data):
        # to insert at beggining
        newNode = Node(data)
        newNode.next = self.head
        self.head = newNode

    def insertLast(self, data):
        # to insert at end
        if self.head == None:
            self.head = Node(data)

        temp = self.head
        while (temp.next is not None):
            temp = temp.next

        temp.next = Node(data)

    def printList(self):
        temp = self.head
        while temp is not None:
            print(temp.data, end=" ")
            temp = temp.next
        print()
    
    def deleteNode(self,data):
        if self.head is None:
            return
        
        if self.head.data==data:
            self.head=None
        
        temp=self.head
        prev=None
        while  temp.data !=data and temp.next is not None :
            prev=temp
            temp=temp.next
        
        if temp is None:
            print("not found")
        else:
            prev.next=temp.next
              
        

if __name__ == "__main__":
    list=LinkedList()
    list.insertBeg(1)
    list.insertBeg(2)
    list.insertLast(3)
    list.insertLast(5)
    list.deleteNode(3)

    list.printList()
    
    

