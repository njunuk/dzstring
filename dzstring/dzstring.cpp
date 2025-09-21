#include <iostream>
#include <cstring>
using namespace std;// ��� strlen, strcpy

class String {
private:
    char* data;
    size_t size; //

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

    char operator[](size_t x) const { //����������� �����
        return data[x];
    }

    bool operator==(const String& other) const {
        return strcmp(data, other.data) == 0;
    }

    bool operator!=(const String& other) const {
        return strcmp(data, other.data) != 0;
    }

    void erase(size_t x, size_t x2) {
        for (size_t i = x; i + x2 <= size; ++i) {
            data[i] = data[i + x2];
        }

        size -= x2;
    }

    void replace(String x, size_t id1, size_t id2) {
        size_t counter = 0;
        for (size_t i = id1; i < id2; i++) {
            data[i] = x[counter];
            counter += 1;
        }
    }

    String substr(size_t id1, size_t id2) {
        size_t newsize = id2 - id1;
        char* newdata;
        newdata = new char[newsize + 1];
        size_t counter = 0;
        for (size_t i = id1; i < id2; i++) {
            newdata[counter] = data[i];
            counter += 1;
        }
        newdata[counter] = '\0';
        return String(newdata);
    }
    bool empty() {
        if (size == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    void insert(String x, size_t id) {
        size_t counter = 0;
        for (size_t i = id; i < id+x.size; i++) {
            data[i] = x[counter];
            counter += 1;
        }
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
    String a2("Hello");
    String a3("Hells");
    String b = a;   // ����������� ���������
    String c = move(a); // ����������� ����������

    String x = ("xxxxxxxxxx"); //10x
    String x2 = "12345";
    //String x0 = "";
    //x.replace(x2, 3, 7);
    //x.print(); //xxx1234xxx
    //String x3 = x2.substr(1, 4); //234
    //x3.print();
    //cout << x0.empty() << endl; //1
    x.insert(x2, 1);
    x.print(); //x12345xxxx

    //b.print();
    //c.print();
    //bool x = a2 == a3;
    //String v = a2 + a1;
    //cout << v[0] << endl;
    //cout << x << endl;
    //v.print();
    //a3.erase(0, 1);
    //a3.print();
}
