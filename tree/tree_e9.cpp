/*
*   Exercise 9 : BST 구현 Binary Search Tree
*/

#include <iostream>

// 정수 값 노드
struct node {
    int data;
    node* left;
    node* right;
};

struct bst {
    node* root = nullptr;

    node* find(int value) {
        return find_impl(root, value);
    }

private:
    node* find_impl(node* current, int value) {
        if (!current) {
            std::cout << std::endl;
            return NULL;
        }

        if (current->data == value) {
            std::cout << value << "을(를) 찾았습니다." << std::endl;
            return current;
        }

        if (value < current->data) {    // value 값이 현재 노드 왼쪽에 있는 경우
            std::cout << current->data << "에서 왼쪽으로 이동: ";
            return find_impl(current->left, value);
        }

        // value 값이 현재 노드 오른쪽에 있는 경우
        std::cout << current->data << "에서 오른쪽으로 이동: ";
        return find_impl(current->right, value);
    }

public:
    // 노드 삽입
    void insert(int value) {
        if (!root)
            root = new node {value, NULL, NULL};
        else
            insert_impl(root, value);
    }

private:
    void insert_impl(node* current, int value) {
        if (value < current->data) {    // 왼쪽 노드에 삽입
            if (!current->left)
                current->left = new node {value, NULL, NULL};
            else
                insert_impl(current->left, value);
        }
        else {      // 오른쪽 노드에 삽입
            if (!current->right)
                current->right = new node {value, NULL, NULL};
            else
                insert_impl(current->right, value);
        }
    }

public:
    // 중위 순회
    void inorder() {
        inorder_impl(root);
    }

private:
    void inorder_impl(node* start) {
        if (!start)
            return;

        inorder_impl(start->left);
        std::cout << start->data << " ";
        inorder_impl(start->right);
    }

public:
    // 후속 노드를 찾는 함수
    node* successor(node* start) {
        auto current = start->right;
        while (current && current->left)
            current = current->left;
        return current;
    }

    // 노드 삭제
    void deleteValue(int value) {
        root = delete_impl(root, value);
    }

private:
    node* delete_impl(node* start, int value) {
        if (!start)
            return NULL;

        if (value < start->data)
            start->left = delete_impl(start->left, value);
        else if (value > start->data)
            start->right = delete_impl(start->right, value);
        else {  // 현재 노드가 삭제할 노드인 경우

            // 1. 자식 노드가 없거나, 오른쪽 자식 노드만 있는 경우
            if (!start->left) { 
                // 현재 노드를 오른쪽 자식 노드로 교체
                auto tmp = start->right;
                delete start;
                return tmp;
            }

            // 2. 왼쪽 자식 노드만 있는 경우
            if (!start->right) {
                auto tmp = start->left;
                delete start;
                return tmp;
            }

            // 3. 자식 노드가 둘 다 있는 경우
            auto succNode = successor(start);
            start->data = succNode->data;

            // 오른쪽 서브 트리에서 후속(successor) 노드를 찾아 삭제
            start->right = delete_impl(start->right, succNode->data);
        }

        return start;
    }
};

int main() {
    bst tree;
    tree.insert(12);    //
    tree.insert(10);    //
    tree.insert(20);    //              12
    tree.insert(8);     //          10       20
    tree.insert(11);    //        8    11  15   28
    tree.insert(15);    //      4
    tree.insert(28);    //    2
    tree.insert(4);     //
    tree.insert(2);     //

    std::cout << "중위 순회: ";
    tree.inorder(); // 오름차순 출력
    std::cout << std::endl;

    tree.deleteValue(12);
    std::cout << "12를 삭제한 후 중위 순회: ";
    tree.inorder();
    std::cout << std::endl;

    //              15
    //          10       20
    //        8    11       28
    //      4
    //    2

    if (tree.find(12))
        std::cout << "원소 12는 트리에 있습니다." << std::endl;
    else
        std::cout << "원소 12는 트리에 없습니다." << std::endl;

    return 0;
}