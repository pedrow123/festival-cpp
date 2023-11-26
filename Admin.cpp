#include "Admin.hpp"
#include <fstream>

namespace festnow{
bool Admin::verificarCredenciais(const std::string& nomeUsuario, const std::string& senha) {
    return (this->nomeUsuario == nomeUsuario && this->senha == senha);
}

void Admin::carregarCredenciais(const std::string& arquivo) {
    std::ifstream arquivoCredenciais(arquivo);
    if (arquivoCredenciais.is_open()) {
        arquivoCredenciais >> nomeUsuario >> senha;
        arquivoCredenciais.close();
    }
}
}
