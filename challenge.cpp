#include "FileFunctions.h"
#include "OperatorFunctions.h"

int menuOptions();

int main(int argc, char *argv[])
{
	std::cout << "Iniciando Protocolo de Assinaturas Múltiplas" << std::endl;
	
	// get the PDF file name
	if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " path_to_pdf.pdf" << std::endl;
        return 1;
    }
	const char *pdfFileName = argv[1];
	
	// convert the PDF file to a ByteArray
	ByteArray documentByteArray = fileToByteArray(pdfFileName);

	// generate the hash of the document
	ByteArray documentHash = applySHA256ToByteArray(documentByteArray);

	// get the number of operators
	int numberOfOperators = getNumberOfOperators();

	// inicialize the operators array
	std::vector<Operator> operators;
	for (long i = 0; i < numberOfOperators; i++)
	{
		operators.push_back(Operator(i));
	}
	
	// main loop
	while (true)
	{
		int option = menuOptions();

		switch (option)
		{
			// sign document
			case 1:
			{
				int numberOfOperator = getNumberOfOperator(numberOfOperators);
				
				ByteArray signature = operators[numberOfOperator - 1].sign(documentHash);
				
				std::cout << "Operador " << numberOfOperator << " assinou o documento" << std::endl << std::endl;
				break;
			}

			// verify signatures
			case 2:
			{
				verifySignatures(operators, numberOfOperators, documentHash);
				break;
			}
			
			// close system
			case 3:
				return 0;
			
			default:
				std::cout << "Opção invalida" << std::endl;
				break;
		}
	}
}

int menuOptions()
{
	std::cout << "1 - Assinar Documento Digital" << std::endl;
	std::cout << "2 - Verificar Acordo" << std::endl;
	std::cout << "3 - Fechar Sistema" << std::endl << std::endl;
	int option;

	while (true)
	{

		option = getInteger("Digite a opção desejada: ");

		if (option <= 0 || option > 4)
		{
			std::cout << "Opção invalida" << std::endl;
			continue;
		}

		return option;
	}
}