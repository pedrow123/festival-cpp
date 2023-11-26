#include "PalcoException.hpp"

namespace festnow {

PalcoException::PalcoException(std::string& motivo, std::string palco) : 
std::runtime_error{motivo}, palco{palco} {
}

}