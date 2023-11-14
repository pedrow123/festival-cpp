#include "ArtistaNacional.hpp"

#include <iostream>

ArtistaNacional::ArtistaNacional(std::string nome, unsigned short int anosAtividade,
                                 std::string estado)
    : Artista{nome, anosAtividade}, estado{estado} {}

ArtistaNacional::ArtistaNacional(std::string nome, unsigned short int anosAtividade,
                                 std::string tipoMusical, std::string estado)
    : Artista{nome, anosAtividade, tipoMusical}, estado{estado} {}

std::string ArtistaNacional::getEstado() const { return this->estado; }

void ArtistaNacional::setEstado(const std::string estado) {
    this->estado = estado;
}

unsigned int ArtistaNacional::calculaCache() const { return 1000; }

void ArtistaNacional::apresentar() const {
    std::cout << "Artista Nacional - " << this->getNome();
    std::cout << "Estado: " << getEstado();
    std::cout << "Cache " << calculaCache() << std::endl;
}