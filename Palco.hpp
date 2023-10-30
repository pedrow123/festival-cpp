#ifndef PALCO_HPP
#define PALCO_HPP

#include <list>
#include <string>

#include "Apresentacao.hpp"

class Palco {
    public:
        Palco(std::string nome);
        Palco(std::string nome, std::list<Apresentacao> apresentacao);
    
    private:
        std::string nome;
        std::list<Apresentacao*> apresentacao;
};

#endif