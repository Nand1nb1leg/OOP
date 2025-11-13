
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


