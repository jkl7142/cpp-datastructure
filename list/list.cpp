#include <iostream>
#include <list>
#include <vector>

// ���� ���� ����Ʈ ����
struct doubly_linked_list_node {
    int data;
    doubly_linked_list_node* next;
    doubly_linked_list_node* prev;
};

int main() {

    // forward_list�� ������
    // 1. ������ �̵� ����
    // 2. ������ ���Ҹ� ������ ���� push_back(), emplace_back(), pop_back() ����
    // 3. ����Ʈ ũ�⸦ ��ȯ�ϴ� size() ����

    // ����� �ݺ��� O(n) : ������ & ������ �̵� ����

    // �ݺ��� ��ȿȭ : ���� ����Ʈ������ ����/���� �� �ݺ��ڰ� ��ȿȭ���� ����

    // ������ ���
    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto v_it4 = vec.begin() + 4;   // vec[4] = 5
    vec.insert(vec.begin() + 2, 0); // v_it4 �ݺ��ڴ� ��ȿȭ��
    // (���� �޸� ������ �Ҵ��ϰ� ������ ��� ���Ҹ� �����ϱ� ������ ������ ����ϴ� ��� �ݺ���, ������, ������ ��ȿȭ)

    // ����Ʈ�� ���
    std::list<int> lst = {1, 2, 3, 4, 5};
    auto l_it4 = next(lst.begin(), 4);
    lst.insert(next(lst.begin(), 2), 0);    // l_it4 �ݺ��ڴ� ������ ��ȿ

    return 0;
}