// Data for a calculator operation
// Includes the previous value in order to help support undo
// Author: Mary Elaine Califf
// Created: 08/09/2024

#pragma once

struct OperationData
{
    char operation;
    int operand;
    int previousAccumulatorValue;

    OperationData(char operation = 'C', int operand = 0, int previousAccumulatorValue = 0): operation(operation), operand(operand), previousAccumulatorValue(previousAccumulatorValue) {};

    bool operator==(const OperationData& other) const
    {
        return (this->operation == other.operation) && (this->operand == other.operand) && (this->previousAccumulatorValue == other.previousAccumulatorValue);
    }
};
