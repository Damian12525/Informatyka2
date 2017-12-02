#include <iostream>
#include <vector>
#include <memory>
#include <typeinfo>
#include <cstring>

const double PI = 3.14159265358;


enum class ShapeType {
    CIRCLE, SQUARE
};

class Shape {
protected:
    ShapeType _shapeType;

public:
    ShapeType getType() const {
        return _shapeType;
    }

    virtual double calculateArea() const =0;
};

class Circle: public Shape {
private:
    double _radius;

public:
    Circle(double radius) {
        _shapeType = ShapeType::CIRCLE;
        _radius = radius;
    }

    double getRadius() const {
        return _radius;
    }

    double calculateArea() const {
        return PI * _radius * _radius;
    }
};

class Square: public Shape {
private:
    double _side;

public:
    Square(double side) {
        _shapeType = ShapeType::SQUARE;
        _side = side;
    }

    double getSide() const {
        return _side;
    }

    double calculateArea() const {
        return _side * _side;
    }
};


class AreaCalculator { //jeśli coś działa - nie ruszaj
public:
    static double calculateArea_new(const std::vector<const Shape*>& shapes) {
        double area = 0;
        for (const auto shape_ptr : shapes) {
                area += shape_ptr->calculateArea();
        }

        return area;
    }
};



int main() {
    std::vector<std::unique_ptr<Shape>> v;
    v.push_back(std::make_unique<Circle>(1.0));
    v.push_back(std::make_unique<Square>(1.0));

    std::vector<const Shape*> v_raw;
    for (const auto& ptr : v) {
        v_raw.push_back(ptr.get());
    }

    std::cout << "total area = " << AreaCalculator::calculateArea_new(v_raw) << std::endl;

    return 0;
}

