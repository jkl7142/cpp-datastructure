/*
*       Activity 6 : �� URL�� ª�� URL�� �����ϱ�
*/

#include <string>
#include <iostream>
#include <unordered_map>

struct URLService {
    using ActualURL = std::string;
    using TinyURL = std::string;

private:
    std::unordered_map<TinyURL, ActualURL> data;

public:
    std::pair<bool, ActualURL> lookup(const TinyURL& url) const {
        auto it = data.find(url);
        if (it == data.end()) { // ª�� URL�� ��ϵǾ� ���� ���� ���
            return std::make_pair(false, std::string());
        }
        else {
            return std::make_pair(true, it->second);
        }
    }

    // URL�� Ű�� ����ϴ� �Լ�
    bool registerURL(const ActualURL& actualURL, const TinyURL& tinyURL) {
        auto found = lookup(tinyURL).first;
        if (found) {
            return false;
        }
        
        data[tinyURL] = actualURL;
        return true;
    }

    // URL ����
    bool deregisterURL(const TinyURL& tinyURL) {
        auto found = lookup(tinyURL).first;
        if (found) {
            data.erase(tinyURL);
            return true;
        }

        return false;
    }

    // ��ϵǾ� �ִ� URL ���
    void printURLs() const {
        for (const auto& entry : data) {
            std::cout << entry.first << " -> " << entry.second << std::endl;
        }
        std::cout << std::endl;
    }
};

int main() {

    URLService service;

    // "https://py_dojang"
    if (service.registerURL("https://www.gilbut.co.kr/book/view?bookcode=BN002245", "https://py_dojang")) {
        std::cout << "https://py_dojang ���" << std::endl;
    }
    else {
        std::cout << "https://py_dojang ��� ����" << std::endl;
    }

    // "https://c_dojang"
    if (service.registerURL("https://www.gilbut.co.kr/book/view?bookcode=BN001484", "https://c_dojang")) {
        std::cout << "https://c_dojang ���" << std::endl;
    }
    else {
        std::cout << "https://c_dojang ��� ����" << std::endl;
    }

    // "https://opencv4"
    if (service.registerURL("https://www.gilbut.co.kr/book/view?bookcode=BN002402", "https://opencv4")) {
        std::cout << "https://opencv4 ���" << std::endl;
    }
    else {
        std::cout << "https://opencv4 ��� ����" << std::endl;
    }

    // "https://py_dojang" lookup
    auto pythonBook = service.lookup("https://py_dojang");
    if (pythonBook.first) {
        std::cout << "https://py_dojang ���� URL: " << pythonBook.second << std::endl;
    }
    else {
        std::cout << "https://py_dojang ���� URL�� ã�� �� �����ϴ�." << std::endl;
    }

    // "https://cpp_dojang" lookup
    auto cppBook = service.lookup("https://cpp_dojang");
    if (cppBook.first) {
        std::cout << "https://cpp_dojang ���� URL: " << cppBook.second << std::endl;
    }
    else {
        std::cout << "https://cpp_dojang ���� URL�� ã�� �� �����ϴ�." << std::endl;
    }

    // "https://c_dojang" deregister
    if (service.deregisterURL("https://c_dojang")) {
        std::cout << "c_dojang å URL ��� ����" << std::endl;
    }
    else {
        std::cout << "c_dojang å URL ��� ���� ����" << std::endl;
    }

    // "https://c_dojang" lookup
    auto findQtBook = service.lookup("https://c_dojang");
    if (findQtBook.first) {
        std::cout << "https://c_dojang ���� URL: " << findQtBook.second << std::endl;
    }
    else {
        std::cout << "https://c_dojang ���� URL�� ã�� �� �����ϴ�." << std::endl;
    }

    std::cout << "��ϵ� URL:" << std::endl;
    service.printURLs();

    return 0;
}