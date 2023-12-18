#include <iostream>


class Player            //class names have to be unique
{
    public:
        int x, y;
        int speed;

        void Move(int xa, int ya )             //functions inside classes are called methods
        {
            x += xa * speed;
            y += ya * speed;

        }
};



int main()
{
    Player player;
    player.Move(1, -1);

    

}