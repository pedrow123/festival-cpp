#ifndef ARTISTA_NACIONAL_HPP
#define ARTISTA_NACIONAL_HPP

#include "Artista.hpp"

class ArtistaNacional : public Artista {
public:
    ArtistaNacional(std::string nome, unsigned short int anosAtividade, std::string estado);
    ArtistaNacional(std::string nome, unsigned short int anosAtividade, std::string tipoMusical, std::string estado);

    
    virtual unsigned int calculaCache() const override;
    virtual void apresentar() const override;

    std::string getEstado() const;
    void setEstado(const std::string estado);

private:
    std::string estado;
};

#endif