#include "Apresentacao.hpp"

Apresentacao::Apresentacao(const std::string horario, Artista* const artista)
    : horario{horario}, artista{artista} {}

Apresentacao::~Apresentacao(){
    setArtista(nullptr);
}

std::string Apresentacao::getHorario() const { return this->horario; }
void Apresentacao::setHorario(const std::string horario) {
    this->horario = horario;
}

const Artista* Apresentacao::getArtista() const { return this->artista; }

void Apresentacao::setArtista(Artista* const artista) {
    this->artista = artista;
}