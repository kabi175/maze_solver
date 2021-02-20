#include <iostream>
#include <string>
#include <set>
#include <utility>

#include "API.h"
#include "controller.h"

using namespace std;

void log(const std::string& text);

void shutDown();

void dfs(Controller);

int main(int argc, char* argv[]) {
    API::setColor(0, 0, 'G');
    API::setText(0, 0, "start");
    log("Running...");
    Controller controller = Controller();
    dfs(controller);
    return 0;
}

void dfs(Controller controller){
    
    controller.add();

    if (controller.isEnd()){
       exit(0);
    }
    if (controller.canMove(Move::Cur)){
       return;
    }


    if(!API::wallLeft() && controller.canMove(Move::Left)){
        controller.mouse.turnLeft();
        controller.mouse.moveFwd(1);
        dfs(controller);
        controller.mouse.moveBack(1);
        controller.mouse.turnRight();
    }
    if(!API::wallFront() && controller.canMove(Move::Fwd)){
        controller.mouse.moveFwd(1);
        dfs(controller);
        controller.mouse.moveBack(1);
    }
    if(!API::wallRight() && controller.canMove(Move::Right)){
        controller.mouse.turnRight();
        controller.mouse.moveFwd(1);
        dfs(controller);
        controller.mouse.moveBack(1);
        controller.mouse.turnLeft();
    }
    controller.add();
    return;
}

void log(const std::string& text) {
    std::cerr << text << std::endl;
}

void shutDown(){
    exit(1);
}