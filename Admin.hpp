#ifndef ADMIN_HPP
#define ADMIN_HPP

#include <string>

namespace festnow {
class Admin {
    public:
        bool verificarCredenciais(const std::string& nomeUsuario, const std::string& senha);
        void carregarCredenciais(const std::string& arquivo);
    private:
        std::string nomeUsuario;
        std::string senha;
};
}

#endif
