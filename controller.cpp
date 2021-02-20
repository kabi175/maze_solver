#include "controller.h"


void Controller::add(){
    int x,y;
    mouse.points(x,y);
    visited.insert(std::make_pair(x,y));
}

void Controller::remove(){
    int x,y;
    mouse.points(x,y);
    auto iter = visited.find(std::make_pair(x,y));
    if (iter == visited.end()){
        return;
    }
    visited.erase(iter);
}

bool Controller::canMove(Move move){
    int x,y;

    Axis axis;
    if (move == Move::Fwd){
        axis = mouse.axis.front(mouse.dir,1);
    }else if (move == Move::Left){
        axis = mouse.axis.left(mouse.dir,1);
    }else if (move == Move::Right){
        axis = mouse.axis.right(mouse.dir,1);
    }else if(move == Move::Cur){
        axis = mouse.axis;
    }

    axis.points(x,y);
    auto iter = visited.find(std::make_pair(x,y));
    if (iter == visited.end()){
        return true;
    }
    return false;
}


bool Controller::isEnd(){
    int x,y;
    mouse.points(x,y);
    auto iter = destination.find(std::make_pair(x,y));
    if (iter != destination.end()){
        return true;
    }
    return false;
}
