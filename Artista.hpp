#ifndef ARTISTA_HPP
#define ARTISTA_HPP

#include <list>
#include <string>

#include "Pessoa.hpp"

class Artista : public Pessoa {
    public:
        Artista(std::string nome, int idade, bool estrangeiro);
    
    private:
        bool estrangeiro;
        std::string tipoMusical;
};

#endif