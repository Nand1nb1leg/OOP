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

