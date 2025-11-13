
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

// Цэгийн класс
class Point {
protected:
    float x_axis;
    float y_axis;

public:
    Point() : x_axis(0), y_axis(0) {}
    Point(float x, float y) : x_axis(x), y_axis(y) {}

    void setX(float x) { x_axis = x; }
    void setY(float y) { y_axis = y; }
    float getX() { return x_axis; }
    float getY() { return y_axis; }
};

// Дүрсийн үндсэн класс
class Shape {
protected:
    char* name;
    Point pointA;
    static int objectCount; // Үүссэн объектын тоо

public:
    Shape() : name(nullptr) { objectCount++; }
    virtual void print() {}
    virtual ~Shape() { objectCount--; }

    // Static гишүүн функц
    static int getObjectCount() { return objectCount; }
};

// Статик хувьсагчийг анхны утгатай тодорхойлох
int Shape::objectCount = 0;

// 2 хэмжээст дүрс
class TwoDShape : public Shape {
public:
    float side;

    TwoDShape() : side(0) {}
    TwoDShape(float ax, float ay, float s, const char* shapeName) {
        name = new char[strlen(shapeName) + 1];
        strcpy(name, shapeName);
        side = s;
        pointA = Point(ax, ay);
    }
    virtual ~TwoDShape() { delete[] name; }

    virtual float getPerimeter() = 0;
    virtual float getArea() = 0;
};

// Гурвалжин
class Triangle : public TwoDShape {
private:
    Point pointB, pointC;

public:
    Triangle(float ax, float ay, float s, const char* shapeName) : TwoDShape(ax, ay, s, shapeName) {
        pointB = Point(ax - s / 2, ay + (sqrt(3) * s / 2));
        pointC = Point(ax + s / 2, ay + (sqrt(3) * s / 2));
    }

    float getPerimeter() override { return 3 * this->side; }
    float getArea() override { return sqrt(3) * this->side * this->side / 4; }

    void print() override {
        cout << this->name << " (Triangle) details:" << endl
             << "Point A: (" << this->pointA.getX() << ", " << this->pointA.getY() << ")" << endl
             << "Point B: (" << this->pointB.getX() << ", " << this->pointB.getY() << ")" << endl
             << "Point C: (" << this->pointC.getX() << ", " << this->pointC.getY() << ")" << endl
             << "Perimeter: " << this->getPerimeter() << ", Area: " << this->getArea() << endl;
    }
};

// Квадрат
class Square : public TwoDShape {
private:
    Point vertex_B, vertex_C, vertex_D;

public:
    Square(float ax, float ay, float s, const char* shapeName) : TwoDShape(ax, ay, s, shapeName) {
        vertex_B = Point(ax + this->side, ay);
        vertex_C = Point(ax + this->side, ay + this->side);
        vertex_D = Point(ax, ay + this->side);
    }

    float getPerimeter() override { return 4 * this->side; }
    float getArea() override { return this->side * this->side; }

    void print() override {
        cout << this->name << " (Square) details:" << endl
             << "Point A: (" << this->pointA.getX() << ", " << this->pointA.getY() << ")" << endl
             << "Point B: (" << this->vertex_B.getX() << ", " << this->vertex_B.getY() << ")" << endl
             << "Point C: (" << this->vertex_C.getX() << ", " << this->vertex_C.getY() << ")" << endl
             << "Point D: (" << this->vertex_D.getX() << ", " << this->vertex_D.getY() << ")" << endl
             << "Perimeter: " << this->getPerimeter() << ", Area: " << this->getArea() << endl;
    }
};

// Тойрог
class Circle : public TwoDShape {
public:
    Circle(float cx, float cy, float r, const char* shapeName) : TwoDShape(cx, cy, r, shapeName) {}

    float getPerimeter() override { return 2 * M_PI * this->side; }
    float getArea() override { return M_PI * this->side * this->side; }

    void print() override {
        cout << this->name << " (Circle) details:" << endl
             << "Center: (" << this->pointA.getX() << ", " << this->pointA.getY() << ")" << endl
             << "Radius: " << this->side << endl
             << "Perimeter: " << this->getPerimeter() << ", Area: " << this->getArea() << endl;
    }
};

// Эрэмбэлэх бизнес класс
class TwoDBusiness {
public:
    static void areaSort(TwoDShape** shapes, int count) {
        for (int i = 1; i < count; i++) {
            TwoDShape* temp = shapes[i];
            int j = i - 1;
            while (j >= 0 && temp->getArea() < shapes[j]->getArea()) {
                shapes[j + 1] = shapes[j];
                j--;
            }
            shapes[j + 1] = temp;
        }
    }
};

int main() {
    const int randomAmount = 10;
    srand(time(NULL));

    char** name = new char* [randomAmount];
    for (int i = 0; i < randomAmount; i++) {
        name[i] = new char[11];
        int count = rand() % 10 + 1;
        for (int j = 0; j < count; j++) {
            name[i][j] = 'a' + rand() % 26;
        }
        name[i][count] = '\0';
    }

    TwoDShape** shapes = new TwoDShape* [randomAmount];

    for (int i = 0; i < randomAmount; i++) {
        int id = rand() % 3 + 1;
        int x = rand() % 21 - 10;
        int y = rand() % 21 - 10;
        int side = rand() % 5 + 3;

        switch (id) {
        case 1:
            shapes[i] = new Triangle(x, y, side, name[i]);
            break;
        case 2:
            shapes[i] = new Square(x, y, side, name[i]);
            break;
        case 3:
            shapes[i] = new Circle(x, y, side, name[i]);
            break;
        }
    }

    cout << "Total shapes created: " << Shape::getObjectCount() << endl << endl;

    // Эрэмбэлэх
    TwoDBusiness::areaSort(shapes, randomAmount);

    // Эрэмбэлэгдсэн мэдээллийг хэвлэх
    for (int i = 0; i < randomAmount; i++) {
        cout << "Area: " << shapes[i]->getArea() << endl;
        shapes[i]->print();
        cout << endl;
    }

    // Объект устгах
    for (int i = 0; i < randomAmount; i++)
        delete shapes[i];

    delete[] shapes;
    for (int i = 0; i < randomAmount; i++)
        delete[] name[i];
    delete[] name;

    cout << "Total shapes after deletion: " << Shape::getObjectCount() << endl;

    return 0;
}
