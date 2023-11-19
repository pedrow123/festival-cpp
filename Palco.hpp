#ifndef PALCO_HPP
#define PALCO_HPP

#include <list>
#include <string>

#include "Apresentacao.hpp"

class Palco {
   public:
    Palco(std::string nome);
    Palco(std::string nome, std::list<Apresentacao*> apresentacoes);
    ~Palco();

    void setNome(const std::string nome);
    std::string getNome() const;

    void addApresentacao(Apresentacao* const apresentacao);
    void removeApresentacao(std::string& nomeArtista);
    std::list<Apresentacao*> getApresentacoes() const;

   private:
    std::string nome;
    std::list<Apresentacao*> apresentacoes;
};

#endif