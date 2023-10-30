#ifndef ARTISTA_HPP
#define ARTISTA_HPP

#include <list>
#include <string>

#include "Pessoa.hpp"
#include "Musica.hpp"

class Artista : public Pessoa {
    public:
        Artista(std::string nome, unsigned short int idade);
        virtual unsigned int calculaCache() const = 0;
    
    private:
        std::string tipoMusical;
        std::list<Musica*> setlistShow;
        bool ehInternacional;
};

#endif