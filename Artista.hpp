#ifndef ARTISTA_HPP
#define ARTISTA_HPP

#include <list>
#include <string>

#include "Musica.hpp"
#include "Pessoa.hpp"

class Artista : public Pessoa {
   public:
    Artista(std::string nome, unsigned short int idade);
    Artista(std::string nome, unsigned short int idade, std::string tipoMusical);
    virtual unsigned int calculaCache() const = 0;
    virtual void apresentar() const = 0;
    virtual ~Artista() = default;

    void adicionarMusica(Musica* musica);
    void removerMusica(const std::string& nomeMusica);


    std::list<Musica*> getSetList() const;

    std::string getTipoMusical() const;
    void setTipoMusical(const std::string& tipoMusical);

   private:
    std::string tipoMusical;
    std::list<Musica*> setlistShow;
    int cache;
};

#endif