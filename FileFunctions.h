// Funções para manipulação do arquivo de entrada
#include <fstream>
#include <vector>
#include <libcryptosec/ByteArray.h>
#include <libcryptosec/MessageDigest.h>

// Converte um arquivo para um ByteArray
ByteArray fileToByteArray(const std::string &filename);

// Aplica o algoritmo SHA-256 a um ByteArray
ByteArray applySHA256ToByteArray(ByteArray &data);
