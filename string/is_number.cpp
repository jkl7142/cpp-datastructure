#include <iostream>
#include <cctype>
#include <string>

using namespace std;

bool isHex(string str) {
    // str[0]���� ���� 2��, �տ� �� ���ڰ� "0x"����
    if (str.substr(0, 2) == "0x") {
        // 3��° ���� ������ �Ǻ�
        string subStr = str.substr(2);
        // �ش� ���ڰ� �ƴ� ���ڰ� ������ string::npos
        if (subStr.find_first_not_of("0123456789abcdef") == string::npos)
            return true;
    }

    return false;
}

bool isOct(string str) {
    // str[0]�� "0"����
    if (str[0] == '0') {
        // 2��° ���� ������ �Ǻ�
        string subStr = str.substr(1);
        // �ش� ���ڰ� �ƴ� ���ڰ� ������ string::npos
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

    // �������� �Ǻ�
    string numstr = "123abc";
    isdigit(numstr[0]); // "1" - true
    isdigit(numstr[3]); // "3" - true
    isdigit(numstr[5]); // "b" - false

    // isupper() : �빮������ �Ǻ�
    // islower() : �ҹ������� �Ǻ�
    // isalpha() : ���ĺ����� �Ǻ�
    // isspace() : �������� �Ǻ�

    // tolower() : �빮�� -> �ҹ���
    // toupper() : �ҹ��� -> �빮��

    string bin = "1001";
    string oct = "012";
    string hex = "0xa";

    isBin(bin);
    isOct(oct);
    isHex(hex);

    return 0;
}