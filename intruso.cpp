#include <iostream>
#include "intruso.hpp"

Intruso::Intruso(){
    
}
void Intruso::set_senha_vazada(std::string vazou){
    
    std::vector<int> numbers;
    std::string word = "";

    for(char i : vazou){

        if(int(i) >= 48 and int(i) <= 57)
            numbers.push_back(int(i) - 48);
        
        if(int(i) >= 65 and int(i) <=69)
            word+=i;

    }

    std::map<char, std::vector<int>> hash;

    for(int i=0; i<10 ;i++)
        hash[char((i+130)/2)].push_back(numbers[i]);
    
    _code.push_back(hash);

    _senhas.push_back(word);

}

std::string Intruso::crack_senha(){
    
    std::string answer = "";

    for(int i=0;i<5;i++){

        std::map<int,int> cont;

        for(int j=0;j<10;j++) cont[j] = 0;

        std::vector<char> letras;

        for(int j=0;j<_senhas.size();j++)
            letras.push_back(_senhas[j][i]);
        
        for(int j=0;j<_code.size();j++)
            for(int k : _code[j][letras[j]])
                cont[k]++;
        
        int right_number = 0;

        for(int j=0;j<10;j++)
            if(cont[j] > cont[right_number])
                right_number = j;
        
        answer += char(right_number + 65);

        
    }

    return answer;
}