#ifndef MUSICA_HPP
#define MUSICA_HPP

#include <string>
#include <cstdint>
#include <list>

class Artista;
// #include "Artista.hpp"

class Musica {

    public:
        Musica(std::string nome, unsigned short int duracaoSegundos, std::list<Artista*> Escritores);
        Musica(std::string nome, unsigned short int duracaoSegundos);

        void setNome(const std::string nome);
        std::string& getNome() const;

        void setDuracao(const unsigned short int duracaoSegundos);
        unsigned short int getDuracao() const;
        
        void addEscritor(Artista* const escritor);
        void removeEscritor(std::string& nomeEscritor); 
        std::list<Artista*> getEscritores() const;
    
    private:
        std::string nome;
        uint8_t duracaoSegundos;
        std::list<Artista*> escritores;
};

#endif