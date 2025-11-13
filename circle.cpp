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

