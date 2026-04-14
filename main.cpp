//AI Disclaimer: Moderate AI use.
//Main code was my own, Claude used to ensure proper syntax and to help with any debugging.

/*Submission Checklist

    [X] AI usage disclosure at top of main.cpp
    [X] All files at repository root
    [X] Base Shape class with pure virtual getArea()
    [X] Two derived classes (Rectangle and Circle) with proper area calculations
    [X] Read and parse shapes.txt
    [X] Use std::vector<std::unique_ptr<Shape>> for polymorphism
    [X] Use std::make_unique<Shape>() for all object creation
    [X] Display all shapes and their areas using getArea()
    [X] No manual memory management (no delete)
    [X] Error handling with line numbers for bad file data
    [X] Tested with sample data and bad data
    [X] Compiles and runs without memory leaks
    [X] Committed and pushed to GitHub
*/

/*--------------------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <string>
#include <iomanip>
#include "Shape.h"
#include "Shape.cpp"

/*--------------------------------------------------------------------------------*/

void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) {
    for (const auto& shape : shapes) {
        shape->display();
        std::cout << "Area: " << std::fixed << std::setprecision(4) << shape->getArea() << "\n\n";
        std::cout << std::defaultfloat;
    }
}

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;

    std::ifstream inputFile("shapes.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open shapes.txt\n";
        return 1;
    }

    std::string line;
    int lineNumber{0};

    while (std::getline(inputFile, line)) {
        lineNumber++;
        std::istringstream stream(line);
        std::string shapeType;
        stream >> shapeType;

        if (shapeType == "rectangle") {
            double width{0.0};
            double height{0.0};
            if (!(stream >> width >> height)) {
                std::cerr << "Error on line " << lineNumber << ": invalid rectangle data\n";
                continue;
            }
            shapes.push_back(std::make_unique<Rectangle>(width, height));
        }
        else if (shapeType == "circle") {
            double radius{0.0};
            if (!(stream >> radius)) {
                std::cerr << "Error on line " << lineNumber << ": invalid circle data\n";
                continue;
            }
            shapes.push_back(std::make_unique<Circle>(radius));
        }
        else {
            std::cerr << "Error on line " << lineNumber << ": unknown shape type '" << shapeType << "'\n";
            continue;
        }
    }

    inputFile.close();

    printAllAreas(shapes);
    return 0;
}

