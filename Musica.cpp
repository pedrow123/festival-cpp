#include "Musica.hpp"
#include "Artista.hpp"

Musica::Musica(std::string nome, unsigned short int duracaoSegundos, std::list<Artista*> escritores)
    : nome(nome), duracaoSegundos(duracaoSegundos), escritores(escritores) {}

Musica::Musica(std::string nome, unsigned short int duracaoSegundos)
    : nome(nome), duracaoSegundos(duracaoSegundos) {}

void Musica::setNome(const std::string nome) {
    this->nome = nome;
}

std::string& Musica::getNome() const {
    return const_cast<std::string&>(nome);
}

void Musica::setDuracao(const unsigned short int duracaoSegundos) {
    this->duracaoSegundos = duracaoSegundos;
}

unsigned short int Musica::getDuracao() const {
    return duracaoSegundos;
}

void Musica::addEscritor(Artista* const escritor) {
    escritores.push_back(escritor);
}

Artista& Musica::removeEscritor(std::string& nomeEscritor) {
    std::list<Artista*>::iterator it{getEscritores().begin()};
    for( ; it != getEscritores().end(); ++it)
        if((*it)->getNome() == nomeEscritor)
            break;

    if (it != getEscritores().end()) {
        Artista* ptr{*it};
        getEscritores().erase(it);
        delete ptr;
    }
}

std::list<Artista*> Musica::getEscritores() const {
    return this->escritores;
}