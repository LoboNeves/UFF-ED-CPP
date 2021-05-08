//Questão 4 Letra B- Inverter pilha com duas pilhas
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

//Programa principal onde será feita a inversão
int main(){  
    StackEnc pilha1;
    StackEnc pilha2;
    StackEnc pilha3;


    pilha1.cria();
    pilha2.cria();
    pilha3.cria();

    pilha1.empilha('A');
    pilha1.empilha('B');
    pilha1.empilha('C');

    int tamanho = pilha1.N;

    for(int i = 0; i < tamanho; i++){
        pilha2.empilha(pilha1.topo());
        pilha1.desempilha();
    }   

    for(int i = 0; i < tamanho; i++){
        pilha3.empilha(pilha2.topo());
        pilha2.desempilha();
    }

    for(int i = 0; i < tamanho; i++){
        pilha1.empilha(pilha3.topo());
        pilha3.desempilha();
        std::cout << pilha1.topo() << std::endl;
    }

    pilha1.libera();
    pilha2.libera();
    pilha3.libera();

    return 0;
}