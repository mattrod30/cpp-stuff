#include <iostream>
#include <vector>

class Shape {
public:
    virtual void draw() {   // virtual for polymorphism
        std::cout << "Drawing a Shape" << std::endl;
    }
    virtual ~Shape() {}     // virtual destructor is important
};

class Circle : public Shape {
public:
    void draw() override {  // override the base function
        std::cout << "Drawing a Circle" << std::endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a Rectangle" << std::endl;
    }
};

int main() {
    std::vector<Shape*> shapes;  // vector of base class pointers

    Circle c;
    Rectangle r;

    shapes.push_back(&c);        // store addresses in the vector
    shapes.push_back(&r);

    for (int i = 0; i < shapes.size(); i++) {
        shapes[i]->draw();       // calls the correct draw() function
    }

    return 0;
}
