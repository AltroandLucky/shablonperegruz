#include <iostream>
#include <time.h>
using namespace std;

// � ��� ����� Point (����� �� ���������)
class Point {
    int x;
    int y;

public:
    // ����������� 
    Point() : x(0), y(0) {}

    // ����������� � �����������
    Point(int x, int y) : x(x), y(y) {}

    //��� ���������� ��������� ������������ 
    Point& operator=(const Point& other) {
        if (this == &other) return *this; // �������� �� ����������������
        x = other.x;
        y = other.y;
        return *this;
    }

    // ���������� ��������� ������ '<<' ��� ������ Point
    friend ostream& operator<<(ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    srand(time(0));

    // MyArray ��� int
    cout << "Masiv int:\n";
    }

    // ����� ��� ���������� ���������� ���������� �������� �����
    void Randomize() {
        x = rand() % 100;
        y = rand() % 100;
    }
};

// ��� ��������� ����� MyArray ��������
template <class T>
class MyArray {
    T* mas = nullptr; // ��������� �� ������
    int size;         // ������ �������

public:
    MyArray();              // ����������� �� ���������
    void Output();          // ����� ��������� �������
    ~MyArray();             // ����������
    T operator[](int index); // ���������� ��������� 
    int GetSize() const { return size; }
    T* GetPtr() const { return mas; }
    void SetSize(int s) { size = s; }
    void SetPtr(T* ptr) { mas = ptr; }
};

// ����������� ��� MyArray
template <class T>
MyArray<T>::MyArray() {
    size = 10;
    mas = new T[10];
    for (int i = 0; i < size; i++) {
        mas[i] = T(); // ����������  ��� (��� ���������� ����������)
    }
}

// ������������� ������������ ��� ������ Point
template <>
MyArray<Point>::MyArray() {
    size = 10;
    mas = new Point[10];
    for (int i = 0; i < size; i++) {
        mas[i].Randomize(); // ���������� ���������� ���������� ��� Point
    }
}

// ����� ��� ������ �������
template <class T>
void MyArray<T>::Output() {
    for (int i = 0; i < size; i++) {
        cout << mas[i] << "\t";
    }
    cout << endl << endl;
}

// ���������� ��� MyArray
template <class T>
MyArray<T>::~MyArray() {
    if (mas != nullptr) {
        delete[] mas;
    }
}

// ���������� ��������� 
template <class T>
T MyArray<T>::operator[](int index) {
    return mas[index];
}

// ������� �������
int main() {
    MyArray<int> obj1;
    obj1.Output();

    // MyArray ��� char
    cout << "Masiv char:\n";
    MyArray<char> obj2;
    obj2.Output();

    // MyArray ��� double
    cout << "Masiv double:\n";
    MyArray<double> obj3;
    obj3.Output();

    // MyArray ��� Point
    cout << "Masiv Point:\n";
    MyArray<Point> obj4;
    obj4.Output();

    system("pause");
    return 0;
}

//��� ���� ������ �� ����� ������� ������ ����� ���