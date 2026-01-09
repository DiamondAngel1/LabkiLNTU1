#include <iostream>
#include <string>
#include <cmath>
#include <windows.h>
using namespace std;

class Shape {
private:
    string name;
    string color;

public:
    Shape(string n, string c) : name(n), color(c) {}

    string getName() const {
        return name; 
    }
    void setName(const string& n) {
        name = n; 
    }

    string getColor() const {
        return color; 
    }
    void setColor(const string& c) {
        color = c;
    }

    virtual double area() const {
        return 0.0; 
    }

    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(string n, string c, double r) : Shape(n, c), radius(r) {}

    double area() const override {
		const double pi = 3.141592653589793;
        return pi * (radius * radius);
    }
};

class Square : public Shape {
private:
    double side;

public:
    Square(string n, string c, double s) : Shape(n, c), side(s) {}

    double area() const override {
        return side * side;
    }
};

class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(string n, string c, double b, double h) : Shape(n, c), base(b), height(h) {}

    double area() const override {
        return 0.5 * base * height;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Circle circle("Коло", "Фіолетове", 5);
    Square square("Квадрат", "Зелений", 5);
    Triangle triangle("Трикутник", "Бордовий", 6, 5);

    cout << circle.getName() << " (" << circle.getColor() << ") має площу: " << circle.area() << endl;
    cout << square.getName() << " (" << square.getColor() << ") має площу: " << square.area() << endl;
    cout << triangle.getName() << " (" << triangle.getColor() << ") має площу: " << triangle.area() << endl;

    return 0;
}
