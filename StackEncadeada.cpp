#include <iostream>
using namespace std;

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

//Programa principal
int main(){
    StackEnc p1;
    p1.cria();
    p1.empilha('A');
    p1.empilha('B');
    p1.empilha('C');
    cout << p1.topo() << endl;
    cout << p1.desempilha() << endl;
    p1.empilha('D');
    while(p1.N > 0) cout << p1.desempilha() << endl;
    p1.libera();
    return 0;
}