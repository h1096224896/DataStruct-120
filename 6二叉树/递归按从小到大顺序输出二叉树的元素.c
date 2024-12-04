#include "二叉树.c"


// 设计一个递归的算法，把一棵二叉排序树T中的元素按由小到大的顺序输出
// 相当于中序遍历
void fun(BiTree T) {
    if (T) {
        fun(T->lchild);
        printf("%c ", T->data);
        fun(T->rchild);
    }
}

// 设计一个递归算法，把任意的一颗二叉树T中的元素按由小到大的顺序输出
// 相当于小到大的顺序输出二叉树的所有元素
void fun2(BiTree T) {
    
}

int main(int argc, char const* argv[]) {
    BiTree T;
    Init_Tree(&T);
    Create_Tree(&T);
    PreOrder(T); printf("\n");
    printf("%d", countLeafNodes(T)), printf("\n");
    return 0;
}