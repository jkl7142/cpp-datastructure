#include <iostream>
#include <string>
#include <vector>

using namespace std;

// sep�� ���� �и� ��, ����ϴ� �Լ�
void parsing(string str, string sep) {
    size_t prev = 0, curr;
    curr = str.find(sep);

    while (curr != string::npos) {
        // prev ���� curr���� ���ڿ��� ����
        string subStr = str.substr(prev, curr - prev);
        cout << subStr << "\n";
        prev = curr + 1;

        // prev ���� sep ��ġ�� ã��
        curr = str.find(sep, prev);
    }

    cout << str.substr(prev, curr - prev);
}

// sep�� ���� �и� ��, �迭�� ����, �迭 ��ȯ
vector<string> parsedVector(string str, string sep) {
    vector<string> result;
    size_t prev = 0, curr;
    curr = str.find(sep);

    while (curr != string::npos) {
        // prev ���� curr���� ���ڿ��� ����
        string subStr = str.substr(prev, curr - prev);
        result.push_back(subStr);
        prev = curr + 1;

        // prev ���� sep ��ġ�� ã��
        curr = str.find(sep, prev);
    }

    result.push_back(str.substr(prev, curr - prev));

    return result;
}

int main() {

    // ���ڿ� �и�
    string str = "I am Iron Man";
    
    parsing(str, " ");

    vector<string> strs = parsedVector(str, " "); // {"I", "am", "Iron", "Man"}

    for (string s : strs) {
        cout << s << endl;
    }

    return 0;
}