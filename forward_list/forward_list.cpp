#include <iostream>
#include <forward_list>

int main(int argc, char* argv[]) {

    // ���Ḯ��Ʈ ����
    std::forward_list<int> fwd_list1 = {1, 2, 3};

    // ���Ḯ��Ʈ ���� �߰�
    // forward_list.push_front(val) : �� �տ� ���� �߰�
    // forward_list.insert_after(&, val) : & ��ġ ������ ���� �߰�

    fwd_list1.push_front(0); // �� �տ� 0 �߰� : {0, 1, 2, 3}

    auto it = fwd_list1.begin();
    fwd_list1.insert_after(it, 5);   // ù ��° ���� �ڿ� 5 �߰� : {0, 5, 1, 2, 3}
    fwd_list1.insert_after(it, 6);   // ù ��° ���� �ڿ� 6 �߰� : {0, 6, 5, 1, 2, 3}

    // forward_list.emplace_front() or .emplace_after() // �߰����� ���� �Ǵ� �̵� x -> ȿ����

    // ���Ḯ��Ʈ ���� ����
    // forward_list.pop_front() : �� �տ� ���� ����
    // forward_list.erase_after(&) : & ��ġ ���� ���� ����
    // forward_list.erase_after(&, &) : & ��ġ �������� & �ٷ� �� ���ұ��� ����

    std::forward_list<int> fwd_list2 = {1, 2, 3, 4, 5};

    fwd_list2.pop_front();  // �� �տ� ���Ҹ� ���� : {2, 3, 4, 5}
    
    auto it = fwd_list2.begin();
    fwd_list2.erase_after(it);  // ù ��° ���� ���� ���Ҹ� ���� : {2, 4, 5}
    
    fwd_list2.erase_after(it, fwd_list2.end()); // �� ���� ���� �������� ������ ���ұ��� ���� : {2}

    // forward_list.remove(val) : val�� ���� ���� ���Ҹ� ��� ����
    // forward_list.remove_if() : ������ �Լ��� �޾� true�� ��ȯ�ϴ� ���Ҹ� ��� ����

    // ���� ����Ʈ ����
    // forward_list.sort() : �������� ����
    // forward_list.sort(�� �Լ�) : �� �Լ� ���ǿ� �°� ����
    
    std::forward_list<int> list1 = {23, 0, 1, -3, 34, 32};

    list1.sort();   // {-3, 0, 1, 23, 32, 34}
    list1.sort(std::greater<int>());    // {34, 32, 23, 1, 0, -3} �������� ����

    // forward_list.reverse() : �������� ����
    // forward_list.unique() : �ߺ��Ǵ� ���ҿ� ���� ù ��°�� ����� �������� ����
    // * unique()�� ������ ���ҳ��� �񱳸� �ϱ� ������ ������ �� �Լ��� ����ؾ� ��

    std::forward_list<int> list2 = {2, 53, 1, 0, 4, 10};
    list2.reverse();    // {10, 4, 0, 1, 53, 2}

    list2 = {0, 1, 0, 1, -1, 10, 5, 5, 10, 0};
    list2.unique(); // {0, 1, 0, 1, -1, 10, 5, 10, 0}

    list2 = {0, 1, 0, 1, -1, 10, 5, 5, 10, 0};
    list2.sort();   // {-1, 0, 0, 0, 1, 1, 5, 5, 10, 10}
    list2.unique(); // {-1, 0, 1, 5, 10}

    // Ư�� ���Ұ� �ٷ� �� ���Һ��� 2 �̻� ũ�� ������ ����
    list2.unique([](int a, int b) { return (b - a) < 2; }); // {-1, 1, 5, 10}

    return 0;
}