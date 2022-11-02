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
    
    for(int i=65;i<70;i++){
        //std::cout<<char(i)<<": ";
        //for(char c : hash[char(i)])
            //std::cout<<c<<" ";
    }

    //std::cout<<std::endl;
    _code.push_back(hash);

    _senhas.push_back(word);

}

std::string Intruso::crack_senha(){
    
    std::string answer = "";

    for(int i=0;i<6;i++){

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
        
        answer += char(right_number + 48);

        
    }

    return answer;
}