#include "axis.h"

class Mouse{
    private:
        Axis axis;
        Direction dir;
        void update(Axis);
        void color(char);
    public:
        Mouse():axis(Axis()),dir(north){}
        
        void points(int&,int&);

        void moveFwd(int);
        void moveBack(int);

        void turnLeft();
        void turnRight();
        void turnBack();

        void front(int&,int&);
        void left(int&,int&);
        void right(int&,int&);        
};