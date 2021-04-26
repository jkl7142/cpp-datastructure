/*
*   Activity 4 : 파일 시스템 자료 구조 구현
*/

#include <iostream>
#include <vector>
#include <algorithm>

// N-항 노드
struct n_ary_node {
    std::string name;
    bool is_dir;
    std::vector<n_ary_node*> children;
};

// N-항 노드를 이용한 트리
struct file_system {
    using node = n_ary_node;
    using node_ptr = node*;

private:
    node_ptr root;
    node_ptr cwd;   // 현재 디렉토리

public:
    file_system() {
        root = new node {"/", true, {}};
        cwd = root; // 처음엔 루트가 현재 디렉토리
    }

    // 파일/디렉토리를 찾는 find
    node_ptr find(const std::string& path) {
        if (path[0] == '/')     // 절대 경로
            return find_impl(root, path.substr(1));
        else
            return find_impl(cwd, path);
    }

    // std::str.find("") : str에서 단어를 찾고 없으면 string::npos를 반환한다
private:
    node_ptr find_impl(node_ptr directory, const std::string& path) {
        if (path.empty())
            return directory;
        auto sep = path.find('/');
        std::string current_path = sep == std::string::npos ? path : path.substr(0, sep);   // '/'가 있으면 맨 첫번째 문자열
        std::string rest_path = sep == std::string::npos ? "" : path.substr(sep + 1);       // '/'가 있으면 첫번째 '/' 다음 모든 문자열
        auto found = std::find_if(directory->children.begin(), directory->children.end(),
            [&](const node_ptr child) {
                return child->name == current_path;
            });

        if (found != directory->children.end())
            return find_impl(*found, rest_path);

        return NULL;
    }

public:
    // 파일/디렉토리 추가
    bool add(const std::string& path, bool is_dir) {
        if (path[0] == '/')
            return add_impl(root, path.substr(1), is_dir);
        else
            return add_impl(cwd, path, is_dir);
    }

private:
    bool add_impl(node_ptr directory, const std::string& path, bool is_dir) {
        if (!directory->is_dir) {
            std::cout << directory->name << "은(는) 파일입니다." << std::endl;
            return false;
        }

        auto sep = path.find('/');

        // path에 '/'가 없는 경우
        if (sep == std::string::npos)
        {
            auto found = std::find_if(directory->children.begin(), directory->children.end(),
                [&](const node_ptr child) {
                    return child->name == path;
                });
            
            // 동일한 파일/디렉토리가 있는 경우
            if (found != directory->children.end()) {
                std::cout << directory->name << "에 이미 " << path << " 이름의 파일/디렉토리가 있습니다." << std::endl;
                return true;
            }

            // 해당 파일/디렉토리를 추가
            directory->children.push_back(new node {path, is_dir, {}});
            return true;
        }

        // path에 '/'가 있는 경우, 즉, 디렉토리 이름을 포함하고 있는 경우
        std::string next_dir = path.substr(0, sep);
        auto found = std::find_if(directory->children.begin(), directory->children.end(), 
            [&](const node_ptr child) {
                return child->name == next_dir && child->is_dir;
            });

        if (found != directory->children.end()) {
            return add_impl(*found, path.substr(sep + 1), is_dir);
        }

        // path에 디렉토리 이름이 포함되어 있지만, 해당 디렉토리가 없는 경우
        std::cout << directory->name << "에 " << next_dir << " 이름의 디렉토리가 없습니다." << std::endl;
        return false;
    }

public:
    // 파일/디렉토리 이동
    bool change_dir(const std::string& path) {
        auto found = find(path);
        if (found && found->is_dir) {
            cwd = found;
            std::cout << "현재 디렉토리를 " << cwd->name << "로 이동합니다." << std::endl;
            return true;
        }

        std::cout << path << "경로를 찾을 수 없습니다." << std::endl;
        return false;
    }

public:
    // 파일/디렉토리 목록 출력
    void show_path(const std::string& path) {
        auto found = find(path);
        if (!found) {
            std::cout << path << " 경로가 존재하지 않습니다." << std::endl;
            return;
        }

        if (found->is_dir) {
            for (auto child : found->children) {
                std::cout << (child->is_dir ? "d " : "- ") << child->name << std::endl;
            }
        }
        else {
            std::cout << "- " << found->name << std::endl;
        }
    }
};

int main() {

    file_system fs;
    fs.add("usr", true);        // "/"에 usr 디렉토리 추가
    fs.add("etc", true);        // "/"에 etc 디렉토리 추가
    fs.add("var", true);        // "/"에 var 디렉토리 추가
    fs.add("tmp_file", false);  // "/"에 tmp_file 파일 추가

    std::cout << "\"/\"의 파일/디렉토리 목록:" << std::endl;
    fs.show_path("/");
    std::cout << std::endl;

    fs.change_dir("usr");
    fs.add("gilbut", true);
    fs.add("gilbut/Downloads", true);
    fs.add("gilbut/Downloads/newFile.cpp", false);

    std::cout << "현재 디렉토리에서 usr의 파일/디렉토리 목록: " << std::endl;
    fs.show_path("usr");    // 현재 디렉토리에는 usr 디렉토리가 없으므로 정상적인 출력 x

    std::cout << "\"/usr\"의 파일/디렉토리 목록:" << std::endl;
    fs.show_path("/usr");   // 절대 경로

    std::cout << "\"/usr/gilbut/Downloads\"의 파일/디렉토리 목록" << std::endl;
    fs.show_path("/usr/gilbut/Downloads");

    return 0;
}