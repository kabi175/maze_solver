#include "axis.h"

class Mouse{
    public:
        Axis axis;
        Direction dir;
        Mouse():axis(Axis()),dir(north){}
        void update(Axis);
        void points(int&,int&);
        void moveFwd(int);
        void moveBack(int);
        void turnLeft();
        void turnRight();
        void turnBack();
};