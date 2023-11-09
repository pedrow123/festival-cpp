#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <cstdint>
#include <string>


class Pessoa {
   public:
    Pessoa();
    Pessoa(const std::string nome);
    Pessoa(const std::string nome, unsigned short idade);


    // uint64_t getCpf() const;
    // void setCpf(const uint64_t novoCpf);

    std::string getNome() const;
    void setNome(const std::string& novoNome);

    unsigned short int getIdade() const;
    void setIdade(const unsigned short novaIdade);

   private:
    // bool validarCPF(uint64_t cpfTeste) const;

    std::string nome;
    // uint64_t cpf;
    uint8_t idade;
};
#endif