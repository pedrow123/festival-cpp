#ifndef ARTISTA_INTERNACIONAL_HPP
#define ARTISTA_INTERNACIONAL_HPP

#include "Artista.hpp"

class ArtistaInternacional : public Artista {
   public:
    ArtistaInternacional(std::string nome, unsigned short int idade,
                         std::string pais);
    ArtistaInternacional(std::string nome, unsigned short int idade,
                         std::string tipoMusical, std::string pais);
    unsigned int calculaCache() const override;
    void apresentar() const override;

    void setPais(const std::string pais);
    std::string getPais() const;

    unsigned int ArtistaInternacional::calculaCache() const;

   private:
    std::string pais;
};

#endif