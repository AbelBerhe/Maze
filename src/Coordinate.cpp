//
// Created by abelg on 2023-02-14.
//

#include <ostream>
#include <iostream>
#include "Coordinate.h"

std::ostream& operator<<(std::ostream &output, Coordinate& c) {
    std::cout<<"x: "<<c.x<<", ";
    std::cout<<"y: " <<c.y<<std::endl;
    return output;
}