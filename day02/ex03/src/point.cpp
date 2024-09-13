#include "point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float x1, const float y1) : x(x1), y(y1) {}

Point::Point(const Point& other) {
    x = other.getXValue();
    y = other.getYValue();
}

Point& Point::operator=(const Point& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

Point::~Point() {}

Fixed Point::getXValue() const {
    return x;
}

Fixed Point::getYValue() const {
    return y;
}
