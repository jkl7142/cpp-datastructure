/*
*   Activity 4 : ���� �ý��� �ڷ� ���� ����
*/

#include <iostream>
#include <vector>
#include <algorithm>

// N-�� ���
struct n_ary_node {
    std::string name;
    bool is_dir;
    std::vector<n_ary_node*> children;
};

// N-�� ��带 �̿��� Ʈ��
struct file_system {
    using node = n_ary_node;
    using node_ptr = node*;

private:
    node_ptr root;
    node_ptr cwd;   // ���� ���丮

public:
    file_system() {
        root = new node {"/", true, {}};
        cwd = root; // ó���� ��Ʈ�� ���� ���丮
    }

    // ����/���丮�� ã�� find
    node_ptr find(const std::string& path) {
        if (path[0] == '/')     // ���� ���
            return find_impl(root, path.substr(1));
        else
            return find_impl(cwd, path);
    }

    // std::str.find("") : str���� �ܾ ã�� ������ string::npos�� ��ȯ�Ѵ�
private:
    node_ptr find_impl(node_ptr directory, const std::string& path) {
        if (path.empty())
            return directory;
        auto sep = path.find('/');
        std::string current_path = sep == std::string::npos ? path : path.substr(0, sep);   // '/'�� ������ �� ù��° ���ڿ�
        std::string rest_path = sep == std::string::npos ? "" : path.substr(sep + 1);       // '/'�� ������ ù��° '/' ���� ��� ���ڿ�
        auto found = std::find_if(directory->children.begin(), directory->children.end(),
            [&](const node_ptr child) {
                return child->name == current_path;
            });

        if (found != directory->children.end())
            return find_impl(*found, rest_path);

        return NULL;
    }

public:
    // ����/���丮 �߰�
    bool add(const std::string& path, bool is_dir) {
        if (path[0] == '/')
            return add_impl(root, path.substr(1), is_dir);
        else
            return add_impl(cwd, path, is_dir);
    }

private:
    bool add_impl(node_ptr directory, const std::string& path, bool is_dir) {
        if (!directory->is_dir) {
            std::cout << directory->name << "��(��) �����Դϴ�." << std::endl;
            return false;
        }

        auto sep = path.find('/');

        // path�� '/'�� ���� ���
        if (sep == std::string::npos)
        {
            auto found = std::find_if(directory->children.begin(), directory->children.end(),
                [&](const node_ptr child) {
                    return child->name == path;
                });
            
            // ������ ����/���丮�� �ִ� ���
            if (found != directory->children.end()) {
                std::cout << directory->name << "�� �̹� " << path << " �̸��� ����/���丮�� �ֽ��ϴ�." << std::endl;
                return true;
            }

            // �ش� ����/���丮�� �߰�
            directory->children.push_back(new node {path, is_dir, {}});
            return true;
        }

        // path�� '/'�� �ִ� ���, ��, ���丮 �̸��� �����ϰ� �ִ� ���
        std::string next_dir = path.substr(0, sep);
        auto found = std::find_if(directory->children.begin(), directory->children.end(), 
            [&](const node_ptr child) {
                return child->name == next_dir && child->is_dir;
            });

        if (found != directory->children.end()) {
            return add_impl(*found, path.substr(sep + 1), is_dir);
        }

        // path�� ���丮 �̸��� ���ԵǾ� ������, �ش� ���丮�� ���� ���
        std::cout << directory->name << "�� " << next_dir << " �̸��� ���丮�� �����ϴ�." << std::endl;
        return false;
    }

public:
    // ����/���丮 �̵�
    bool change_dir(const std::string& path) {
        auto found = find(path);
        if (found && found->is_dir) {
            cwd = found;
            std::cout << "���� ���丮�� " << cwd->name << "�� �̵��մϴ�." << std::endl;
            return true;
        }

        std::cout << path << "��θ� ã�� �� �����ϴ�." << std::endl;
        return false;
    }

public:
    // ����/���丮 ��� ���
    void show_path(const std::string& path) {
        auto found = find(path);
        if (!found) {
            std::cout << path << " ��ΰ� �������� �ʽ��ϴ�." << std::endl;
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
    fs.add("usr", true);        // "/"�� usr ���丮 �߰�
    fs.add("etc", true);        // "/"�� etc ���丮 �߰�
    fs.add("var", true);        // "/"�� var ���丮 �߰�
    fs.add("tmp_file", false);  // "/"�� tmp_file ���� �߰�

    std::cout << "\"/\"�� ����/���丮 ���:" << std::endl;
    fs.show_path("/");
    std::cout << std::endl;

    fs.change_dir("usr");
    fs.add("gilbut", true);
    fs.add("gilbut/Downloads", true);
    fs.add("gilbut/Downloads/newFile.cpp", false);

    std::cout << "���� ���丮���� usr�� ����/���丮 ���: " << std::endl;
    fs.show_path("usr");    // ���� ���丮���� usr ���丮�� �����Ƿ� �������� ��� x

    std::cout << "\"/usr\"�� ����/���丮 ���:" << std::endl;
    fs.show_path("/usr");   // ���� ���

    std::cout << "\"/usr/gilbut/Downloads\"�� ����/���丮 ���" << std::endl;
    fs.show_path("/usr/gilbut/Downloads");

    return 0;
}