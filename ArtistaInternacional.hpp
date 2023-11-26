#ifndef ARTISTA_INTERNACIONAL_HPP
#define ARTISTA_INTERNACIONAL_HPP

#include "Artista.hpp"

namespace festnow {
class ArtistaInternacional : public Artista {
   public:
    ArtistaInternacional(std::string nome, unsigned short int anosAtividade,
                         std::string pais);
    ArtistaInternacional(std::string nome, unsigned short int anosAtividade,
                         std::string tipoMusical, std::string pais);
    virtual unsigned int calculaCache() const override;
    virtual std::string getOrigem() const override;

    void setPais(const std::string pais);

   private:
    std::string pais;
};
}

#endif