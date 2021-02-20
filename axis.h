enum Direction {north,east,south,west};

class Axis{
    private:
        int x,y;
    public:
        Axis():x(0),y(0){};
        Axis(int x_,int y_):x(x_),y(y_){};
        void points(int& x, int& y);
        Axis front(Direction,int);
        Axis right(Direction,int);
        Axis back(Direction,int);
        Axis left(Direction,int);
};