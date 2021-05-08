#include <iostream>
using namespace std;

//Criação da fila com o dado e o endereço do próximo
class NoQueue{
    public:
        char dado;
        NoQueue* prox;
};

//Criação da fila para encadear, com suas váriaveis e funções
class QueueEnc{
    public:
        NoQueue* inicio;
        NoQueue* fim;
        int N;
        void cria();
        void libera();
        char frente();
        void enfileira(char dado);
        char desenfileira();
};

//Definindo as funções de QueueEnc separadamente
void QueueEnc::cria(){
    this->N = 0;
    this->inicio = 0;
    this->fim = 0;
}

void QueueEnc::libera(){
    while(this->N > 0){
        NoQueue* p = this->inicio;
        inicio = inicio->prox;
        delete p;
        this->N--;
    }
}

char QueueEnc::frente(){
    return this->inicio->dado;
}

void QueueEnc::enfileira(char x){
    NoQueue* no = new NoQueue{.dado = x, .prox = 0};
    if(N == 0){inicio=fim=no;}
    else{fim->prox = no; fim = no;}
    this->N++;
}

char QueueEnc::desenfileira(){
    NoQueue* p = this->inicio;
    inicio = inicio->prox;
    char r = p->dado;
    delete p;
    this->N--;
    return r;
}

//Programa principal
int main(){
    QueueEnc f1;
    f1.cria();
    f1.enfileira('A');
    f1.enfileira('B');
    f1.enfileira('C');
    cout << f1.frente() << endl;
    cout << f1.desenfileira() << endl;
    f1.enfileira('D');
    while(f1.N > 0) cout << f1.desenfileira() << endl;
    f1.libera();
    return 0;
}