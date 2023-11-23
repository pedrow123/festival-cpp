#include <iostream>
#include <list>
#include <string>

#include "ArtistaInternacional.hpp"
#include "ArtistaNacional.hpp"
#include "Festival.hpp"
#include "Musica.hpp"
#include "Pessoa.hpp"

Festival* criarFestival(){
    std::string nome;
    std::cout << "Digite o nome do Festival: ";
    std::cin >> nome;
    Festival* novoFestival;
    novoFestival = new Festival{nome};

    std::cout << "Digite os palcos e suas apresentaçoes.";

    int op = 1;
    while(op != 0){
        std::cout << "Digite o nome do palco\n";
        std::cin >> nome;
        Palco* novoPalco;
        novoPalco = new Palco{nome};
        std::cout << "Digite as apresentações do Palco " << novoPalco->getNome() << ":\n";

        int opAp = 1;
        while(opAp != 0){
            std::string nomeArtista, horario;
            unsigned short int art, anosAtividade;
            std::cout << "Digite o nome do Artista: ";
            std::cin >> nomeArtista;
            std::cout << "\nArtista Internacional?\n1. Sim\n2.Não\n";
            std::cin >> art;
            std::cout << "\nDigite os anos de Atividade do Artista: ";
            std::cin >> anosAtividade;
            if(art == 1){
                ArtistaInternacional* novoArtista;
                std::string pais;
                std::cout << "Digite o país do Artista: ";
                std::cin >> pais;
                novoArtista = new ArtistaInternacional{nomeArtista, anosAtividade, pais};

                std::cout << "\nDigite o horário da apresentação: ";
                std::cin >> horario;

                Apresentacao* novaApresentacao;
                novaApresentacao = new Apresentacao{horario, novoArtista};
                novoPalco->addApresentacao(novaApresentacao);
            } else {
                ArtistaNacional* novoArtista;
                std::string estado;
                novoArtista = new ArtistaNacional{nomeArtista, anosAtividade, estado};

                std::cout << "\nDigite o horário da apresentação: ";
                std::cin >> horario;

                Apresentacao* novaApresentacao;
                novaApresentacao = new Apresentacao{horario, novoArtista};
                novoPalco->addApresentacao(novaApresentacao);
            }
            std::cout << "Se não deseja criar outra apresentação digite 0.\n";
            std::cin >> opAp;
        }
        novoFestival->addPalco(novoPalco);
        std::cout << "Se não deseja criar outro palco para o Festival " << nome << " digite 0.";
        std::cin >> op;
    }

    return novoFestival;
}

int main() {
    std::cout << "Seja bem-vindo(a) ao FestNow! Visualize e o crie os Festivais mais badalados do momento!" << std::endl;

    std::list<Festival*> listaFestivais;
    // Palco* cj{new Palco{"Cidade Jardim"}};
    // Palco* bt{new Palco{"Butantã"}};
    // Palco* alt{new Palco{"Alternativo"}};

    // Apresentacao* am{new Apresentacao{"21:30", new ArtistaInternacional{"Arctic Monkeys", 10, "Rock Alternativo","Inglaterra" }}}; 
    // cj->addApresentacao(am);
    // Apresentacao* pr{new Apresentacao{"13:00", new ArtistaNacional{"Plebe Rude", 25, "Distrito Federal"}}};
    // cj->addApresentacao(pr);

    // Festival* Lollapalooza{new Festival{"Lollapalooza"}};

    // Lollapalooza->addPalco(cj);

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

    std::list<Festival*>::iterator it;
    std::list<Palco*>::const_iterator itPalco;
    std::list<Apresentacao*>::const_iterator itAp;
    while (op != 5) {
        switch (op) {
            case 1:
                Festival* fest;
                fest = criarFestival();
                listaFestivais.push_back(fest);
                break;
            case 2:
                for (it = listaFestivais.begin(); it != listaFestivais.end(); ++it){
                    if ((*it) == nullptr) {
                        std::cout << "It null\n";
                        continue;
                    }
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

    for (it = listaFestivais.begin(); it != listaFestivais.end(); ++it) {
        delete *it;  // Libera cada festival
    }


    return 0;
}