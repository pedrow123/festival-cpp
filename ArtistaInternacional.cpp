#include "ArtistaInternacional.hpp"

#include <iostream>

ArtistaInternacional::ArtistaInternacional(std::string nome,
                                           unsigned short int anosAtividade,
                                           std::string pais)
    : Artista{nome, anosAtividade}, pais{pais} {}

ArtistaInternacional::ArtistaInternacional(std::string nome,
                                           unsigned short int anosAtividade,
                                           std::string tipoMusical,
                                           std::string pais)
    : Artista{nome, anosAtividade, tipoMusical}, pais{pais} {}

std::string ArtistaInternacional::getPais() const { return this->pais; }

void ArtistaInternacional::setPais(const std::string pais) {
    this->pais = pais;
}

unsigned int ArtistaInternacional::calculaCache() const { return 1000; }

void ArtistaInternacional::apresentar() const {
    std::cout << "Artista Interacional - " << this->getNome();
    std::cout << "Pais: " << getPais();
    std::cout << "Cache " << calculaCache() << std::endl;
}
