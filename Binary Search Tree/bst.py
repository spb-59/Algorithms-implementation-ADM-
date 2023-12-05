class Node:
    def __init__(self,value) -> None:
        self.data=value
        self.left=None
        self.right=None
        self.parent=None

class bst:
    def __init__(self) -> None:
        self.root=None

    def _insert(self, value, root:Node) -> Node:
        if root is None:
            return Node(value)

        if value < root.data:
            root.left = self._insert(value, root.left)
        elif value > root.data:
            root.right = self._insert(value, root.right)
        
        return root

    def insert(self,value):
        self.root=self._insert(value,self.root)
    
    def _inorder_traversal(self, root):
        
        if root:
            self._inorder_traversal(root.left)
            print(root.data, end=" ")
            self._inorder_traversal(root.right)
    
    def inorder_traversal(self):
        self._inorder_traversal(self.root)
    
    def _search(self,value,root:Node)->bool:
        if root is None or root.data==value:
            return True if root is not None else False
        
        if value<root.data:
            return self._search(value,root.left)
        elif value>root.data:
            return self._search(value,root.right)
    
    def search(self,value)->bool:
        return self._search(value,self.root)
    


    def _deleteNode(self, value, root: Node):
        if root is None:
            return root

        if value < root.data:
            root.left = self._deleteNode(value, root.left)
        elif value > root.data:
            root.right = self._deleteNode(value, root.right)
        else:
            if root.right is None and root.left is None:
                return None
            elif root.right and root.left is None:
                return root.right
            elif root.left and root.right is None:
                return root.left
            else:
                temp = self._minValueNode(root.right)
                root.data = temp.data
                root.right = self._deleteNode(temp.data, root.right)
            

        return root
    
    def deleteNode(self,value):
        self._deleteNode(value,self.root)

    def _minValueNode(self, node):
    
        while node.left is not None:
            node = node.left

        return node
       
        
        
    
if __name__ == "__main__":
    tree=bst()
    tree.insert(5)
    tree.insert(1)
    tree.insert(10)
    tree.insert(8)
    tree.insert(7)
    tree.insert(6)
    
    tree.inorder_traversal()

    print(tree.search(6))
    tree.deleteNode(5)

    tree.inorder_traversal()


        
        
            
            
            


    

