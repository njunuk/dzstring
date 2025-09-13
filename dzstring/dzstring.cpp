#include <iostream>
#include <cstring>
using namespace std;// для strlen, strcpy

class String {
private:
    char* data;
    size_t size;

public:
    //конструктор за замовчуванням
    String() {
        data = nullptr;
        size = 0;
    }

    //конструктор з параметрами
    String(const char* str) {
        size = strlen(str);
        data = new char[size + 1];
        strcpy(data, str);
    }

    //конструктор копіювання
    String(const String& other) {
        size = other.size;
        data = new char[size + 1];
        strcpy(data, other.data);
    }

    //конструктор переміщення
    String(String&& other) noexcept {
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
    }

    //оператор присвоєння з копіюванням
    String& operator=(const String& other) {
        if (this != &other) {  // захист від самоприсвоєння
            delete[] data;    // звільняємо старі дані
            size = other.size;
            data = new char[size + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    //оператор присвоєння з переміщенням
    String& operator=(String&& other) noexcept {
        if (this != &other) {
            delete[] data;  // звільняємо старі дані
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }

    String operator+(const String& other) const { //конкатрація рядків
        size_t newSize = size + other.size;
        char* newData = new char[newSize + 1];

        strcpy(newData, data);
        strcat(newData, other.data);

        return String(newData);
    }

    //деструктор
    ~String() {
        delete[] data;
    }

    //прінт
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

// Тестування
int main() {
    String a("Hello");
    String a1("World!");
    String a2("Hello ");
    String b = a;   // конструктор копіювання
    String c = std::move(a); // конструктор переміщення

    b.print();
    c.print();

    String v = a2 + a1;
    v.print();
}
