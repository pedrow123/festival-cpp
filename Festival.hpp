#ifndef FESTIVAL_HPP
#define FESTIVAL_HPP

#include <list>
#include <string>

#include "Palco.hpp"

class Festival {
   public:
    Festival(std::string nome);
    Festival(std::string nome, std::list<Palco*> palcos);

    void setNome(const std::string nome);
    std::string getNome() const;

    void addPalco(Palco* const palco);
    void removePalco(std::string& nomePalco);
    std::list<Palco*> getPalcos() const;

   private:
    std::string nome;
    std::list<Palco*> palcos;
    // LineUp lineup;
};

#endif