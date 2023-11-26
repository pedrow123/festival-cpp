#include <iostream>
#include <list>
#include <string>

#include "ArtistaInternacional.hpp"
#include "ArtistaNacional.hpp"
#include "Festival.hpp"
#include "Pessoa.hpp"
#include "Gerenciador.hpp"
#include "Usuario.hpp"
#include "Admin.hpp"

using namespace festnow;


int main() {
    
    Usuario* usr{new Usuario};
    Admin* adm{new Admin};
    usr->carregarCredenciais("usr.txt");
    adm->carregarCredenciais("adm.txt");


    
    std::cout << "Seja bem-vindo(a) ao FestNow! Visualize e o crie os Festivais mais badalados do momento!" << std::endl;
    while (true) {
        std::string nome;
        std::string senha;
        std::cout << "\nDigite o nome do usuário: ";
        std::getline(std::cin, nome);
        std::cout << "\nDigite a senha: ";
        std::getline(std::cin, senha);

        if (usr->verificarCredenciais(nome, senha)) {
            delete adm;
            adm = nullptr;
            break;
        } else if (adm->verificarCredenciais(nome, senha)) {
            delete usr;
            usr = nullptr;
            break;
        } else {
            std::cout << "\nNenhum usuário foi encontrado! Entre com um registrado";
        }
    }

    std::list<Festival*> listaFestivais;
    std::list<Artista*> listaArtistas;
    Gerenciador* ger{new Gerenciador{listaArtistas, listaFestivais}};

    Palco* cj{new Palco{"Cidade Jardim"}};
    Palco* bt{new Palco{"Butantã"}};

    ArtistaInternacional* am {new ArtistaInternacional{"Arctic Monkeys", 10, "Rock Alternativo","Inglaterra" }};
    ArtistaNacional* pr {new ArtistaNacional{"Plebe Rude", 25, "Distrito Federal"}};
    ArtistaInternacional* mgmt {new ArtistaInternacional{"MGMT", 10, "Alternativa", "Estados Unidos"}};

    Apresentacao* pr_ap{new Apresentacao{"13:00", pr}};
    cj->addApresentacao(pr_ap);
    ger->addArtista(pr);
    Apresentacao* am_ap{new Apresentacao{"21:30", am}}; 
    cj->addApresentacao(am_ap);
    ger->addArtista(am);
    Apresentacao* mgmt_ap{new Apresentacao{"18:00", mgmt}};
    bt->addApresentacao(mgmt_ap);
    ger->addArtista(mgmt);

    Festival* Lollapalooza{new Festival{"Lollapalooza"}};

    Lollapalooza->addPalco(cj);
    Lollapalooza->addPalco(bt);

    ger->addFestival(Lollapalooza);

    int op{0};

    std::list<Festival*>::const_iterator it;
    while (op != 5) {
        std::cout << "Qual ação deseja realizar?\n";
        std::cout << "1. Visualizar Festivais\n";
        std::cout << "2. Visualizar artistas registrados\n";
        std::cout << "3. Criar Festival\n";
        std::cout << "4. Registrar Artista\n";
        std::cout << "5. Sair\n";
        std::cin >> op;
        switch (op) {
            case 1:
                for (it = ger->getFestivais().begin(); it != ger->getFestivais().end(); ++it){
                    std::cout << *(*it);
                }       
                break;
            case 2:
                ger->showArtistas();
                break;
            case 3:
                if (adm == nullptr) {
                    std::cout << "\nSeu usuário não tem permissão para acessar esta funcionalidade!\n";
                    break;
                }
                ger->criarFestival();
                break;
            case 4:
                if (adm == nullptr) {
                    std::cout << "\nSeu usuário não tem permissão para acessar esta funcionalidade!\n";
                    break;
                }
                ger->regArtista();
                break;

            default:
                break;
        }
    }

    delete ger;

    if (usr)
        delete usr;
    else
        delete adm;

    return 0;
}