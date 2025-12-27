
#include <string>

class rolAtacant
{
public:
    virtual ~rolAtacant() = default;     // IMPORTANT (polimorfisme)
    virtual void ataca() = 0;            // =0 => “interfície” (virtual pur)
    virtual std::string nom() const = 0; // útil per mostrar quin rol és
};
