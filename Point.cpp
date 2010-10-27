#include "Point.h"

Point::Point(int x, int y)
    : x(x), y(y)
{
}

bool Point::operator==(const Point& rhs) const
{
    return (x == rhs.x && y == rhs.y);
}
bool Point::operator!=(const Point& rhs) const
{
    return (x != rhs.x || y != rhs.y);
}

