//
// Created by abelg on 2023-02-14.
//

#include "Stack.h"
#include <iostream>

//add coordinates to the stack
void Stack::push(Coordinate coordinate) {
    auto node = new Node();
    node->coordinate = coordinate;
    //add the first node
    node->m_next = m_first;
    m_first = node;
}

//remove coordinates to the stack
void Stack::pop() {
    auto node = m_first;
    m_first = m_first ? m_first->m_next : nullptr;
    delete node;
}

std::ostream &operator<<(std::ostream &output, Stack stack) {
    auto node = stack.m_first;
    while (node != nullptr) {
        std::cout << "x: " << node->coordinate.x << ", ";
        std::cout << "y: " << node->coordinate.y << std::endl;
        node = node->m_next;
    }
    return output;
}

Coordinate Stack::peek() {
    return m_first ? m_first->coordinate : Coordinate({-1, -1});
}

//vector to store the x coordinates
std::vector<int> Stack::xCoordinates() {
    std::vector<int> numList;
    auto node = m_first;
    while (node != nullptr) {
        numList.push_back(node->coordinate.x);
        node = node->m_next;
    }
    return numList;
}

//vector to store the y coordinates
std::vector<int> Stack::yCoordinates() {
    std::vector<int> numList;
    auto node = m_first;
    while (node != nullptr) {
        numList.push_back(node->coordinate.y);
        node = node->m_next;
    }
    return numList;
}

