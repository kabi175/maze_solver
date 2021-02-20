#include "axis.h"

void Axis::points(int& x_, int& y_){
    x_ = x;
    y_ = y;
}

Axis Axis::front(Direction dir,int step=1){
    int x,y;
    points(x,y);
    if (dir == Direction::north){
        return Axis(x,y+step);
    }else if (dir == Direction::east){
        return Axis(x+step,y);
    }else if (dir == Direction::south){
        return Axis(x,y-step);
    }else{
        return Axis(x-step,y);
    }
}

Axis Axis::right(Direction dir,int step =1){
    int x,y;
    points(x,y);
    if (dir == Direction::north){
        return Axis(x+step,y);
    }else if (dir == Direction::east){
        return Axis(x,y-step);
    }else if (dir == Direction::south){
        return Axis(x-step,y);
    }else{
        return Axis(x,y+step);
    }
}

Axis Axis::back(Direction dir,int step =1){
    int x,y;
    points(x,y);
    if (dir == Direction::north){
        return Axis(x,y-step);
    }else if (dir == Direction::east){
        return Axis(x-step,y);
    }else if (dir == Direction::south){
        return Axis(x,y+step);
    }else{
        return Axis(x+step,y);
    }
}

Axis Axis::left(Direction dir,int step =1){
    int x,y;
    points(x,y);
    if (dir == Direction::north){
        return Axis(x-step,y);
    }else if (dir == Direction::east){
        return Axis(x,y+step);
    }else if (dir == Direction::south){
        return Axis(x+step,y);
    }else{
        return Axis(x,y-step);
    }
}