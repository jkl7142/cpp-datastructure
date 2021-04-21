/*
*   Exercise 9 : BST ���� Binary Search Tree
*/

#include <iostream>

// ���� �� ���
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
            std::cout << value << "��(��) ã�ҽ��ϴ�." << std::endl;
            return current;
        }

        if (value < current->data) {    // value ���� ���� ��� ���ʿ� �ִ� ���
            std::cout << current->data << "���� �������� �̵�: ";
            return find_impl(current->left, value);
        }

        // value ���� ���� ��� �����ʿ� �ִ� ���
        std::cout << current->data << "���� ���������� �̵�: ";
        return find_impl(current->right, value);
    }

public:
    // ��� ����
    void insert(int value) {
        if (!root)
            root = new node {value, NULL, NULL};
        else
            insert_impl(root, value);
    }

private:
    void insert_impl(node* current, int value) {
        if (value < current->data) {    // ���� ��忡 ����
            if (!current->left)
                current->left = new node {value, NULL, NULL};
            else
                insert_impl(current->left, value);
        }
        else {      // ������ ��忡 ����
            if (!current->right)
                current->right = new node {value, NULL, NULL};
            else
                insert_impl(current->right, value);
        }
    }

public:
    // ���� ��ȸ
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
    // �ļ� ��带 ã�� �Լ�
    node* successor(node* start) {
        auto current = start->right;
        while (current && current->left)
            current = current->left;
        return current;
    }

    // ��� ����
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
        else {  // ���� ��尡 ������ ����� ���

            // 1. �ڽ� ��尡 ���ų�, ������ �ڽ� ��常 �ִ� ���
            if (!start->left) { 
                // ���� ��带 ������ �ڽ� ���� ��ü
                auto tmp = start->right;
                delete start;
                return tmp;
            }

            // 2. ���� �ڽ� ��常 �ִ� ���
            if (!start->right) {
                auto tmp = start->left;
                delete start;
                return tmp;
            }

            // 3. �ڽ� ��尡 �� �� �ִ� ���
            auto succNode = successor(start);
            start->data = succNode->data;

            // ������ ���� Ʈ������ �ļ�(successor) ��带 ã�� ����
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

    std::cout << "���� ��ȸ: ";
    tree.inorder(); // �������� ���
    std::cout << std::endl;

    tree.deleteValue(12);
    std::cout << "12�� ������ �� ���� ��ȸ: ";
    tree.inorder();
    std::cout << std::endl;

    //              15
    //          10       20
    //        8    11       28
    //      4
    //    2

    if (tree.find(12))
        std::cout << "���� 12�� Ʈ���� �ֽ��ϴ�." << std::endl;
    else
        std::cout << "���� 12�� Ʈ���� �����ϴ�." << std::endl;

    return 0;
}