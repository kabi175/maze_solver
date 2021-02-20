#include <iostream>
#include <string>
#include <set>
#include <utility>

#include "API.h"
#include "mouse.h"

#define log std::cerr

using namespace std;

set<pair<int,int>>lookup;
set<pair<int,int>> destination;

void dfs(Mouse);
void add(Mouse);
bool destiny(Mouse);
bool find(Mouse);
bool canMove(int,int);

void init(){
    int c = API::mazeWidth()/2 -1;
    int r = API::mazeHeight()/2 -1;
    destination.insert(make_pair(c,r));
    destination.insert(make_pair(r,c));
    destination.insert(make_pair(r,r));
    destination.insert(make_pair(c,c));

    API::setColor(0, 0, 'G');
    API::setText(0, 0, "start");
}

int main(int argc, char* argv[]) {
    init();
    log << "Running..."; 
    Mouse mouse = Mouse();
    dfs(mouse);
    return 0;
}

void dfs(Mouse mouse){
    int x,y;
    
    if(find(mouse)){
        return;
    }
    
    add(mouse);
    
    if (destiny(mouse)){
       exit(0);
    }
    
    mouse.front(x,y); 
    if(!API::wallFront() && canMove(x,y)){
        mouse.moveFwd(1);
        dfs(mouse);
        mouse.moveBack(1);
    }
    
    mouse.left(x,y);
    if(!API::wallLeft() && canMove(x,y)){
        mouse.turnLeft();
        mouse.moveFwd(1);
        dfs(mouse);
        mouse.moveBack(1);
        mouse.turnRight();
    }
    
    mouse.right(x,y);
    if(!API::wallRight() && canMove(x,y)){
        mouse.turnRight();
        mouse.moveFwd(1);
        dfs(mouse);
        mouse.moveBack(1);
        mouse.turnLeft();
    }
    
    return;
}

bool destiny(Mouse mouse){
    int x,y;
    mouse.points(x,y);
    auto iter = destination.find(make_pair(x,y));
    if (iter != destination.end()){
        return true;
    }
    return false;

}

void add(Mouse mouse){
    int x,y;
    mouse.points(x,y);
    lookup.insert(make_pair(x,y));
}

bool find(Mouse mouse){
    int x,y;
    mouse.points(x,y);
    auto iter = lookup.find(make_pair(x,y));
    if (iter != lookup.end()){
        return true;
    }
    return false;
}

bool canMove(int x,int y){
    auto iter = lookup.find(make_pair(x,y));
    if (iter == lookup.end()){
        return true;
    }
    return false;
}