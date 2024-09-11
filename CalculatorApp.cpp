/*
Group: DaShawn and Zach 
Class: IT 279
Program: Program 1
*/
#include "Calculator.h"
#include <iostream>
#include "Stack.h"

using namespace std;

//Main function where program logic is stored
int main()
{
    //###########DaShawn wrote this#####################//
    //Creates objects for our Calculator and Pointer towards Stack Objects
    Calculator c = Calculator();
    Stack* u = new Stack();
    Stack* r = new Stack();
    //Initalize variables and prints out Welcome messages
    int accumulator = 0;
    int num;
    char i = ' ';
    cout<<"\n Welcome to the Undo-Redo Calculator!\n"<<endl;
    cout<<"   This calculator handles the following commands: \n"<<"\n   +,-,*,/,C,U,R, and Q"<<endl;
    cout<<"   Arithmetic operations are followed by a single positive integer.\n"<<"   C will clear accumulator, U will undo, R will redo, and Q will quit."<<endl;
    cout<<accumulator<<"\n";

    //The only thing to break this program is Quit
    while(i != 'Q')
    {
    cout<<"\n>";
    cin>> i;
    
    //This switch case reads what operation the user picked
    switch (i)
    {
    //plus will add onto the u main stack and increase the accumulator
    case '+':
        cout<<' ';
        cin>>num;
        u->push(i,num,accumulator);
        accumulator = c.add(accumulator,num);
        //If the redo stack is not empty then delete all it's data and make a new one
        if(!r->isEmpty()) delete r, r = new Stack();
        
        break;
    //minus will add onto the stack and decrease the accumulator
    case '-':
        cout<<" ";
        cin>>num;
        u->push(i,num,accumulator);
        accumulator = c.sub(accumulator,num);
        //If the redo stack is not empty then delete all it's data and make a new one
        if(!r->isEmpty()) delete r, r = new Stack();
        break;
    //multiply will add onto the u main stack and multiply the accumulator
    case '*':
        cout<<" ";
        cin>>num;
        u->push(i,num,accumulator);
        accumulator = c.multi(accumulator,num);
        //If the redo stack is not empty then delete all it's data and make a new one
        if(!r->isEmpty()) delete r, r = new Stack();
        break;
    //divide will add onto the u main stack and divide the accumulator
    case '/':
        cout<<" ";
        cin>>num;
        u->push(i,num,accumulator);
        accumulator = c.div(accumulator,num);
        //If the redo stack is not empty then delete all it's data and make a new one
        if(!r->isEmpty()) delete r, r = new Stack();
        break;
    //R will call a redo
    case 'R':
        //Since you can only redo after an Undo we must check if redo is empty
        if(!r->isEmpty())
        {
            //poppedData returns a pointer towards an OperationData object so we recieve it from the r redo stack
            Node* poppedData = r->pop();
            //We then push onto the u main stack filling the parameter fields by unpacking our poppedData
            u->push(poppedData->data.operation,poppedData->data.operand,poppedData->data.previousAccumulatorValue);
            //delete the temporary pointer, poppedData
            delete poppedData;
            cout<<" Redoing: ";
            //from our new layer on the u main stack we must detect what that operation was
            switch(u->top().operation)
            {
                case '+':
                    //In the case of plus we add the previousAccumulator value with our operand
                    accumulator = u->top().previousAccumulatorValue + u->top().operand;
                    cout<<u->top().operation<<u->top().operand<<endl;
                    cout<< accumulator;
                    break;
                case '-':
                    //In the case of minus we subtract the previousAccumulator value with our operand
                    accumulator = u->top().previousAccumulatorValue - u->top().operand;
                    cout<<u->top().operation<<u->top().operand<<endl;
                    cout<< accumulator;
                    break;
                case '*':
                    //In the case of multiply we multiply the previousAccumulator value with our operand
                    accumulator = u->top().previousAccumulatorValue * u->top().operand;
                    cout<<u->top().operation<<u->top().operand<<endl;
                    cout<< accumulator;
                    break;
                case '/':
                    //In the case of divide we divide the previousAccumulator value with our operand
                    accumulator = u->top().previousAccumulatorValue / u->top().operand;
                    cout<<u->top().operation<<u->top().operand<<endl;
                    cout<< accumulator;
                    break;
                case 'C':
                    //In the case of clear. It will always be zero
                    accumulator = 0;
                    cout<<u->top().operation<<endl;
                    cout<< accumulator;
                    break;
                default:
                    break;
            }
            
        }
        else 
        cout<< " Nothing to redo\n"<<accumulator;
        break;
    //################Zach wrote this###############//
    //U will call an undo
    case 'U':
        //If our main U stack is not empty then there are operations we can undo in the main u stack.
        if(!u->isEmpty())
        { 
            //poppedData returns a pointer towards an OperationData object so we recieve it from the u main stack
            Node* poppedData = u->pop();
            //We then push onto the r redo stack filling the parameter fields by unpacking our poppedData
            r->push(poppedData->data.operation,poppedData->data.operand,poppedData->data.previousAccumulatorValue);
            //delete our temporary pointer
            delete poppedData;
            cout<<" Undoing: " ;
            //Since we're undoing an operation the accumulator has to be set back to previousAccumulatorValue
            accumulator = r->top().previousAccumulatorValue;
            //check the operation retrieved
            switch(r->top().operation)
            {   
                //print out what operation and operand was undone
                case '+':
                    cout<<"+ "<<r->top().operand<<endl;
                    cout<<accumulator;
                    break;
                case '-':
                    cout<<"- "<<r->top().operand<<endl;
                    cout<< accumulator;
                    break;
                case '*':
                    cout<<"* "<<r->top().operand<<endl;
                    cout<< accumulator;
                    break;
                case '/':
                    cout<<"/ "<<r->top().operand<<endl;
                    cout<< accumulator;
                    break;
                case 'C':
                    cout<<"C "<<endl;
                    cout<< accumulator;
                    break;
                default:
                    break;
            }
        }
        else
        cout<<"Nothing to undo";
        break;
    //In the case of clear, we push it to the main u stack since a clear can be undone.
    case 'C':
        u->push(i,0,accumulator);
        if(!r->isEmpty()) delete r, r = new Stack();
        //Clear will always result in zero
        accumulator = 0;
        cout<<accumulator;
        
        break;
    case 'Q':
        cout<<"Goodbye"<<endl;
        break;
    
    default:
        break;
    }
}

//delete our two stacks outside the Quit while loop
delete u;
delete r;
}