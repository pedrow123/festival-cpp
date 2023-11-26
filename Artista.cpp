#include "Artista.hpp"

namespace festnow {
Artista::Artista(std::string nome, unsigned short int idade)
    : Pessoa{nome, idade}, tipoMusical{"Indefinido"} {}

Artista::Artista(std::string nome, unsigned short int idade,
                 std::string tipoMusical)
    : Pessoa{nome, idade}, tipoMusical{tipoMusical} {}

Artista::~Artista() {

}

std::string Artista::getTipoMusical() const { return tipoMusical; }

void Artista::setTipoMusical(const std::string& tipoMusical) {
    this->tipoMusical = tipoMusical;
}

}