class Node:
    def __init__(self, val: int = None, edges: list['Node'] = None) -> None:
        self.val = val
        self.edges = edges if edges is not None else []

    


class Graph:
    
    def __init__(self) -> None:
        self.nodes = []
    
    def addNode(self, val: int) -> None:
        self.nodes.append(Node(val))
    
    def addEdge(self, node1: Node, node2: Node) -> None:
        if node1 not in self.nodes or node2 not in self.nodes:
            raise ValueError("Both nodes should be part of the Graph.")
        
        
        node1.edges.append(node2)
        node2.edges.append(node1)

    
        

