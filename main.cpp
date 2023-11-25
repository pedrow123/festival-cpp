#include <iostream>
#include <list>
#include <string>

#include "ArtistaInternacional.hpp"
#include "ArtistaNacional.hpp"
#include "Festival.hpp"
#include "Musica.hpp"
#include "Pessoa.hpp"
#include "Gerenciador.hpp"


int main() {
    std::cout << "Seja bem-vindo(a) ao FestNow! Visualize e o crie os Festivais mais badalados do momento!" << std::endl;

    std::list<Festival*> listaFestivais;
    std::list<Artista*> listaArtistas;
    Gerenciador* ger{new Gerenciador{listaArtistas, listaFestivais}};

    Palco* cj{new Palco{"Cidade Jardim"}};
    // Palco* bt{new Palco{"Butantã"}};
    // Palco* alt{new Palco{"Alternativo"}};

    Apresentacao* am{new Apresentacao{"21:30", new ArtistaInternacional{"Arctic Monkeys", 10, "Rock Alternativo","Inglaterra" }}}; 
    cj->addApresentacao(am);
    Apresentacao* pr{new Apresentacao{"13:00", new ArtistaNacional{"Plebe Rude", 25, "Distrito Federal"}}};
    cj->addApresentacao(pr);

    Festival* Lollapalooza{new Festival{"Lollapalooza"}};

    Lollapalooza->addPalco(cj);

    ger->addFestival(Lollapalooza);

    // listaFestivais.push_back(Lollapalooza);

    // delete Lollapalooza;


    std::string nome;

    int op;
    std::cout << "Qual ação deseja realizar?\n";
    std::cout << "1. Criar Festival\n";
    std::cout << "2. Visualizar Festivais\n";
    std::cout << "3. Visualizar artistas participantes\n";
    std::cout << "4. Visualizar palcos\n";
    std::cout << "5. Sair\n";
    std::cin >> op;

    std::list<Festival*>::const_iterator it;
    std::list<Palco*>::const_iterator itPalco;
    std::list<Apresentacao*>::const_iterator itAp;
    while (op != 5) {
        switch (op) {
            case 1:
                ger->criarFestival();
                break;
            case 2:
                for (it = ger->getFestivais().begin(); it != ger->getFestivais().end(); ++it){
                    std::cout << "Nome Festival: " << (*it)->getNome() << "\n";
                    for(itPalco = (*it)->getPalcos().begin(); itPalco != (*it)->getPalcos().end(); itPalco++){
                        if ((*itPalco) == nullptr) {
                            std::cout << "It Palco null\n";
                            continue;
                        }
                        std::cout << "---> Nome do Palco: " << (*itPalco)->getNome();
                        for(itAp = (*itPalco)->getApresentacoes().begin(); itAp != (*itPalco)->getApresentacoes().end(); ++itAp){
                            if ((*itAp) == nullptr) {
                                std::cout << "It Ap null\n";
                                continue;
                            }
                            
                            std::cout << "-------------> ";
                            (*itAp)->getArtista()->apresentar();
                        }
                    }
                }
                
                break;
                // case 3:

                // case 4:

            default:
                break;
        }

        std::cout << "Qual ação deseja realizar?\n";
        std::cout << "1. Criar Festival\n";
        std::cout << "2. Visualizar Festivais\n";
        std::cout << "3. Visualizar artistas participantes\n";
        std::cout << "4. Visualizar palcos\n";
        std::cout << "5. Sair\n";
        std::cin >> op;
    }

    delete ger;


    return 0;
}