#include "Artista.hpp"

Artista::Artista(std::string nome, unsigned short int idade)
    : Pessoa{nome, idade}, tipoMusical{"Indefinido"} {}

Artista::Artista(std::string nome, unsigned short int idade, std::string tipoMusical)
    : Pessoa{nome, idade}, tipoMusical{tipoMusical} {}


std::string Artista::getTipoMusical() const {
    return tipoMusical;
}

void Artista::setTipoMusical(const std::string& tipoMusical) {
    this->tipoMusical = tipoMusical;
}

void Artista::adicionarMusica(Musica* musica) {
    setlistShow.push_back(musica);
}

std::list<Musica*> Artista::getSetList() const{
    return this->setlistShow;
}

void Artista::removerMusica(const std::string& nomeMusica) {
    std::list<Musica*>::iterator it{getSetList().begin()};
    for( ; it != getSetList().end(); ++it)
        if((*it)->getNome() == nomeMusica)
            break;

    if (it != getSetList().end()) {
        Musica* ptr{*it};
        getSetList().erase(it);
        delete ptr;
    }
}