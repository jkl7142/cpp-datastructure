/*
*   Exercise 10 : 중앙값 구하기
*/
#include <iostream>
#include <queue>
#include <vector>

// 데이터를 저장할 컨테이너
struct median {
    std::priority_queue<int> maxHeap;   // 중앙값보다 작은 데이터 큐
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;  // 중앙값보다 큰 데이터 큐

    void insert(int data) {
        if (maxHeap.size() == 0) {
            maxHeap.push(data);
            return;
        }

        if (maxHeap.size() == minHeap.size()) {
            if (data <= get())
                maxHeap.push(data);
            else
                minHeap.push(data);

            return;
        }

        if (maxHeap.size() < minHeap.size()) {
            if (data > get()) {
                // minHeap의 탑 원소를 maxHeap에 넣고 data를 minHeap에 삽입
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(data);
            }
            else
                maxHeap.push(data);

            return;
        }

        // maxHeap.size() > minHeap()
        if (data < get()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(data);
        }
        else
            minHeap.push(data);
    }

    // 중앙값 반환
    double get() {
        if (maxHeap.size() == minHeap.size())
            return (maxHeap.top() + minHeap.top()) / 2.0;

        if (maxHeap.size() < minHeap.size())
            return minHeap.top();
        
        return maxHeap.top();
    }
};

int main() {

    median med;

    med.insert(1);
    std::cout << "1 삽입 후 중앙값: " << med.get() << std::endl;

    med.insert(5);
    std::cout << "5 삽입 후 중앙값: " << med.get() << std::endl;

    med.insert(2);
    std::cout << "2 삽입 후 중앙값: " << med.get() << std::endl;

    med.insert(10);
    std::cout << "10 삽입 후 중앙값: " << med.get() << std::endl;

    med.insert(40);
    std::cout << "40 삽입 후 중앙값: " << med.get() << std::endl;

    return 0;
}