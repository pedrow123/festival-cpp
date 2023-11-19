#include <stdexcept>

class FestivalException : public std::runtime_error {
public:
    FestivalException(const std::string& message)
        : std::runtime_error(message) {}
};