#include <iostream>
#include <string>
#include "API.h"
#include "mouse.h"

#include <set>
#include <utility>

using namespace std;

set<pair<int,int>>lookup;
set<pair<int,int>> destination;

void add(Mouse);
bool destiny(Mouse);
bool find(Mouse);

void dfs(Mouse);

void log(const std::string& text) {
    std::cerr << text << std::endl;
}

int main(int argc, char* argv[]) {
    destination.insert(make_pair(8-1,8-1));
    destination.insert(make_pair(9-1,8-1));
    destination.insert(make_pair(9-1,8-1));
    destination.insert(make_pair(9-1,9-1));
    log("Running...");
    API::setColor(0, 0, 'G');
    API::setText(0, 0, "abc");
    Mouse mouse = Mouse();
    dfs(mouse);
    return 0;
}

void dfs(Mouse mouse){
    if(find(mouse)){
        return;
    }
    add(mouse);
    if (destiny(mouse)){
       exit(0);
    }
    if(!API::wallFront()){
        mouse.moveFwd(1);
        dfs(mouse);
        mouse.moveBack(1);
    }
    if(!API::wallLeft()){
        mouse.turnLeft();
        mouse.moveFwd(1);
        dfs(mouse);
        mouse.moveBack(1);
        mouse.turnRight();
    }
    if(!API::wallRight()){
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