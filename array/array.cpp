#include <iostream>
#include <array>

// array �Լ� ����
void print(std::array<int, 5> arr) {
    for (auto ele : arr) 
        std::cout << ele << ", ";
}

// �迭 ũ�⸦ ���ø����� ����
template<size_t N>
void print2(const std::array<int, N>& arr) {
    for (auto ele : arr) 
        std::cout << ele << ", ";
}

int main(int argc, char* argv[]) {

    // std::array<type, size> arr;
    // array ����
    std::array<int, 10> arr1;

    arr1[0] = 1;
    
    std::array<int, 4> arr2 = {1, 2, 3, 4};

    // �迭 ���� ����
    // array.at(index)
    arr2.at(2);  // == arr2[1]

    //////////////////////////////////////////
    
    // array ���� ó��
    std::array<int, 4> arr3 = {1, 2, 3, 4};

    try
    {
        std::cout << arr3.at(3) << std::endl;   // arr3[3] == 4
        std::cout << arr3.at(4) << std::endl;   // out_of_range
    }
    catch(const std::out_of_range& ex)
    {
        std::cerr << ex.what() << '\n';
    }

    ///////////////////////////////////////////

    std::array<int, 5> arr4 = {1, 2, 3, 4, 5};
    print(arr4);

    // ���ø� �Ű����� �Լ� ���
    print2(arr4);

    // ���� ��� for ���
    for (auto element : arr4) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    ////////////////////////////////////////////

    // array::begin() : ù ��° ���� ��ġ ��ȯ
    // array::end() : ������ ���� ���� ��ġ ��ȯ

    std::array<int, 10> arr5 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (auto it = arr5.begin(); it != arr5.end(); it++) {
        auto element = *it;
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    /////////////////////////////////////////////

    // array::front() : ù ��° ���ҿ� ���� ������ ��ȯ
    // array::back() : ������ ���ҿ� ���� ������ ��ȯ
    // array::data() : ��ü ���ο��� ���� ������ �޸� ���۸� ����Ű�� �����͸� ��ȯ

    std::array<int, 5> arr6 = {1, 2, 3, 4, 5};
    std::cout << arr6.front() << std::endl;         // 1
    std::cout << arr6.back() << std::endl;          // 5
    std::cout << *(arr6.data() + 1) << std::endl;   // 2

    return 0;
}