#include <iostream>
#include <vector>

class Point {
public:
    int x, y;

    Point(int x_value, int y_value) {
        x = x_value;
        y = y_value;
    }
};

class Line {
public:
    Point p1, p2;

    Line(Point point1, Point point2) {
        p1 = point1;
        p2 = point2;
    }
};

class Polygon {
protected:
    std::vector<Line> lines;
public:
    Polygon(std::vector<Line> lines_vec) {
        lines = lines_vec;
    }
};

class Triangle : public Polygon {
public:
    Triangle(Point p1, Point p2, Point p3) : Polygon({Line(p1, p2), Line(p2, p3), Line(p3, p1)}) {}
};

class Trapezoid : public Polygon {
public:
    Trapezoid(Point p1, Point p2, int height) : Polygon({Line(p1, p2), 
                                                         Line(p2, Point(p2.x + height, p2.y)),
                                                         Line(Point(p1.x + height, p1.y),
                                                              Point(p2.x + height, p2.y)),
                                                         Line(Point(p1.x + height, p1.y),
                                                              p1)}) {}
};

class Square : public Trapezoid {
public:
    Square(Point p1, int side_length) : Trapezoid(p1, Point(p1.x + side_length, p1.y), side_length) {}
};

int main() {
    std::vector<Polygon*> shapes;
    Point p1(0, 0), p2(2, 2), p3(3, 5), p4(5, 5);
    Line l1(p1, p2), l2(p2, p3), l3(p3, p1), l4(p2, p4), l5(p3, p4);
    Triangle t(p1, p2, p3);
    Trapezoid tr(p1, p2, 2);
    Square s(p2, 2);
    
    shapes.push_back(&t);
    shapes.push_back(&tr);
    shapes.push_back(&s);
    
    for (Polygon* shape : shapes) {
        std::cout << "Coordinates of
