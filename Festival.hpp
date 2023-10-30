#ifndef FESTIVAL_HPP
#define FESTIVAL_HPP

#include <string>
#include <list>

#include "Palco.hpp"

class Festival {
   public:
    Festival(std::string nome);
    Festival(std::string nome, std::list<Palco> palcos);
    

   
   private:
    std::string nome;
    std::list<Palco> palcos;
    // LineUp lineup;
};

#endif