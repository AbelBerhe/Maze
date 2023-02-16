//
// Created by abelg on 2023-02-14.
//

#ifndef ASSIGNMENT_2_NODE_H
#define ASSIGNMENT_2_NODE_H

#include "Coordinate.h"

struct Node {
    Coordinate coordinate;
    Node *m_next{nullptr};
};
#endif //ASSIGNMENT_2_NODE_H
