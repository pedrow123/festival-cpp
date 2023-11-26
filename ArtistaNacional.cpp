#include "ArtistaNacional.hpp"

#include <iostream>

namespace festnow {
ArtistaNacional::ArtistaNacional(std::string nome, unsigned short int anosAtividade,
                                 std::string estado)
    : Artista{nome, anosAtividade}, estado{estado} {}

ArtistaNacional::ArtistaNacional(std::string nome, unsigned short int anosAtividade,
                                 std::string tipoMusical, std::string estado)
    : Artista{nome, anosAtividade, tipoMusical}, estado{estado} {}

std::string ArtistaNacional::getOrigem() const { return this->estado; }

void ArtistaNacional::setEstado(const std::string estado) {
    this->estado = estado;
}

unsigned int ArtistaNacional::calculaCache() const { return 1000; }

}