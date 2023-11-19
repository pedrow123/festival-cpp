#include <iostream>
#include "Festival.hpp"
#include "ArtistaInternacional.hpp"
#include "ArtistaNacional.hpp"
#include "Festival.hpp"
#include "Musica.hpp"
#include "Pessoa.hpp"

int main() {
    
    std::cout << "Seja bem-vindo(a) ao FestNow! Visualize e o crie os Festivais mais badalados do momento!" << std::endl;

    std::list<Festival*> listaFestivais;
    Palco* cj{new Palco{"Cidade Jardim"}};
    Palco* bt{new Palco{"Butantã"}};
    Palco* alt{new Palco{"Alternativo"}};

    Apresentacao* am{new Apresentacao{"21:30", new ArtistaInternacional{"Arctic Monkeys", 10, "Rock Alternativo","Inglaterra" }}};
    Apresentacao* pr{new Apresentacao{"13:00", new ArtistaNacional{"Plebe Rude", 25, "Distrito Federal"}}};

    Festival* Lollapalooza{new Festival{"Lollapalooza"}};

    
    cj->addApresentacao(am);
    cj->addApresentacao(pr);
    Lollapalooza->addPalco(cj);
    
    return 0;
}