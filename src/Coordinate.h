//
// Created by abelg on 2023-02-14.
//

#ifndef ASSIGNMENT_2_COORDINATE_H
#define ASSIGNMENT_2_COORDINATE_H

struct Coordinate {
    int x = 0;
    int y = 0;

    friend std::ostream &operator<<(std::ostream &output, Coordinate &student);
};

#endif //ASSIGNMENT_2_COORDINATE_H
