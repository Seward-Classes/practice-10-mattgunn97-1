#pragma once
#include <iostream>

class Shape {
public:
    virtual double getArea() const = 0;
    virtual void display() const;
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height);
    double getArea() const override;
    void display() const override;

private:
    double w_width;
    double h_height;
};

class Circle : public Shape {
public:
    Circle(double radius);
    double getArea() const override;
    void display() const override;

private:
    double r_radius;
};