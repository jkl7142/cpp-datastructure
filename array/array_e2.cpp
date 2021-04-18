/*
*   Exercise 2 : ������ ���� �����̳� �����
*/

#include <array>
#include <iostream>
#include <type_traits>

// �����̳� ����
//template<typename ... Args>
// std::array ��ȯ
//std::array<?, ?> build_array(Args&&... args)

// ���� Ÿ�� & ���� ����            // ���� ���� Ÿ�� ����
//auto build_array(Args&&... args) -> std::array<typename::common_type<Args...>::type, ?> {
    //using commonType = typename std::common_type<Args...>::type;
    // �迭 ���� �ڵ� ��ġ
//}

template<typename ... Args>
auto build_array(Args&&... args) -> std::array<typename std::common_type<Args...>::type, sizeof...(args)> {// sizeof...(args) : ���� ����
    using commonType = typename std::common_type<Args...>::type;
    return {std::forward<commonType>((Args&&)args)...}; // commonType���� �迭 ����
}

int main() {
    auto data = build_array(1, 0u, 'a', 3.2f, false);   // �پ��� Ÿ���� �����͸� ���ڷ� ����

    for (auto i : data) {
        std::cout << i << " ";  // ���ڵ��� ��� float �ڷ������� ��ȯ�� �� �־� ���� ����� float ����
    }
    std::cout << std::endl;

    // ���ڿ��� ���ڸ� ��� ǥ���� �� �ִ� ���� �ڷ����� ���� ����
    // auto data2 = build_array(1, "Packt", 2.0);

    return 0;
}