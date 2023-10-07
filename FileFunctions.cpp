#include "FileFunctions.h"

ByteArray fileToByteArray(const std::string &filename)
{
	// abre o arquivo em modo binário
	std::ifstream file(filename, std::ios::binary | std::ios::ate);

	// verifica se arquivo foi aberto 
	if (!file)
	{
		throw std::runtime_error("Failed to open the file.");
	}

	// tamanho do arquivo
	std::streamsize size = file.tellg();

	// posiciona o cursor no início do arquivo
	file.seekg(0, std::ios::beg);

	// cria um vetor para armazenar o conteúdo do arquivo
	std::vector<char> buffer(size);

	// le o conteúdo do arquivo para um vetor
	if (!file.read(buffer.data(), size))
	{
		throw std::runtime_error("Failed to read the file.");
	}

	// retorna o vetor convertido em ByteArray
	return ByteArray(reinterpret_cast<const unsigned char*>(buffer.data()), size);
}

ByteArray applySHA256ToByteArray(ByteArray &data)
{
	// initialize hash
	MessageDigest md(MessageDigest::Algorithm::SHA256); 

	// upload data
	md.update(data);

	return md.doFinal();
}
