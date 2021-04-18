/*
*   Exercise 1 : 동적 크기 배열 구현하기
*   학생 정보 관리 프로그램
*/

#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>

// 동적 배열 클래스 템플릿
template<typename T>
class dynamic_array {
    // 주요 멤버 변수 선언
    T* data;
    size_t n;

public:
    // 생성자
    dynamic_array(int n) {
        this->n = n;
        data = new T[n];
    }

    // 복사 생성자
    dynamic_array(const dynamic_array<T>& other) {
        n = other.n;
        data = new T[n];

        for (int i = 0; i < n; i++) {
            data[i] = other[i];
        }
    }

    // 배열 원소 접근 함수
    T& operator[](int index) {
        return data[index];
    }

    const T& operator[](int index) const {
        return data[index];
    }

    T& at(int index) {
        if (index < n) return data[index];
        throw "Index out of range";
    }

    // 배열 크기 반환 함수
    size_t size() const {
        return n;
    }

    // 소멸자
    ~dynamic_array() {
        delete[] data;  // memory leak 방지
    }

    // 배열 원소 순회
    T* begin() { return data; }
    const T* begin() const { return data; }
    T* end() { return data + n; }
    const T* end() const { return data + n; }

    // 덧셈 연산자
    friend dynamic_array<T> operator+(const dynamic_array<T>& arr1,
                                      dynamic_array<T>& arr2) {
        dynamic_array<T> result(arr1.size() + arr2.size());
        std::copy(arr1.begin(), arr1.end(), result.begin());        // arr1을 result.begin()에 복사
        std::copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());  // arr2를 복사된 result 뒤에 복사

        return result;
    }

    // 저장된 모든 데이터를 문자열로 반환하는 함수
    std::string to_string(const std::string& sep = ", ") {
        if (n == 0) return "";
        
        std::ostringstream os;
        os << data[0];

        for (int i = 1; i < n; i++) 
            os << sep << data[i];

        return os.str();
    }
};

// 학생 정보
struct student {
    std::string name;
    int standard;
};

std::ostream& operator<<(std::ostream& os, const student& s) {
    return (os << "[" << s.name << ", " << s.standard << "]");
}

int main() {

    int nStudents;
    std::cout << "1반 학생 수를 입력하세요: ";
    std::cin >> nStudents;

    dynamic_array<student> class1(nStudents);
    for (int i = 0; i < nStudents; i++) {
        std::string name;
        int standard;
        std::cout << i + 1 << "번째 학생 이름과 나이를 입력하세요: ";
        std::cin >> name >> standard;
        class1[i] = student{name, standard};
    }

    // 배열 크기보다 큰 인덱스의 학생에 접근
    try
    {
        // 아래 주석을 해제하면 프로그램이 비정상 종료됨
        // class1[nStudents] = student {"John", 8}; // 예상치 못한 동작

        class1.at(nStudents) = student{"John", 8};  // 예외 발생
    }
    catch(...)
    {
        std::cout << "예외 발생!" << std::endl;
    }

    // 깊은 복사
    auto class2 = class1;
    std::cout << "1반을 복사하여 2반 생성: " << class2.to_string() << std::endl;

    // 두 학급 합쳐서 새로운 큰 학급을 생성
    auto class3 = class1 + class2;
    std::cout << "1반과 2반을 합쳐 3반 생성: " << class3.to_string() << std::endl;
    

    return 0;
}