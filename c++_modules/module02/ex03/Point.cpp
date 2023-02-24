#include "Point.hpp"

//___________Default Constructor____________

Point::Point(): x(0), y(0){
    std::cout << "Point Default Contructor" << std::endl;
}

//____________Constructor________________

Point::Point(const float x, const float y) : x(x), y(y){
     std::cout << "Point Contructor" << std::endl;
}

//____________Copy Constructor_______________

Point::Point(const Point& copy) : x(copy.x), y(copy.y){
     std::cout << "Point Copy Contructor" << std::endl;
}

Point& Point::operator=(const Point& copy){
    if (this != &copy){
        *this = copy;
    }
    return (*this);
}

//____________Get X_______________________

int Point::getX(){
    return this->x.toFloat();
}

//____________Get Y_______________________

int Point::getY(){
    return this->y.toFloat();
}