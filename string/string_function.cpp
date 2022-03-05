#include <iostream>
#include <string>
#include <vector>

using namespace std;

// sep에 맞춰 분리 후, 출력하는 함수
void parsing(string str, string sep) {
    size_t prev = 0, curr;
    curr = str.find(sep);

    while (curr != string::npos) {
        // prev 부터 curr까지 문자열을 저장
        string subStr = str.substr(prev, curr - prev);
        cout << subStr << "\n";
        prev = curr + 1;

        // prev 부터 sep 위치를 찾음
        curr = str.find(sep, prev);
    }

    cout << str.substr(prev, curr - prev);
}

// sep에 맞춰 분리 후, 배열에 저장, 배열 반환
vector<string> parsedVector(string str, string sep) {
    vector<string> result;
    size_t prev = 0, curr;
    curr = str.find(sep);

    while (curr != string::npos) {
        // prev 부터 curr까지 문자열을 저장
        string subStr = str.substr(prev, curr - prev);
        result.push_back(subStr);
        prev = curr + 1;

        // prev 부터 sep 위치를 찾음
        curr = str.find(sep, prev);
    }

    result.push_back(str.substr(prev, curr - prev));

    return result;
}

int main() {

    // 문자열 분리
    string str = "I am Iron Man";
    
    parsing(str, " ");

    vector<string> strs = parsedVector(str, " "); // {"I", "am", "Iron", "Man"}

    for (string s : strs) {
        cout << s << endl;
    }

    return 0;
}