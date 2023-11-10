parametrosCompilacao=-Wall #-Wshadow
nomePrograma=festival

all: $(nomePrograma)

$(nomePrograma): main.o Festival.o Apresentacao.o Artista.o ArtistaInternacional.o ArtistaNacional.o Musica.o Palco.o Pessoa.o
	g++ -o $(nomePrograma) main.o Festival.o Apresentacao.o Artista.o ArtistaInternacional.o ArtistaNacional.o Musica.o Palco.o Pessoa.o $(parametrosCompilacao)

main.o: main.cpp
	g++ -c main.cpp $(parametrosCompilacao)
	
Pessoa.o: Pessoa.hpp Pessoa.cpp
	g++ -c Pessoa.cpp $(parametrosCompilacao)

Musica.o: Musica.hpp Musica.cpp
	g++ -c Musica.cpp $(parametrosCompilacao)

Artista.o: Artista.hpp Artista.cpp
	g++ -c Artista.cpp $(parametrosCompilacao)

ArtistaNacional.o: ArtistaNacional.hpp ArtistaNacional.cpp
	g++ -c ArtistaNacional.cpp $(parametrosCompilacao)

ArtistaInternacional.o: ArtistaInternacional.hpp ArtistaInternacional.cpp
	g++ -c ArtistaInternacional.cpp $(parametrosCompilacao)

Apresentacao.o: Apresentacao.hpp Apresentacao.cpp
	g++ -c Apresentacao.cpp $(parametrosCompilacao)

Palco.o: Palco.hpp Palco.cpp
	g++ -c Palco.cpp $(parametrosCompilacao)

Festival.o: Festival.hpp Festival.cpp
	g++ -c Festival.cpp $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)
