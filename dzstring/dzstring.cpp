#include <iostream>
#include <cstring>
using namespace std;// ��� strlen, strcpy

class String {
private:
    char* data;
    size_t size;

public:
    //����������� �� �������������
    String() {
        data = nullptr;
        size = 0;
    }

    //����������� � �����������
    String(const char* str) {
        size = strlen(str);
        data = new char[size + 1];
        strcpy(data, str);
    }

    //����������� ���������
    String(const String& other) {
        size = other.size;
        data = new char[size + 1];
        strcpy(data, other.data);
    }

    //����������� ����������
    String(String&& other) noexcept {
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
    }

    //�������� ��������� � ����������
    String& operator=(const String& other) {
        if (this != &other) {  // ������ �� �������������
            delete[] data;    // ��������� ���� ���
            size = other.size;
            data = new char[size + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    //�������� ��������� � �����������
    String& operator=(String&& other) noexcept {
        if (this != &other) {
            delete[] data;  // ��������� ���� ���
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }

    String operator+(const String& other) const { //����������� �����
        size_t newSize = size + other.size;
        char* newData = new char[newSize + 1];

        strcpy(newData, data);
        strcat(newData, other.data);

        return String(newData);
    }

    //����������
    ~String() {
        delete[] data;
    }

    //����
    void print() const {
        cout << data << endl;
    }
    char* returnchar(){
        return data;
    }
    String returnstr() {
        return *this;
    }
};

// ����������
int main() {
    String a("Hello");
    String a1("World!");
    String a2("Hello ");
    String b = a;   // ����������� ���������
    String c = std::move(a); // ����������� ����������

    b.print();
    c.print();

    String v = a2 + a1;
    v.print();
}
