#include <iostream>
#include <array>

// array 함수 전달
void print(std::array<int, 5> arr) {
    for (auto ele : arr) 
        std::cout << ele << ", ";
}

// 배열 크기를 템플릿으로 전달
template<size_t N>
void print2(const std::array<int, N>& arr) {
    for (auto ele : arr) 
        std::cout << ele << ", ";
}

int main(int argc, char* argv[]) {

    // std::array<type, size> arr;
    // array 선언
    std::array<int, 10> arr1;

    arr1[0] = 1;
    
    std::array<int, 4> arr2 = {1, 2, 3, 4};

    // 배열 원소 접근
    // array.at(index)
    arr2.at(2);  // == arr2[1]

    //////////////////////////////////////////
    
    // array 예외 처리
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

    // 템플릿 매개변수 함수 사용
    print2(arr4);

    // 범위 기반 for 출력
    for (auto element : arr4) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    ////////////////////////////////////////////

    // array::begin() : 첫 번째 원소 위치 반환
    // array::end() : 마지막 원소 다음 위치 반환

    std::array<int, 10> arr5 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (auto it = arr5.begin(); it != arr5.end(); it++) {
        auto element = *it;
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    /////////////////////////////////////////////

    // array::front() : 첫 번째 원소에 대한 참조를 반환
    // array::back() : 마지막 원소에 대한 참조를 반환
    // array::data() : 객체 내부에서 실제 데이터 메모리 버퍼를 가리키는 포인터를 반환

    std::array<int, 5> arr6 = {1, 2, 3, 4, 5};
    std::cout << arr6.front() << std::endl;         // 1
    std::cout << arr6.back() << std::endl;          // 5
    std::cout << *(arr6.data() + 1) << std::endl;   // 2

    return 0;
}