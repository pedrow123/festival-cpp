#ifndef PALCO_EXCEPTION_HPP
#define PALCO_EXCEPTION_HPP

#include <string>
#include <stdexcept>

namespace festnow {
class PalcoException : public std::runtime_error {
public:
    std::string palco;
    
    PalcoException(std::string& motivo, std::string palco);
    virtual ~PalcoException() = default;
};
}

#endif