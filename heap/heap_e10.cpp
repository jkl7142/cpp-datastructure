/*
*   Exercise 10 : �߾Ӱ� ���ϱ�
*/
#include <iostream>
#include <queue>
#include <vector>

// �����͸� ������ �����̳�
struct median {
    std::priority_queue<int> maxHeap;   // �߾Ӱ����� ���� ������ ť
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;  // �߾Ӱ����� ū ������ ť

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
                // minHeap�� ž ���Ҹ� maxHeap�� �ְ� data�� minHeap�� ����
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

    // �߾Ӱ� ��ȯ
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
    std::cout << "1 ���� �� �߾Ӱ�: " << med.get() << std::endl;

    med.insert(5);
    std::cout << "5 ���� �� �߾Ӱ�: " << med.get() << std::endl;

    med.insert(2);
    std::cout << "2 ���� �� �߾Ӱ�: " << med.get() << std::endl;

    med.insert(10);
    std::cout << "10 ���� �� �߾Ӱ�: " << med.get() << std::endl;

    med.insert(40);
    std::cout << "40 ���� �� �߾Ӱ�: " << med.get() << std::endl;

    return 0;
}