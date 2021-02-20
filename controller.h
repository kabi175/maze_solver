#include<set>

#include "mouse.h"
#include "API.h"

enum Move{Fwd,Left,Right,Cur};

class Controller{
    private:
        std::set<std::pair<int,int>> visited;
        std::set<std::pair<int,int>> destination;
    public:  
        Mouse mouse;
        Controller(){
            visited.insert(std::make_pair(-1,-1));
            int r = (API::mazeWidth()/2)-1,c = (API::mazeWidth()/2)-1;
            destination.insert(std::make_pair(r,c));
            destination.insert(std::make_pair(r,r));
            destination.insert(std::make_pair(c,c));
            destination.insert(std::make_pair(c,r));
            mouse = Mouse();
        };

        void add();
        void remove();
        bool canMove(Move);
        bool isEnd();

};