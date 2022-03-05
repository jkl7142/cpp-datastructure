#include <iostream>
#include <string>

using namespace std;

int main() {

    // 1. 초기화
    string create_str1;
    string create_str2("String");
    string create_str3(create_str2);    // 복사

    // 2. 문자 반환
    string s = "ABCDE";
    s[0];       // 'A'
    s[1];       // 'B'
    s.at(2);    // 'C'
    s.at(3);    // 'D'
    s.front();  // 'A'
    s.back();   // 'E'

    // 3. 문자열 길이
    string length_str("ABCDE");
    length_str.length(); // == 5
    length_str.size(); // == 5

    // 4. 추가
    string lStr = "left";
    string rStr = "right";
    lStr + rStr;    // "leftright"
    lStr += rStr;   // lStr == "leftright"
    lStr.append("mid");  // lStr == "leftrightmid"

    // 5. 비교
    string aStr = "Abcde";
    string bStr = "Bcdef";
    if (aStr < bStr);    // == 1 : aStr이 사전 순 앞
    if (aStr == bStr);   // != 1 : 같으면 1
    aStr.compare(bStr);  // 0이면 같음, 양수면 aStr > bStr, 음수면 aStr < bStr

    // 6. 타입 변환
    // #include <cstdlib>
    string cStr;
    cStr.c_str();   // string -> char*

    char* cp;
    atoi(cp);       // char* -> int;

    atoi(cStr.c_str()); // string -> char* -> int

    // #include <string>
    string sto;
    stoi(sto);  // string -> int
    stol(sto);  // string -> long
    stof(sto);  // string -> flot
    stod(sto);  // string -> double

    string sto2 = "12345ABCDE";
    size_t sz;
    int num = stoi(sto2, &sz);
    sto2.substr(sz);
    // num == 12345
    // sz = 5
    // sto2.substr(sz) == ABCDE

    to_string(num); // int -> string

    // 7. 그 외 함수들
    string fStr = "KimJiHyeok";
    int idx = fStr.find("JiHyeok");   // J의 위치인 3 반환
    fStr.find_first_of("abcde");    // e가 fStr[7]에 있으므로 7 반환
    fStr.find_first_not_of("KimJiHyeok"); // 해당 문자를 제외한 다른 문자가 없으므로 string::npos 반환

    fStr.substr(idx);   // 3부터 끝까지 "JiHyeok" 반환
    fStr.substr(idx, 2); // 3부터 길이 2만큼 "Ji" 반환 3, 4


    return 0;
}