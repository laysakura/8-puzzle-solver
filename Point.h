#pragma once

class Point {
    friend class Puzzle;

private:
    int x, y;

public:
    Point(int x, int y);

    bool operator==(const Point& rhs) const;
    bool operator!=(const Point& rhs) const;
};
