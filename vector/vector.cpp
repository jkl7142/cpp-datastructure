#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {

    // int�� ���� ����
    std::vector<int> vec1;

    // ������ �ʱ갪���� �̷���� ũ�Ⱑ 5�� ���� ����
    std::vector<int> vec2 = {1, 2, 3, 4, 5};

    // ũ�Ⱑ 10�� ���� ����
    std::vector<int> vec3(10);

    // ũ�Ⱑ 10�̰�, ��� ���Ұ� 5�� �ʱ�ȭ�� ���� ����
    std::vector<int> vec4(10, 5);

    // ���Ϳ� ���ο� ���� �߰�
    // vector.push_back(val) : �� �������� ���ο� ���� �߰�
    // vector.insert(&, val) : ������ ��ġ�� ���� �߰�

    vec1.insert(vec1.begin(), 0);    // �� �տ� 0 �߰� : {0}
    vec1.push_back(1);               // �� �ڿ� 1 �߰� : {0, 1}
    vec1.push_back(2);               // �� �ڿ� 2 �߰� : {0, 1, 2}
    vec1.insert(vec1.begin(), 0);    // �� �տ� 0 �߰� : {0, 0, 1, 2}
    vec1.insert(find(vec1.begin(), vec1.end(), 1), 4);  // 1 �տ� 4 �߰� : {0, 0, 4, 1, 2}

    // vec.emplace_back() or emplace() �Լ��� �� ���� ��ġ���� ��ٷ� ��ü�� �����Ǳ� ������ ���� ��� ������ ��

    // ���� ���� ����
    // vector.pop_back() : �� ������ ���� ����
    // vector.erase(&) : �ش� ��ġ ���� ����
    // vector.erase(&, &) : ���ۺ��� �� �ٷ� �� ���ұ��� ����

    std::vector<int> vec5 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    vec5.pop_back();            // �� ������ ���� �ϳ� ���� : {0, 1, 2, 3, 4, 5, 6, 7, 8}
    vec5.erase(vec5.begin());   // �� ó�� ���� �ϳ� ���� : {1, 2, 3, 4, 5, 6, 7, 8}
    vec5.erase(vec5.begin() + 1, vec5.begin() + 4); // 1��° ���Һ��� 4��° �� ���ұ��� ���� {1, 5, 6, 7, 8}

    // vector.clear() : ��� ���Ҹ� �����Ͽ� �� ���ͷ� ����
    // vector.reserve(capacity) : ���Ϳ��� ����� �뷮�� ���� (������ ���� ���� �뷮���� ũ�� �Ű�������ŭ ���Ҵ�, ���ų� ������ �ƹ��� ������ ���� ����)
    // vector.shrink_to_fit() : ������ �޸� ������ ���� (���� ũ�Ⱑ �� �̻� ������� ���� �� ����ϸ� ����)

    /////////////////////////////////////////////////////////////
    // vector �Ҵ���

    // vector.allocate()
    // vector.deallocate()
    // vector.construct()
    // vector.destroy()
}