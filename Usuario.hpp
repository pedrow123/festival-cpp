#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>

namespace festnow {
class Usuario {
    public:
        bool verificarCredenciais(const std::string& nomeUsuario, const std::string& senha);
        void carregarCredenciais(const std::string& arquivo);
    private:
        std::string nomeUsuario;
        std::string senha;
};
}

#endif
