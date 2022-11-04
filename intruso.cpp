#include <iostream>
#include "intruso.hpp"

Intruso::Intruso(){
    
}
void Intruso::set_senha_vazada(std::string vazou){
    
    std::vector<char> numbers;
    std::string word = "";

    for(char i : vazou){

        if(int(i) >= 48 and int(i) <= 57)
            numbers.push_back(i);
        
        if(int(i) >= 65 and int(i) <=69)
            word+=i;

    }

    std::map<char, std::vector<char>> hash;

    for(int i=0; i<10 ;i++)
        hash[char((i+130)/2)].push_back(numbers[i]);
    
    
    _code.push_back(hash);

    _senhas.push_back(word);

}

std::string Intruso::crack_senha(){
    
    std::string answer = "";

    for(int i=0 ;i < 6; i++){

        
        std::map<char,int> qnt;

        char letter = '0';

        for(int j=48; j<58 ; j++)
            qnt[char(j)] = 0;
        
        
        for(int j=0;j < _senhas.size(); j++){

            for(char c : _code[j][_senhas[j][i]]){
                qnt[c]++;
                if(qnt[c] > qnt[letter])
                    letter = c;
            }   

        }

        answer += letter;
        answer += " ";
    }

    return answer;
}