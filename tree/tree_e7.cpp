/*
*   Exercise 7 : 트리 구조 만들기
*/

#include <iostream>
#include <queue>

// 이진 트리 노드
struct node {
    std::string position;
    node* first;
    node* second;
};

// 루트 노드
struct org_tree {
    node* root;

    // 루트 노드 생성
    static org_tree create_org_structure(const std::string& pos) {
        org_tree tree;
        tree.root = new node {pos, NULL, NULL};
        return tree;
    }

    // 특정 직책 이름에 해당하는 노드를 찾아서 반환
    static node* find(node* root, const std::string& value) {
        if (root == NULL)
            return NULL;
        
        if (root->position == value)
            return root;

        // first 노드를 먼저 탐색
        auto firstFound = org_tree::find(root->first, value);

        if (firstFound != NULL)
            return firstFound;

        // second 노드 탐색
        return org_tree::find(root->second, value);
    }

    // 노드 삽입
    bool addSubordinate(const std::string& manager, const std::string& subordinate) {
        auto managerNode = org_tree::find(root, manager);

        if (!managerNode) {
            std::cout << manager << "을(를) 찾을 수 없습니다: " << std::endl;
            return false;
        }

        if (managerNode->first && managerNode->second) {
            std::cout << manager << " 아래에 " << subordinate << "을(를) 추가할 수 없습니다." << std::endl;
            return false;
        }

        if (!managerNode->first)
            managerNode->first = new node {subordinate, NULL, NULL};
        else
            managerNode->second = new node {subordinate, NULL, NULL};

        std::cout << manager << " 아래에 " << subordinate << "을(를) 추가했습니다." << std::endl;

        return true;
    }
};

int main() {

    auto tree = org_tree::create_org_structure("CEO");

    tree.addSubordinate("CEO", "부사장");
    tree.addSubordinate("부사장", "IT부장");
    tree.addSubordinate("부사장", "마케팅부장");
    tree.addSubordinate("IT부장", "보안팀장");
    tree.addSubordinate("IT부장", "앱개발팀장");
    tree.addSubordinate("마케팅부장", "물류팀장");
    tree.addSubordinate("마케팅부장", "홍보팀장");
    tree.addSubordinate("부사장", "재무부장");

    return 0;
}