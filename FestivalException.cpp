#include "FestivalException.hpp"

namespace festnow
{
    FestivalException::FestivalException(const std::string& motivo, std::string festival) : 
    std::runtime_error{motivo}, festival{festival} {}
}