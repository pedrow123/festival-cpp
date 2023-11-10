#include "Festival.hpp"

Festival::Festival(std::string nome) : nome{nome} {}
Festival::Festival(std::string nome, std::list<Palco*> palcos)
    : nome{nome}, palcos{palcos} {}

void Festival::setNome(const std::string nome){
    this->nome = nome;
}

std::string Festival::getNome() const{
    return this->nome;
}

void Festival::addPalco(Palco* const palco){
    getPalcos().push_back(palco);
}

void Festival::removePalco(std::string& nomePalco){
    std::list<Palco*>::iterator it{getPalcos().begin()};
    for (; it != getPalcos().end(); ++it)
        if ((*it)->getNome() == nomePalco) break;

    if (it != getPalcos().end()) {
        Palco* ptr{*it};
        getPalcos().erase(it);
        delete ptr;
    }
}

std::list<Palco*> Festival::getPalcos() const{
    return this->palcos;
}