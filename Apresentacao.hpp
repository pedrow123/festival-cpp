#ifndef APRESENTACAO_HPP
#define APRESENTACAO_HPP

#include <string>
#include "Artista.hpp"
class Apresentacao {
    public:
        Apresentacao(std::string horario, Artista artista);

    private:
        std::string horario;
        Artista artista;
}

#endif