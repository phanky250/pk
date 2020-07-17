#ifndef AXISSETTING_H
#define AXISSETTING_H


class AxisSetting {
public:
    AxisSetting();
    double spanX() const {
        return maxX - minX;
    }
    double spanY() const {
        return maxY - minY;
    }
    double minX;
    double maxX;
    int numXTicks;
    double minY;
    double maxY;
    int numYTicks;
};

#endif // AXISSETTING_H
