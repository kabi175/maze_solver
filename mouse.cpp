#include "API.h"
#include "mouse.h"

void Mouse::update(Axis axis_){
    axis = axis_; 
}

void Mouse::points(int& x_,int& y_){
    axis.points(x_,y_);
}

void Mouse::moveFwd(int step=1){
    API::moveForward(step);
    update(axis.front(dir,step));
    int x,y;
    axis.points(x,y);
    API::setColor(x,y, 'G');
}

void Mouse::moveBack(int step=1){
    int x,y;
    axis.points(x,y);
    API::setColor(x,y, 'R');
    turnBack();
    API::moveForward(step);
    turnBack();
    update(axis.back(dir,step));
}

void Mouse::turnRight(){
    API::turnRight();
    if(dir == Direction::north){
        dir = east;
    }else if(dir == Direction::east){
        dir = south;
    }else if(dir == Direction::south){
        dir = west;
    }else if(dir == Direction::west){
        dir = north;
    }
}

void Mouse::turnLeft(){
    API::turnLeft();
    if(dir == Direction::north){
        dir = west;
    }else if(dir == Direction::east){
        dir = north;
    }else if(dir == Direction::south){
        dir = east;
    }else if(dir == Direction::west){
        dir = south;
    }
}

void Mouse::turnBack(){
    turnRight();
    turnRight();
}