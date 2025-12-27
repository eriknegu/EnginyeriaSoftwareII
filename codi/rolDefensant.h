
#include <string>

class rolDefensant
{
public:
    virtual ~rolDefensant() = default;
    virtual void defensa() = 0;
    virtual std::string nom() const = 0;
};
