class TreeNode:
    def __init__(self, value=0, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right


def inorder(node):
    if node is None:
        return
    # 递归访问左子树
    inorder(node.left)
    # 输出当前节点的值
    print(node.value, end=" ")
    # 递归访问右子树
    inorder(node.right)


# 示例：构造一个二叉树
root = TreeNode(5)
root.left = TreeNode(3)
root.right = TreeNode(8)
root.left.left = TreeNode(2)
root.left.right = TreeNode(4)
root.right.left = TreeNode(7)
root.right.right = TreeNode(9)

# 按从小到大的顺序输出二叉树中的元素
print("二叉树中元素的排序输出：")
inorder(root)
