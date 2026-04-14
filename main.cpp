//AI Disclaimer:

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

