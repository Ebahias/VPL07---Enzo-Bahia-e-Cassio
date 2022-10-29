#include <string>
#include <vector>
#include <map>
#include <sstream>

class Intruso{
    /*Continue a implementação da classe Intruso*/
    private:
        std::vector<std::map<char, std::vector<int>>> _code;
        std::vector<std::string> _senhas;
        

    public:
        Intruso();
        ~Intruso();
        void set_senha_vazada(std::string vazou);
        std::string crack_senha();
};