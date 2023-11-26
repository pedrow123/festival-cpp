#include "Palco.hpp"

namespace festnow {
Palco::Palco(std::string nome) : nome{nome} {}

Palco::Palco(std::string nome, std::list<Apresentacao*> apresentacoes)
    : nome{nome}, apresentacoes{apresentacoes} {}

Palco::~Palco(){
    std::list<Apresentacao*>::iterator it;
    for (it = this->apresentacoes.begin(); it != this->apresentacoes.end(); ++it) {
        delete *it;
    }
        
}

void Palco::setNome(const std::string nome) { this->nome = nome; }

std::string Palco::getNome() const { return this->nome; }

void Palco::addApresentacao(Apresentacao* const apresentacao) {
    this->apresentacoes.push_back(apresentacao);
}

void Palco::removeApresentacao(std::string& nomeArtista) {
    std::list<Apresentacao*>::iterator it{this->apresentacoes.begin()};
    for (; it != this->apresentacoes.end(); ++it)
        if ((*it)->getArtista()->getNome() == nomeArtista) break;

    if (it != this->apresentacoes.end()) {
        Apresentacao* ptr{*it};
        this->apresentacoes.erase(it);
        delete ptr;
    }
}

const std::list<Apresentacao*>& Palco::getApresentacoes() const {
    return this->apresentacoes;
}

std::ostream& operator<<(std::ostream& stream, const Palco& palco) {
    std::list<Apresentacao*>::const_iterator it{palco.getApresentacoes().begin()};
    bool vazio{true};

    stream << "Palco: " << palco.getNome() << '\n';
    for (; it != palco.getApresentacoes().end(); ++it) {
        if (vazio)
            stream << "Horários | Artista| País de origem/Estado do Brasil \n\n";

        vazio = false;

        stream << *(*it);
    }

    if (vazio)
        stream << "Ainda não foram registradas apresentações para este Palco!\n\n";

    return stream;
}


}