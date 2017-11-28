#include <iostream>
#include <vector>
#include <memory>
#include <typeinfo>
#include <cstring>
 
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
};
 
const double PI = 3.14159265358;
 
class AreaCalculator {
  private:
    static double calculateSquareArea(const Square& square) {
      return square.getSide() * square.getSide();
    }
 
    static double calculateCircleArea(const Circle& circle) {
      return PI * circle.getRadius() * circle.getRadius();
    }
 
  public:
    static double calculateArea(const std::vector<const Shape*>& shapes) {
      double area = 0;
      for (const auto shape_ptr : shapes) {
        if (shape_ptr->getType() == ShapeType::SQUARE) {
          area += calculateSquareArea(static_cast<const Square&>(*shape_ptr));
        } else if (shape_ptr->getType() == ShapeType::CIRCLE) {
          area += calculateCircleArea(static_cast<const Circle&>(*shape_ptr));
        }
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
 
  std::cout << "total area = " << AreaCalculator::calculateArea(v_raw) << std::endl;
 
  return 0;
}
