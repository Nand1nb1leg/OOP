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

