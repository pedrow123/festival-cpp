#include "Festival.hpp"

Festival::Festival(std::string nome) : nome{nome} {}

Festival::Festival(std::string nome, std::list<Palco*> palcos)
    : nome{nome}, palcos{palcos} {}

Festival::~Festival() {
    std::list<Palco*>::iterator it;
    for (it = this->palcos.begin(); it != this->palcos.end(); ++it) 
        delete *it;
}

void Festival::setNome(const std::string nome) { this->nome = nome; }

std::string Festival::getNome() const { return this->nome; }

void Festival::addPalco(Palco* const palco) {
    // if (!palco) {
    //     throw FestivalException(
    //         "Tentativa de adicionar palco nulo ao festival.");
    // }

    // // Verifica se o palco já existe
    // for (Palco* p : this->palcos) {
    //     if (p->getNome() == palco->getNome()) {
    //         throw FestivalException(
    //             "Palco com o mesmo nome já existe no festival.");
    //     }
    // }

    this->palcos.push_back(palco);
}

void Festival::removePalco(std::string& nomePalco) {
    std::list<Palco*>::iterator it{this->palcos.begin()};
    for (; it != this->palcos.end(); ++it)
        if ((*it)->getNome() == nomePalco) break;

    if (it != this->palcos.end()) {
        Palco* ptr{*it};
        this->palcos.erase(it);
        delete ptr;
    }
    // } else {
    //     throw FestivalException("Palco não encontrado no festival.");
    // }
}

const std::list<Palco*>& Festival::getPalcos() const { return this->palcos; }