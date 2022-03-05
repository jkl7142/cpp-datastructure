#include <iostream>
#include <string>

using namespace std;

int main() {

    // 1. �ʱ�ȭ
    string create_str1;
    string create_str2("String");
    string create_str3(create_str2);    // ����

    // 2. ���� ��ȯ
    string s = "ABCDE";
    s[0];       // 'A'
    s[1];       // 'B'
    s.at(2);    // 'C'
    s.at(3);    // 'D'
    s.front();  // 'A'
    s.back();   // 'E'

    // 3. ���ڿ� ����
    string length_str("ABCDE");
    length_str.length(); // == 5
    length_str.size(); // == 5

    // 4. �߰�
    string lStr = "left";
    string rStr = "right";
    lStr + rStr;    // "leftright"
    lStr += rStr;   // lStr == "leftright"
    lStr.append("mid");  // lStr == "leftrightmid"

    // 5. ��
    string aStr = "Abcde";
    string bStr = "Bcdef";
    if (aStr < bStr);    // == 1 : aStr�� ���� �� ��
    if (aStr == bStr);   // != 1 : ������ 1
    aStr.compare(bStr);  // 0�̸� ����, ����� aStr > bStr, ������ aStr < bStr

    // 6. Ÿ�� ��ȯ
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

    // 7. �� �� �Լ���
    string fStr = "KimJiHyeok";
    int idx = fStr.find("JiHyeok");   // J�� ��ġ�� 3 ��ȯ
    fStr.find_first_of("abcde");    // e�� fStr[7]�� �����Ƿ� 7 ��ȯ
    fStr.find_first_not_of("KimJiHyeok"); // �ش� ���ڸ� ������ �ٸ� ���ڰ� �����Ƿ� string::npos ��ȯ

    fStr.substr(idx);   // 3���� ������ "JiHyeok" ��ȯ
    fStr.substr(idx, 2); // 3���� ���� 2��ŭ "Ji" ��ȯ 3, 4


    return 0;
}