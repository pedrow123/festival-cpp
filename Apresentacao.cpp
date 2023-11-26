#include "Apresentacao.hpp"

namespace festnow {
Apresentacao::Apresentacao(const std::string horario, Artista* const artista)
    : horario{horario}, artista{artista} {}

Apresentacao::~Apresentacao(){
}

std::string Apresentacao::getHorario() const { return this->horario; }
void Apresentacao::setHorario(const std::string horario) {
    this->horario = horario;
}

const Artista* Apresentacao::getArtista() const { return this->artista; }

void Apresentacao::setArtista(Artista* const artista) {
    this->artista = artista;
}

std::ostream& operator<<(std::ostream& stream, const Apresentacao& ap) {

    stream << ap.getHorario() << " | " << ap.getArtista()->getNome() <<" | "<< ap.getArtista()->getOrigem() << '\n' << '\n';

    return stream;
}

}