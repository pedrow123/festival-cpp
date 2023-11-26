#ifndef ARTISTA_HPP
#define ARTISTA_HPP

#include <list>
#include <string>

#include "Pessoa.hpp"

namespace festnow {
class Artista : public Pessoa {
   public:
    Artista(std::string nome, unsigned short int idade);
    Artista(std::string nome, unsigned short int idade, std::string tipoMusical);
    virtual std::string getOrigem() const = 0;
    virtual ~Artista();


    std::string getTipoMusical() const;
    void setTipoMusical(const std::string& tipoMusical);

   private:
    std::string tipoMusical;
};
}

#endif