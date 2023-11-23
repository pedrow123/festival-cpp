#ifndef APRESENTACAO_HPP
#define APRESENTACAO_HPP

#include <string>
#include "Artista.hpp"

class Apresentacao {
    public:
        Apresentacao(std::string horario, Artista* const artista);
        virtual ~Apresentacao();

        std::string getHorario() const;
        void setHorario(const std::string horario);

        const Artista* getArtista() const;
        void setArtista(Artista *const artista);


    private:
        std::string horario;
        Artista* artista;
};

#endif