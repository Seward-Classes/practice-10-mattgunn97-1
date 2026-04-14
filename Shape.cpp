#include "Shape.h"
#include <cmath>

void Shape::display() const {
    std::cout << "Shape\n";
}

Rectangle::Rectangle(double width, double height) : w_width(width), h_height(height) {

}

double Rectangle::getArea() const {
    return w_width * h_height;
}

void Rectangle::display() const {
    std::cout << "Rectangle (" << w_width << " x " << h_height << ")\n";
}

Circle::Circle(double radius) : r_radius(radius) {

}

double Circle::getArea() const {
    return M_PI * r_radius * r_radius;
}

void Circle::display() const {
    std::cout << "Circle (radius: " << r_radius << ")\n";
}