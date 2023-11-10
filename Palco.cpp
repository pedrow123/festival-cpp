#include "Palco.hpp"

Palco::Palco(std::string nome) : nome{nome} {}
Palco::Palco(std::string nome, std::list<Apresentacao*> apresentacoes)
    : nome{nome}, apresentacoes{apresentacoes} {}

void Palco::setNome(const std::string nome) { this->nome = nome; }

std::string Palco::getNome() const { return this->nome; }

void Palco::addApresentacao(Apresentacao* const apresentacao) {
    getApresentacoes().push_back(apresentacao);
}

void Palco::removeApresentacao(std::string& nomeArtista) {
    std::list<Apresentacao*>::iterator it{getApresentacoes().begin()};
    for (; it != getApresentacoes().end(); ++it)
        if ((*it)->getArtista()->getNome() == nomeArtista) break;

    if (it != getApresentacoes().end()) {
        Apresentacao* ptr{*it};
        getApresentacoes().erase(it);
        delete ptr;
    }
}

std::list<Apresentacao*> Palco::getApresentacoes() const {
    return this->apresentacoes;
}