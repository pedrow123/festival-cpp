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

    int op, opAp = 1;
    while(op != 0){
        std::cout << "Digite o nome do palco\n";
        std::cin >> nome;
        Palco* novoPalco;
        novoPalco = new Palco{nome};
        std::cout << "Digite as apresentações do Palco " << nome << ":\n";
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

    // Apresentacao* am{new Apresentacao{"21:30", new
    // ArtistaInternacional{"Arctic Monkeys", 10, "Rock
    // Alternativo","Inglaterra" }}}; Apresentacao* pr{new Apresentacao{"13:00",
    // new ArtistaNacional{"Plebe Rude", 25, "Distrito Federal"}}};

    // Festival* Lollapalooza{new Festival{"Lollapalooza"}};

    // cj->addApresentacao(am);
    // cj->addApresentacao(pr);
    // Lollapalooza->addPalco(cj);

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
    while (op != 5) {
        switch (op) {
            case 1:
                criarFestival();
                break;
            case 2:
                for (it = listaFestivais.begin(); it != listaFestivais.end(); ++it){
                    std::cout << (*it)->getNome() << "\n";
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
    return 0;
}