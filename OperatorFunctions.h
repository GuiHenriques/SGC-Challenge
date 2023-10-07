#include <iostream>
#include <vector>
#include "Operator.h"

bool verifySignatures(const std::vector<Operator> &operators, int numberOfOperators, ByteArray &documentHash);

void printSignatures(const std::vector<Operator> &operators);

int getNumberOfOperators();

int getNumberOfOperator(int numberOfOperators);

int getInteger(std::string message);
