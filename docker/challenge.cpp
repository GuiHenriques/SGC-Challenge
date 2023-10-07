#include <iostream>

using std::cout;
using std::endl;


class Operator {
    private:
        int key = 0;
    public:
        void sign() {
            std::cout << "Assinatura Registrada" << std::endl;
        }

        bool verify() {
            return true;
        }
        
        int getKey() {
            return key;
        }
};

void menu() {
    std::cout << "1 - Assinar" << std::endl;
    std::cout << "2 - Verificar" << std::endl;
    std::cout << "3 - Fechar Sistema" << std::endl;
    std::cout << "4 - Fazer nova Simulação" << std::endl;
}

int main()
{
    int numeroDeOperadores;
    std::cout << "Digite o numero de operadores: ";
    std::cin >> numeroDeOperadores;

    Operator operadores[numeroDeOperadores];

    while (true)
    {
        menu();
        int opcao;
        std::cout << "Digite a opcao desejada: ";
        std::cin >> opcao;

        switch (opcao)
        {
            // Assinar
            case 1:
                int numeroDoOperador;
                std::cout << "Digite o número do operador: ";
                std::cin >> numeroDoOperador;
                operadores[numeroDoOperador-1].sign();
                break;
            
            // Verificar
            case 2:
                for (Operator operador : operadores)
                {
                    cout << operador.getKey();
                    cout << endl;
                    if (operador.verify())
                        continue;
                    else {
                        std::cout << "Assinatura inválida" << std::endl;
                        break;
                    }
                }
                break;
            
            // quit
            case 3:
                std::cout << "Sistema encerrado" << std::endl;
                return 0;
            
            case 4:
                // limpar array de operadores
                // limpar jsons
                // call menu
                break;

         }

    }
}

