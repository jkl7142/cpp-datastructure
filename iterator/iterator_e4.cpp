/*
*   Exercise 4 : �پ��� �ݺ��ڷ� �̵��ϱ�
*/

#include <iostream>
#include <forward_list>
#include <vector>

int main() {

    // std::vector
    std::vector<std::string> vec = {
        "Lewis Hamilton", "Lewis Hamilton", "Nico Roseberg",
        "Sebastian Vettel", "Lewis Hamilton", "Sebastian Vettel",
        "Sebastian Vettel", "Sebastian Vettel", "Fernando Alonso"
    };

    // �ð� ���⵵ O(1)
    auto it = vec.begin();
    std::cout << "���� �ֱ� �����: " << *it << std::endl;

    it += 8;
    std::cout << "8�� �� �����: " << *it << std::endl;

    advance(it, -3);
    std::cout << "���� 3�� �� �����: " << *it << std::endl;

    // std::forward_list
    std::forward_list<std::string> fwd(vec.begin(), vec.end());

    // �ð� ���⵵ O(n)
    auto it1 = fwd.begin();
    std::cout << "���� �ֱ� �����: " << *it1 << std::endl;

    advance(it1, 5);
    std::cout << "5�� �� �����: " << *it1 << std::endl;

    // advance(it1, -2) // ���� ����Ʈ�� ������ �̵� x

    // it1 += 2;    // ���� ����Ʈ += ������ x


    return 0;
}