#include "Gerenciador.hpp"

#include <string>
#include <iostream>

Gerenciador::Gerenciador(const std::list<Artista*> listaArtistas, const std::list<Festival*> listaFestivais) : listaArtistas{listaArtistas}, listaFestivais{listaFestivais} {}

Gerenciador::~Gerenciador(){
    std::list<Festival*>::iterator it;
    // std::list<Artista*>::iterator itArt;
    // for(itArt = this->listaArtistas.begin(); itArt != this->listaArtistas.end(); ++itArt)
    //     delete *itArt;
    for (it = this->listaFestivais.begin(); it != this->listaFestivais.end(); ++it) 
        delete *it;
    

}

void Gerenciador::criarFestival(){
    std::string nome;
    std::cout << "\nDigite o nome do Festival: ";
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
            Apresentacao* novaApresentacao;

            std::cout << "Digite o nome do Artista: ";
            std::cin >> nomeArtista;

            // Verifica se o artista já existe na lista
            std::list<Artista*>::iterator it;
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
            
            std::cout << "Se não deseja criar outra apresentação digite 0.\n";
            std::cin >> opAp;
        }
        novoFestival->addPalco(novoPalco);
        std::cout << "Se não deseja criar outro palco para o Festival " << nome << " digite 0.";
        std::cin >> op;
    }

    this->addFestival(novoFestival);

}

Artista* Gerenciador::criarArtista(const std::string nomeArtista){
    unsigned short int art, anos;
    std::cout << "\nDigite quantos anos de atividade do artista:\n" << nomeArtista;
    std::cin >> anos;
    std::cout << "Artista Internacional?\n1. Sim\n2. Não\n";
    std::cin >> art;
    if(art == 1){
        ArtistaInternacional* novoArtista;
        std::string pais;
        std::cout << "\nDigite o país do artista ";
        std::cin >> pais;
        novoArtista = new ArtistaInternacional{nomeArtista, anos, pais};
        return novoArtista;
    } else {
        ArtistaNacional* novoArtista;
        std::string estado;
        std::cout << "\nDigite o estado do artista ";
        std::cin >> estado;
        novoArtista = new ArtistaNacional{nomeArtista, anos, estado}; 
        return novoArtista;
    }
}

void Gerenciador::addArtista(Artista* const artista){
    this->listaArtistas.push_back(artista);

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