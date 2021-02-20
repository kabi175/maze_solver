#include "axis.h"

class Mouse{
    private:
        Axis axis;
        Direction dir;
    public:
        Mouse(){
            axis = Axis();
            dir = north;
        }
        void update(Axis);
        void points(int&,int&);
        void moveFwd(int);
        void moveBack(int);
        void turnLeft();
        void turnRight();
        void turnBack();
};