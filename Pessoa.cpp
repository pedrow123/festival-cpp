#include "Pessoa.hpp"

namespace festnow {
Pessoa::Pessoa(const std::string nome)
    : nome{nome} {}

Pessoa::Pessoa(const std::string nome,
               const unsigned short idade)
    : Pessoa{nome} {
    this->setIdade(idade);
}

std::string Pessoa::getNome() const { return this->nome; }

void Pessoa::setNome(const std::string& nome) { this->nome = nome; }

unsigned short int Pessoa::getIdade() const {
    return this->idade;
}

void Pessoa::setIdade(const unsigned short novaIdade) {
    this->idade = novaIdade;
}
}