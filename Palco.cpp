#include "Palco.hpp"

Palco::Palco(std::string nome) : nome{nome} {}

Palco::Palco(std::string nome, std::list<Apresentacao*> apresentacoes)
    : nome{nome}, apresentacoes{apresentacoes} {}

Palco::~Palco(){
    std::list<Apresentacao*>::iterator it;
    for (it = this->apresentacoes.begin(); it != this->apresentacoes.end(); ++it) 
        delete *it;
}

void Palco::setNome(const std::string nome) { this->nome = nome; }

std::string Palco::getNome() const { return this->nome; }

void Palco::addApresentacao(Apresentacao* const apresentacao) {
    this->apresentacoes.push_back(apresentacao);
}

void Palco::removeApresentacao(std::string& nomeArtista) {
    std::list<Apresentacao*>::iterator it{this->apresentacoes.begin()};
    for (; it != this->apresentacoes.end(); ++it)
        if ((*it)->getArtista()->getNome() == nomeArtista) break;

    if (it != this->apresentacoes.end()) {
        Apresentacao* ptr{*it};
        this->apresentacoes.erase(it);
        delete ptr;
    }
}

const std::list<Apresentacao*>& Palco::getApresentacoes() const {
    return this->apresentacoes;
}