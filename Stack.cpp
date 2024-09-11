// Implementation of the Stack class
// Author: Mary Elaine Califf
// Created: 08/09/2024

#include "Stack.h"
#include <stdexcept>

//#############DaShawn wrote this##########//
//Our push mehtod is taking a char representing the operation, an integer representing the operand, 
//and an integer representing the previousAccumulatorValue before the operation is done.
void Stack::push(char operation, int operand, int previousAccumulatorValue)
{
    //Creates an OperationData representing a node and initializes the data that is passed.
    OperationData newLayerData = OperationData();
    newLayerData.operation=operation;
    newLayerData.operand=operand;
    newLayerData.previousAccumulatorValue=previousAccumulatorValue;
    Node *newLayer = new Node();
    newLayer->data=newLayerData;
    //If the head is a nullptr then there is nothing in the stack.
    if(this->head == nullptr)
    {
        //Since it is empty newLayer is the first node so there is nothing to point to so it becomes the head.
        newLayer->next = nullptr;
        this->head = newLayer;
    }
    //The stack is not empty.
    else
    {
    //Since it is not empty we have to point the new node to what the head currently is and reassign head as newLayer.
    newLayer->next=(this->head);
    (this->head)=newLayer;
    }
    //We have no need for our temporary pointer anymore so we set it to nullptr and delete it.
    newLayer = nullptr;
    delete newLayer;
}

//#############Zach wrote this############//
//This function will return a OperationData Pointer from the top of the stack.
Node* Stack::pop()
{
    //if the head is not empty, we have data in the stack
    if (head != nullptr)
    {
        //Create a temporary pointer that we will return to the CalculatorApp.cpp and delete there
        //Assign this temp pointer to head and set head as the next of our temp pointer
        Node* newPointer = head;
        head = newPointer->next;
        //set newPointer's next value to nullptr so we isolate the first node of the stack and return it
        newPointer->next = nullptr;
        return newPointer;
    }
    //the stack is empty so throw an error
    else
    {
        throw std::length_error("Stack is empty");
    }
}
//top returns head
OperationData Stack::top() const
{
    //If there is a head return a head.
    if (head != nullptr)
    {
        //Dereferencing here to return the actual object.
        return head->data;
    }
    //There is no head so throw an error.
    else
    {
        throw std::length_error("Stack is empty");
    }
}

//Returns boolean
bool Stack::isEmpty() const
{
    //Compares head if head is a nullptr it returns true is not this returns false.
    return head == nullptr;
}

//This function will clear all data in the stack
void Stack::clear()
{
    //create a temporaty pointer so we don't lose the linked list and leak memory
    Node* temp;
    //while the head isn't empty, meaning the stack has data in it
    while(head!=nullptr)
    {
        //move temp to head's next, this can either be another node or nullptr
        temp = head->next;
        //delete the data head is pointing to
        delete head;
        //set head to temp, this can either be another node causing the loop over again or nullptr ending the loop
        head = temp;
    }
    //delete our pointers
    delete head;
}
//deconstructor calls clear deleting stack
Stack::~Stack(){
    clear();
}




