/*
*   Activity 1 : 음악 재생 목록 구현
*   이중 원형 연결 리스트 구현
*/

#include <iostream>

template<typename T>
struct cir_list_node {
    T* data;
    cir_list_node* next;
    cir_list_node* prev;  // 이전 노드 변수 추가

    ~cir_list_node() {
        delete data;
    }
};

template<typename T>
struct cir_list {
public:
    using node = cir_list_node<T>;
    using node_ptr = node*;

private:
    node_ptr head;
    size_t n;

public:
    cir_list() : n(0) {
        head = new node {NULL, NULL, NULL}; // 더미 노드 생성
        head->next = head;
        head->prev = head;
    }

    size_t size() const {
        return n;
    }

    // 맨 앞에 value 추가
    void insert(const T& value) {
        node_ptr newNode = new node {new T(value), NULL, NULL};
        n++;

        auto dummy = head->prev;    // dummy == tail
        dummy->next = newNode;
        newNode->prev = dummy;

        if (head == dummy) {    // 노드가 없는 경우
            dummy->prev = newNode;
            newNode->next = dummy;
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void erase(const T& value) {
        auto cur = head, dummy = head->prev;
        while (cur != dummy) {  // cur를 첫 노드부터 마지막 노드까지 순회
            if (*(cur->data) == value) {    // value를 가진 노드 제거
                cur->prev->next = cur->next;    // cur 이전노드 next 변경
                cur->next->prev = cur->prev;    // cur 다음노드 prev 변경
                if (cur == head)
                    head = head->next;
                delete cur;
                n--;
                return;
            }
            cur = cur->next; // cur 이동
        }
    }

    // 반복자 구현
    struct cir_list_it {
    private:
        node_ptr ptr;

    public:
        // 생성자
        cir_list_it(node_ptr p) : ptr(p) {}

        // 접근자
        T& operator*() { return *(ptr->data); }
        node_ptr get() { return ptr; }

        // ++ 연산자
        cir_list_it& operator++() {  // 선행 증가
            ptr = ptr->next;
            return *this;
        }

        cir_list_it operator++(int) { // 후행 증가
            cir_list_it it = *this;
            ++(*this);
            return it;
        }

        // -- 연산자
        cir_list_it& operator--() {  // 선행 감소
            ptr = ptr->prev;
            return *this;
        }

        cir_list_it operator--(int) { // 후행 감소
            cir_list_it it = *this;
            --(*this);
            return it;
        }

        // 관계 연산자 (범위 기반 for문 사용을 위해 필요)
        friend bool operator==(const cir_list_it& it1,
                               const cir_list_it& it2) {
            return it1.ptr == it2.ptr;
        }

        friend bool operator!=(const cir_list_it& it1,
                               const cir_list_it& it2) {
            return it1.ptr != it2.ptr;
        }
    };

    cir_list_it begin() { return cir_list_it {head}; }
    cir_list_it begin() const { return cir_list_it {head}; }
    cir_list_it end() { return cir_list_it {head->prev}; }
    cir_list_it end() const { return cir_list_it {head->prev}; }

    // 복사 생성자
    cir_list(const cir_list<T>& other) : cir_list() {
        // 역순 삽입 (원형 리스트라 방향은 상관없음)
        for (const auto& i : other)
            insert(i);
    }

    // 초기화 리스트 생성자
    cir_list(const std::initializer_list<T>& il) : head(NULL), n(0) {
        // 역순 삽입
        for (const auto& i : il)
            insert(i);
    }

    // 소멸자
    ~cir_list() {
        while (size()) {
            erase(*(head->data));
        }

        delete head;
    }
};

// 음악 재생 목록 클래스
struct playlist {
    cir_list<int> list;

    // 음악 추가
    void insert(int song) { list.insert(song); }
    // 음악 제거
    void erase(int song) { list.erase(song); }
    // 음악 목록 출력
    void loopOnce() {
        for (auto& song : list)
            std::cout << song << " ";
        std::cout << std::endl;
    }
};

int main() {

    playlist pl;
    pl.insert(1);
    pl.insert(2);
    std::cout << "첫 번째 재생 목록 : ";
    pl.loopOnce();

    playlist pl2 = pl;
    pl2.erase(2);
    pl2.insert(3);
    std::cout << "두 번째 재생 목록 : ";
    pl2.loopOnce();

    return 0;
}