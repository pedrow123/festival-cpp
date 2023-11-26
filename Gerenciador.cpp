#include "Gerenciador.hpp"

#include <string>
#include <iostream>
#include <limits>

namespace festnow {
Gerenciador::Gerenciador(const std::list<Artista*> listaArtistas, const std::list<Festival*> listaFestivais) : listaArtistas{listaArtistas}, listaFestivais{listaFestivais} {}

Gerenciador::~Gerenciador(){
    std::list<Festival*>::const_iterator it{this->listaFestivais.begin()};
    std::list<Artista*>::const_iterator it2{this->listaArtistas.begin()};

    for (; it != this->listaFestivais.end(); ++it) 
        delete *it;

    for (; it2 != this->listaArtistas.end(); ++it2) 
        delete *it2;
    

}

void Gerenciador::criarFestival(){
    std::string nome;
    std::cout << "\nDigite o nome do Festival: ";
    // limpa o buffer de entrada
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Festival* novoFestival;
    
    while (true) {
        try {
            std::getline(std::cin, nome);
            novoFestival = new Festival{nome};
            this->addFestival(novoFestival);
            std::cout << '\n';
            break;
        } catch(FestivalException& iv) {
            std::cout << "\nNão foi possível criar o festival " << novoFestival->getNome() << "!";
            std::cout << "\nMotivo: " << iv.what();
            std::cout << "\nDigite um nome válido para o festival: ";

            delete novoFestival;
        }

    }

    std::cout << "Agora será necessário criar os palcos e suas respectivas apresentações\n";

    int op = 1;
    while(op == 1){
        std::cout << "Digite o nome do palco: ";
        Palco* novoPalco;
        
        while (true) {
            try {
                std::getline(std::cin, nome);
                novoPalco = new Palco{nome};
                novoFestival->addPalco(novoPalco);
                break;
            } catch(const PalcoException& iv) {
                std::cout << "Palco " << novoFestival->getNome() << " não pode ser criado\n";
                std::cout << "\nMotivo: " << iv.what();
                std::cout << "\nDigite um nome válido (não utilizado ainda no festival) para o palco: ";
                delete novoPalco;
            }
        }
        std::cout << "\nVamos criar as apresentações do palco " << novoPalco->getNome() << "\n";

        int opAp = 1;
        while(opAp == 1){

            std::string nomeArtista, horario;
            Apresentacao* novaApresentacao;

            std::cout << "Digite o nome do Artista: ";
            std::getline(std::cin, nomeArtista);
            std::cout << "Digite o horário em que o artista vai se apresentar no palco " << novoPalco->getNome() << ": ";
            std::getline(std::cin, horario);

            // Verifica se o artista já existe na lista
            std::list<Artista*>::const_iterator it;
            for(it = this->listaArtistas.begin(); it != this->listaArtistas.end(); ++it)
                if((*it)->getNome() == nomeArtista)
                    break;

            if(it != this->listaArtistas.end()){
                novaApresentacao = new Apresentacao{horario, (*it)};
            } else {
                Artista* novoArtista;
                novoArtista = criarArtista(nomeArtista);
                this->addArtista(novoArtista);
                novaApresentacao = new Apresentacao{horario, novoArtista};
            }


            novoPalco->addApresentacao(novaApresentacao);
            
            std::cout << "Deseja criar uma nova apresentação para este palco?\n";
            std::cout << "1 - Sim\n";
            std::cout << "2 - Não\n";
            std::cin >> opAp;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "Deseja criar outro palco para o festival " << novoFestival->getNome() << "?\n";
        std::cout << "1 - Sim\n";
        std::cout << "2 - Não\n";
        std::cin >> op;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

}

Artista* Gerenciador::criarArtista(const std::string nomeArtista){
    unsigned short int art, anos;
    std::string tipoMusical;
    std::cout << "\nDigite o tipo musical do artista: ";
    std::getline(std::cin, tipoMusical);
    std::cout << "\nDigite quantos anos de atividade do artista " << nomeArtista << ": ";
    std::cin >> anos;
    std::cout << "\nArtista Internacional?\n1. Sim\n2. Não\n";
    std::cin >> art;
    if(art == 1){
        ArtistaInternacional* novoArtista;
        std::string pais;
        std::cout << "\nDigite o país do artista: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, pais);
        novoArtista = new ArtistaInternacional{nomeArtista, anos, tipoMusical, pais};
        return novoArtista;
    } else {
        ArtistaNacional* novoArtista;
        std::string estado;
        std::cout << "\nDigite o estado do artista: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, estado);
        novoArtista = new ArtistaNacional{nomeArtista, anos, tipoMusical, estado}; 
        return novoArtista;
    }
}

void Gerenciador::addArtista(Artista* const artista){
    this->listaArtistas.push_back(artista);

}

void Gerenciador::regArtista() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string nome;
        
    while (true) {
        std::cout << "\nDigite o nome do artista: ";
        std::getline(std::cin, nome);

        std::list<Artista*>::const_iterator it;
        for(it = this->listaArtistas.begin(); it != this->listaArtistas.end(); ++it)
            if((*it)->getNome() == nome)
                break;
            
        if(it != this->listaArtistas.end()){
            std::cout << "Artista já foi registrado! Registre outro" << std::endl;
        } else {
            Artista* novoArtista;
            novoArtista = criarArtista(nome);
            this->addArtista(novoArtista);
            break;
        }
    }
}

void Gerenciador::showArtistas() {
    std::list<Artista*>::const_iterator it{this->listaArtistas.begin()};
    std::cout << std::endl;

    for (; it != this->listaArtistas.end(); ++it) {
        std::cout << (*it)->getNome() << " - " << (*it)->getOrigem() << " - " << (*it)->getTipoMusical() << "\n\n";
    }
}


void Gerenciador::removeArtista(std::string& nomeArtista){
    std::list<Artista*>::iterator it;
    for(it = this->listaArtistas.begin(); it != this->listaArtistas.end(); ++it)
        if((*it)->getNome() == nomeArtista)
            break;

    if(it != this->listaArtistas.end()){
        Artista* ptr{*it};
        this->listaArtistas.erase(it);
        delete ptr;
    }
        
}
const std::list<Artista*>& Gerenciador::getArtistas() const{
    return this->listaArtistas;
}

void Gerenciador::addFestival(Festival* const festival){
    std::string erro{"Festival com o mesmo nome já existe!"};

    // Verifica se o palco já existe
    for (Festival* f : this->listaFestivais) {
        if (f->getNome() == festival->getNome()) {
            throw FestivalException(
                erro, festival->getNome());
        }
    }
    
    this->listaFestivais.push_back(festival);
}

void Gerenciador::removeFestival(std::string& nomeFestival){
    std::list<Festival*>::iterator it;
    for(it = this->listaFestivais.begin(); it != this->listaFestivais.end(); ++it)
        if((*it)->getNome() == nomeFestival)
            break;

    if(it != this->listaFestivais.end()){
        Festival* ptr{*it};
        this->listaFestivais.erase(it);
        delete ptr;
    }
}

const std::list<Festival*>& Gerenciador::getFestivais() const{
    return this->listaFestivais;
}
}