#ifndef FESTIVAL_EXCEPTION_HPP
#define FESTIVAL_EXCEPTION_HPP

#include <stdexcept>

namespace festnow {
class FestivalException : public std::runtime_error {
public:
    std::string festival;
    
    FestivalException(const std::string& motivo, std::string festival);
    virtual ~FestivalException() = default;
};
}

#endif