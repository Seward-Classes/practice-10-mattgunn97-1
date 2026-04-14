#pragma once
#include <iostream>

class Shape {
public:
    virtual double getArea() const = 0;
    virtual void display() const;
    virtual ~Shape() = default;
}