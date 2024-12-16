#include <iostream>
#include <time.h>
using namespace std;

// и так Класс Point (точка на плоскости)
class Point {
    int x;
    int y;

public:
    // Конструктор 
    Point() : x(0), y(0) {}

    // Конструктор с параметрами
    Point(int x, int y) : x(x), y(y) {}

    //Тут перегрузка оператора присваивания 
    Point& operator=(const Point& other) {
        if (this == &other) return *this; // Проверка на самоприсваивание
        x = other.x;
        y = other.y;
        return *this;
    }

    // Перегрузка оператора вывода '<<' для печати Point
    friend ostream& operator<<(ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    srand(time(0));

    // MyArray для int
    cout << "Masiv int:\n";
    }

    // Метод для заполнения случайными значениями поставим сотку
    void Randomize() {
        x = rand() % 100;
        y = rand() % 100;
    }
};

// ТУТ Шаблонный класс MyArray работает
template <class T>
class MyArray {
    T* mas = nullptr; // Указатель на массив
    int size;         // Размер массива

public:
    MyArray();              // Конструктор по умолчанию
    void Output();          // Вывод элементов массива
    ~MyArray();             // Деструктор
    T operator[](int index); // Перегрузка оператора 
    int GetSize() const { return size; }
    T* GetPtr() const { return mas; }
    void SetSize(int s) { size = s; }
    void SetPtr(T* ptr) { mas = ptr; }
};

// Конструктор для MyArray
template <class T>
MyArray<T>::MyArray() {
    size = 10;
    mas = new T[10];
    for (int i = 0; i < size; i++) {
        mas[i] = T(); // Заполнение  для (или случайными значениями)
    }
}

// Специализация конструктора для класса Point
template <>
MyArray<Point>::MyArray() {
    size = 10;
    mas = new Point[10];
    for (int i = 0; i < size; i++) {
        mas[i].Randomize(); // Заполнение случайными значениями для Point
    }
}

// Метод для вывода массива
template <class T>
void MyArray<T>::Output() {
    for (int i = 0; i < size; i++) {
        cout << mas[i] << "\t";
    }
    cout << endl << endl;
}

// Деструктор для MyArray
template <class T>
MyArray<T>::~MyArray() {
    if (mas != nullptr) {
        delete[] mas;
    }
}

// Перегрузка оператора 
template <class T>
T MyArray<T>::operator[](int index) {
    return mas[index];
}

// Главная функция
int main() {
    MyArray<int> obj1;
    obj1.Output();

    // MyArray для char
    cout << "Masiv char:\n";
    MyArray<char> obj2;
    obj2.Output();

    // MyArray для double
    cout << "Masiv double:\n";
    MyArray<double> obj3;
    obj3.Output();

    // MyArray для Point
    cout << "Masiv Point:\n";
    MyArray<Point> obj4;
    obj4.Output();

    system("pause");
    return 0;
}

//Это было сложно но будет сложнее такова жизнь хах