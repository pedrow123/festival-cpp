#ifndef GERENCIADOR_HPP
#define GERENCIADOR_HPP

#include "Festival.hpp"
#include "Artista.hpp"
#include "ArtistaInternacional.hpp"
#include "ArtistaNacional.hpp"

#include <string>
#include <list>

class Gerenciador {
    public:
        Gerenciador(const std::list<Artista*> listaArtistas, const std::list<Festival*> listaFestivais);
        virtual ~Gerenciador();

        void criarFestival();

        Artista* criarArtista(std::string nomeArtista);

        void addArtista(Artista* const artista);
        void removeArtista(std::string& nomeArtista);
        const std::list<Artista*> &getArtistas() const;

        void addFestival(Festival* const festival);
        void removeFestival(std::string& nomeFestival);
        const std::list<Festival*> &getFestivais() const;
    private:
        std::list<Artista*> listaArtistas;
        std::list<Festival*> listaFestivais;
};

#endif