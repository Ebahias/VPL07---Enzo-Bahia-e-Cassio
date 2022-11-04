#include <iostream>
#include "intruso.hpp"

void Intruso::set_senha_vazada(std::string vazou)
{
    std::string valores = vazou.substr(0, 20);
    std::string cod = vazou.substr(20, 11);

    senhas.push_back(cod);

    std::stringstream s(valores);
    int x;
    std::vector<int> numeros;
    while (s >> x)
    {
        numeros.push_back(x);
    }
    
    std::map<char, std::vector<int>> code;
    int n = 0;
    for (int i = 0; i < 5; i++)
    {
        char l = letras[i];
        code[l].push_back(numeros[n]);
        code[l].push_back(numeros[n+1]);
        n += 2; 
    }
    maps.push_back(code);
}

std::string Intruso::crack_senha()
{
    std::string vazou0, vazou1, vazou2;
    if (senhas.size() == 2)
    {
        vazou0 = senhas[0];
        vazou1 = senhas[1];
    }
    else
    {
        vazou0 = senhas[0];
        vazou1 = senhas[1];
        vazou2 = senhas[2];
    }

    std::map<char, std::vector<int>> cod1, cod2, cod3;
    if (maps.size() == 2)
    {
        cod1 = maps[0];
        cod2 = maps[1];
    }
    else
    {
        cod1 = maps[0];
        cod2 = maps[1];
        cod3 = maps[2];
    }

    std::vector<int> senha;
    for (int i = 0; i < vazou0.size(); i++)
    {
        if (senhas.size() == 2)
        {
            char c1 = vazou0[i], c2 = vazou1[i];
            for (auto it1 = cod1.cbegin(); it1 != cod1.cend(); ++it1)
            {
                char it_1 = it1->first;
                if (it_1 == c1)
                {
                    auto char1 = it1;
                    for (auto it2 = cod2.cbegin(); it2 != cod2.cend(); ++it2)
                    {
                        char it_2 = it2->first;
                        if (it_2 == c2)
                        {
                            auto char2 = it2;
                            for (const auto &num1 : char1->second)
                            {
                                for (const auto &num2 : char2->second)
                                {
                                    if (num1 == num2)
                                    {
                                        senha.push_back(num1);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        else
        {
            char c1 = vazou0[i], c2 = vazou1[i], c3 = vazou2[i];
            for (auto it1 = cod1.cbegin(); it1 != cod1.cend(); ++it1)
            {
                char it_1 = it1->first;
                if (it_1 == c1)
                {
                    auto char1 = it1;
                    for (auto it2 = cod2.cbegin(); it2 != cod2.cend(); ++it2)
                    {
                        char it_2 = it2->first;
                        if (it_2 == c2)
                        {
                            auto char2 = it2;
                            for (auto it3 = cod3.cbegin(); it3 != cod3.cend(); ++it3)
                            {
                                char it_3 = it3->first;
                                if (it_3 == c3)
                                {
                                    auto char3 = it3;
                                    for (const auto &num1 : char1->second)
                                    {
                                        for (const auto &num2 : char2->second)
                                        {
                                            for (const auto &num3 : char3->second)
                                            {
                                                if (num1 == num2 && num1 == num3)
                                                {
                                                    senha.push_back(num1);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    std::string resultado;
    for (int i = senha.size()-1; i >= 0; i--)
    {
        std::string str = std::to_string(senha[i]);
        resultado.insert(0, str);
        resultado.insert(0, " ");
    }
    resultado.erase(0, 1);

    return resultado;
}