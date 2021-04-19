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

    return 0;
}