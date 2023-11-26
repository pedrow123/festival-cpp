#include "ArtistaInternacional.hpp"

#include <iostream>

namespace festnow {
ArtistaInternacional::ArtistaInternacional(std::string nome,
                                           unsigned short int anosAtividade,
                                           std::string pais)
    : Artista{nome, anosAtividade}, pais{pais} {}

ArtistaInternacional::ArtistaInternacional(std::string nome,
                                           unsigned short int anosAtividade,
                                           std::string tipoMusical,
                                           std::string pais)
    : Artista{nome, anosAtividade, tipoMusical}, pais{pais} {}

std::string ArtistaInternacional::getOrigem() const { return this->pais; }

void ArtistaInternacional::setPais(const std::string pais) {
    this->pais = pais;
}

unsigned int ArtistaInternacional::calculaCache() const { return 1000; }

}
