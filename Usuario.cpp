#include "Usuario.hpp"
#include <fstream>
#include <iostream>

namespace festnow {
bool Usuario::verificarCredenciais(const std::string& nomeUsuario, const std::string& senha) {
    return (this->nomeUsuario == nomeUsuario && this->senha == senha);
}

void Usuario::carregarCredenciais(const std::string& arquivo) {
    std::ifstream arquivoCredenciais(arquivo);
    if (arquivoCredenciais.is_open()) {
        arquivoCredenciais >> nomeUsuario >> senha;
        arquivoCredenciais.close();
    }
}
}
