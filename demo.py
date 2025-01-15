class LinkList:
    def __init__(self):
        self.head = None

    # 尾插法
    def add(self, data):
        if not self.head:
            self.head = Node(data)
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = Node(data)

    def display(self):
        current = self.head
        while current:
            print(current.data, end=" ")
            current = current.next


class Node:
    def __init__(self, data):
        self.data = data
        self.next: "Node" | None = None


if __name__ == "__main__":
    ll = LinkList()
    ll.add(1)
    ll.add(2)
    ll.add(3)
    ll.display()
