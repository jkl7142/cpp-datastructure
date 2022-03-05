#include <iostream>
#include <cctype>
#include <string>

using namespace std;

bool isHex(string str) {
    // str[0]부터 문자 2개, 앞에 두 문자가 "0x"인지
    if (str.substr(0, 2) == "0x") {
        // 3번째 부터 끝까지 판별
        string subStr = str.substr(2);
        // 해당 문자가 아닌 문자가 있으면 string::npos
        if (subStr.find_first_not_of("0123456789abcdef") == string::npos)
            return true;
    }

    return false;
}

bool isOct(string str) {
    // str[0]이 "0"인지
    if (str[0] == '0') {
        // 2번째 부터 끝까지 판별
        string subStr = str.substr(1);
        // 해당 문자가 아닌 문자가 있으면 string::npos
        if (subStr.find_first_not_of("0123456789") == string::npos)
            return true;

        /*
        for (int i = 1; i < str.length(); i++) {
            if (isdigit(str[i]))
                continue;
            else
                return false;
        }

        return true;
        */
    }

    return false;
}

bool isBin(string str) {
    if (str.find_first_not_of("01") == string::npos)
        return true;
    else
        return false;
}

int main() {

    // 숫자인지 판별
    string numstr = "123abc";
    isdigit(numstr[0]); // "1" - true
    isdigit(numstr[3]); // "3" - true
    isdigit(numstr[5]); // "b" - false

    // isupper() : 대문자인지 판별
    // islower() : 소문자인지 판별
    // isalpha() : 알파벳인지 판별
    // isspace() : 공백인지 판별

    // tolower() : 대문자 -> 소문자
    // toupper() : 소문자 -> 대문자

    string bin = "1001";
    string oct = "012";
    string hex = "0xa";

    isBin(bin);
    isOct(oct);
    isHex(hex);

    return 0;
}