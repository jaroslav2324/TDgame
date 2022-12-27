
#include "fstream"
#include "iostream"

#include "settings.h"
#include "Coords.h"
#include "Vector.h"

using std::ostream;
using std::istream; 
using std::cout;
using std::endl;

struct Line{

    Line(): p1(0, 0), p2(0, 0), guidingVector(0, 0){};
    Line(Point& p1, Point& p2): p1(p1), p2(p2), guidingVector(p2.x - p1.x, p2.y - p1.y){};
    // TODO add constructor with guiding vector and point

    Point p1;
    Point p2;

    Vector guidingVector;

    double findX(double y);
    double findY(double x);

    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    void saveToBinaryFile(ostream& outpustStream);
    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    void loadFromBinaryFile(istream& inputStream);

    Line& operator()(Point& p1, Point& p2);
};

Line getPerpendicularLine(Line& line);
