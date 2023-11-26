#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <cstdint>
#include <string>


namespace festnow {
class Pessoa {
   public:
    Pessoa();
    Pessoa(const std::string nome);
    Pessoa(const std::string nome, unsigned short idade);
    virtual ~Pessoa() = default;

    std::string getNome() const;
    void setNome(const std::string& novoNome);

    unsigned short int getIdade() const;
    void setIdade(const unsigned short novaIdade);

   private:
    std::string nome;
    unsigned short int idade;
};
}

#endif