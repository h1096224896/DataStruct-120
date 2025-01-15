#include "二叉树.c"

// 求二叉树的宽度
int getTreeWidth(BiTree root) {
    if (root == NULL)
        return 0; // 空树宽度为0
    BiTNode* queue[100]; // 使用数组模拟队列  假设队列最大容量为1000
    int front = 0; // 队列头指针
    int rear = 0;  // 队列尾指针
    queue[rear++] = root; // 将根节点入队
    int maxWidth = 0; // 存储最大宽度

    while (front != rear) {  // 队列不为空
        int levelWidth = rear - front; // 当前层的节点数
        if (levelWidth > maxWidth)
            maxWidth = levelWidth;  // 更新最大宽度
        // 遍历当前层的所有节点，将下一层的节点入队
        for (int i = 0; i < levelWidth; i++) {
            BiTNode* temp = queue[front++]; // 出队当前节点
            if (temp->lchild)
                queue[rear++] = temp->lchild; // 左孩子入队
            if (temp->rchild)
                queue[rear++] = temp->rchild; // 右孩子入队
        }
    }
    return maxWidth;
}


int fun(BiTree T) {
    if (T == NULL)
        return 0;
    BiTNode* queue[100];
    int front = 0, rear = 0;
    int maxWidth = 0;
    queue[rear++] = T;
    while (front != rear) {
        int curWidth = rear - front;
        if (curWidth > maxWidth)
            maxWidth = curWidth;
        for (size_t i = 0; i < curWidth; i++) {
            BiTNode* temp = queue[front++];
            if (temp->lchild)
                queue[rear++] = temp->lchild;
            if (temp->rchild)
                queue[rear++] = temp->rchild;
        }
    }
    return maxWidth;
}


int getBitreeWidth(BiTree T) {
    if (T == NULL)
        return 0;
    BiTNode* queue[100];
    int front = 0;
    int rear = 0;
    int maxWidth = 0;
    queue[rear++] = T;
    while (front != rear) {
        int levelWifth = rear - front;
        if (levelWifth > maxWidth)
            maxWidth = levelWifth;
        for (int i = 0; i < levelWifth; i++) {
            BiTNode* temp = queue[front++];
            if (temp->lchild)
                queue[rear++] = temp->lchild;
            if (temp->rchild)
                queue[rear++] = temp->rchild;
        }
    }
    return maxWidth;
}

int main() {
    BiTree T = NULL;
    Init_Tree(&T);
    Create_Tree(&T);
    PreOrder(T);
    printf("二叉树的宽度为：%d\n", getBitreeWidth(T));
    return 0;
}
