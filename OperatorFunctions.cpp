#include "OperatorFunctions.h"


bool verifySignatures(const std::vector<Operator> &operators, int numberOfOperators, ByteArray &documentHash)
{
    for (int i = 0; i < numberOfOperators; i++)
    {
        Operator op = operators[i];

        if (!op.verify(documentHash))
        {
            std::cout << "Ainda não foi possivel entrar em um acordo" << std::endl << std::endl;
            return false;
        }
    }
    std::cout << std::endl << "Todos os operadores assinaram o documento!" << std::endl << std::endl;
    printSignatures(operators);
    return true;
}

void printSignatures(const std::vector<Operator> &operators)
{
    int count = 1;
    for (Operator op : operators)
    {
        std::cout << "Assinatura do operador " << count++ << ": " << std::endl;
        std::cout << op.getSignature().toHex() << std::endl << std::endl;
    }
}

int getNumberOfOperators()
{
    int numberOfOperators = getInteger("Numero de operadores: ");

    return numberOfOperators;
}

int getNumberOfOperator(int numberOfOperators)
{
    int numberOfOperator;

    while (true)
    {
        numberOfOperator = getInteger("Numero do operador: ");

        if (numberOfOperator <= 0 || numberOfOperator > numberOfOperators)
        {
            std::cout << "Operador invalido" << std::endl;
        }
        else
        {
            break;
        }
    }

    return numberOfOperator;
}

int getInteger(std::string message)
{
    std::string input;
    int number;

    while (true)
    {
        std::cout << message;
        std::cin >> input;

        if (input.empty())
        {
            std::cout << "Entrada invalida" << std::endl;
            continue;
        }

        bool isValid = true;
        for (char c : input)
        {
            if (!isdigit(c))
            {
                std::cout << "Entrada invalida" << std::endl;
                isValid = false;
                break; // break from the for-loop, not the while-loop
            }
        }

        if (!isValid)
        {
            continue;
        }

        number = std::stoi(input);

        if (number <= 0)
        {
            std::cout << "Numero invalido" << std::endl;
            continue;
        }

        break;
    }

    return number;
}
