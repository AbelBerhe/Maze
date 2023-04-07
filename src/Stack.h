//
// Created by abelg on 2023-02-14.
//

#ifndef ASSIGNMENT_2_STACK_H
#define ASSIGNMENT_2_STACK_H

#include <ostream>
#include <vector>
#include "Node.h"

class Stack {

private:
    Node *m_first{nullptr};
public:
    void push(Coordinate coordinate);

    void pop();

    friend std::ostream &operator<<(std::ostream &output, Stack stack);

    Coordinate peek();
};

#endif //ASSIGNMENT_2_STACK_H
