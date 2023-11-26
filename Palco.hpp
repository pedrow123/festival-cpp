#ifndef PALCO_HPP
#define PALCO_HPP

#include <list>
#include <string>
#include <iostream>

#include "Apresentacao.hpp"

namespace festnow {
class Palco {
   friend std::ostream& operator<<(std::ostream& stream, const Palco& palco);
   public:
    Palco(std::string nome);
    Palco(std::string nome, std::list<Apresentacao*> apresentacoes);
    virtual ~Palco();

    void setNome(const std::string nome);
    std::string getNome() const;

    void addApresentacao(Apresentacao* const apresentacao);
    void removeApresentacao(std::string& nomeArtista);
    const std::list<Apresentacao*> &getApresentacoes() const;

   private:
    std::string nome;
    std::list<Apresentacao*> apresentacoes;
};
}

#endif