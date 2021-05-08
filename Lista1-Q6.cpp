//Questão 6 - Função ObterMin()
#include <iostream>

//Criação da pilha com o dado e o endereço do próximo
class NoStack{
    public:
        char dado;
        NoStack* prox;
};

//Criação da pilha para encadear, com suas váriaveis e funções
class StackEnc{
    public:
        NoStack* inicio;
        int N;
        void cria();
        void libera();
        char topo();
        void empilha(char dado);
        char desempilha();
        char ObterMinimo();
};

//Definindo as funções de StackEnc separadamente
void StackEnc::cria(){
    this->N = 0;
    this->inicio = 0;
}

void StackEnc::libera(){
    while(this->N > 0){
        NoStack* p = this->inicio->prox;
        delete this->inicio;
        this->inicio = p;
        this->N--;
    }
}

char StackEnc::topo(){
    return this->inicio->dado;
}

void StackEnc::empilha(char x){
    auto* no = new NoStack{.dado = x, .prox = this->inicio};
    this->inicio = no;
    this->N++;
}

char StackEnc::desempilha(){
    NoStack* p = this->inicio->prox;
    char r = this->inicio->dado;
    delete this->inicio;
    this->inicio = p;
    this->N--;
    return r;
}

char StackEnc::ObterMinimo(){
    NoStack* no = this->inicio->prox;
    char menor = this->inicio->dado;

    for(int i = 0; i < this->N - 1; i++){

        if(no->dado < menor) menor = no->dado;

        no = no->prox;
    }

    return menor;
}

//Programa principal
int main(){
    StackEnc p1;
    p1.cria();
    p1.empilha('1');
    p1.empilha('2');
    p1.empilha('3');      
    std::cout << p1.ObterMinimo() << std::endl;
    p1.libera();
    return 0;
}