parametrosCompilacao=-Wall -g #-Wshadow
nomePrograma=festival

all: $(nomePrograma)

$(nomePrograma): main.o Gerenciador.o Festival.o Apresentacao.o Artista.o ArtistaInternacional.o ArtistaNacional.o Palco.o Pessoa.o FestivalException.o PalcoException.o Admin.o Usuario.o
	g++ -o $(nomePrograma) main.o Gerenciador.o Festival.o Apresentacao.o Artista.o ArtistaInternacional.o ArtistaNacional.o Palco.o Pessoa.o FestivalException.o PalcoException.o Admin.o Usuario.o $(parametrosCompilacao)

main.o: main.cpp
	g++ -c main.cpp $(parametrosCompilacao)
	
Pessoa.o: Pessoa.hpp Pessoa.cpp
	g++ -c Pessoa.cpp $(parametrosCompilacao)

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

FestivalException.o: FestivalException.hpp FestivalException.cpp
	g++ -c FestivalException.cpp $(parametrosCompilacao)

PalcoException.o: PalcoException.hpp PalcoException.cpp
	g++ -c PalcoException.cpp $(parametrosCompilacao)

Festival.o: Festival.hpp Festival.cpp
	g++ -c Festival.cpp $(parametrosCompilacao)

Gerenciador.o: Gerenciador.hpp Gerenciador.cpp
	g++ -c Gerenciador.cpp $(parametrosCompilacao)

Admin.o: Admin.hpp Admin.cpp
	g++ -c Admin.cpp $(parametrosCompilacao)

Usuario.o: Usuario.hpp Usuario.cpp
	g++ -c Usuario.cpp $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)
