// A simple array based stack of OperationData records
// Author: Mary Elaine Califf
// Created: 08/09/2024

#pragma once

#include "OperationData.h"

struct Node{
    OperationData data;
    Node *next;

    Node(){}
    Node(OperationData data, Node *next=nullptr): data(data), next(next){};
};

class Stack
{
    
public:
    // default constructor
    Stack(): head(nullptr){
        
    }

    // add an element to the top of the stack
    void push(char operation, int operand, int previousAccumulatorValue);

    // remove an element from the top of the stack
    Node* pop();

    // look at the top of the stack without removing it
    OperationData top() const;

    // is the stack empty?
    bool isEmpty() const;

    // clear the stack
    void clear();


    ~Stack();

private:
    Node *head;
};