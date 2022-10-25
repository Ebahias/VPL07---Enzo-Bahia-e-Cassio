#include <string>
#include <vector>
#include <map>
#include <sstream>

class Intruso{
    /*Continue a implementação da classe Intruso*/
    private:
        std::vector<std::map<char, std::vector<int>>> maps;
        std::vector<std::string> senhas;
        std::string letras = "ABCDE";

    public:
        void set_senha_vazada(std::string vazou);
        std::string crack_senha();
};