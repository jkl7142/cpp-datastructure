/*
*   Activity 5 : 힙을 이용한 데이터 리스트 병합
*/

#include <iostream>
#include <algorithm>
#include <vector>

// 힙 노드
struct node {
    int data;
    int listPosition;
    int dataPosition;
};

std::vector<int> merge(const std::vector<std::vector<int>>& input) {

    // 최소 힙 비교자
    auto comparator = [](const node& left, const node& right) {
        if (left.data == right.data)
            return left.listPosition > right.listPosition;
        return left.data > right.data;
    };

    // 각각의 리스트에서 가장 작은 원소로 최소 힙 구성
    std::vector<node> heap;
    for (int i = 0; i < input.size(); i++) {
        heap.push_back({input[i][0], i, 0});
        // push_heap : 맨 마지막 원소를 포함하여 힙으로 만든다
        std::push_heap(heap.begin(), heap.end(), comparator);
    }

    // 힙에서 원소 하나를 꺼내 출력 벡터에 추가
    // 해당 원소가 있던 리스트에서 다음 원소를 힙에 삽입
    // 힙이 빌 때까지 반복
    std::vector<int> result;
    while (!heap.empty()) {
        // pop_heap : 가장 큰 값을 맨 뒤로 보내고 남은 원소들을 다시 힙으로 만든다
        std::pop_heap(heap.begin(), heap.end(), comparator);
        auto min = heap.back();
        heap.pop_back();

        result.push_back(min.data);
        int nextIndex = min.dataPosition + 1;
        if (nextIndex < input[min.listPosition].size()) {
            heap.push_back({input[min.listPosition][nextIndex], min.listPosition, nextIndex});
            std::push_heap(heap.begin(), heap.end(), comparator);
        }
    }

    return result;
}

int main() {
    std::vector<int> v1 = {1, 3, 8, 15, 105};
    std::vector<int> v2 = {2, 3, 10, 11, 16, 20, 25};
    std::vector<int> v3 = {-2, 100, 1000};
    std::vector<int> v4 = {-1, 0, 14, 18};

    auto result = merge({v1, v2, v3, v4});

    for (auto i : result)
        std::cout << i << ' ';
    std::cout << std::endl;

    return 0;
}