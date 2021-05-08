//Questão 5 Letra A- Inverter fila com uma pilha
#include <iostream>

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
    QueueEnc fila;
    StackEnc pilha;
    
    fila.cria();
    pilha.cria();

    fila.enfileira('A');
    fila.enfileira('B');
    fila.enfileira('C');

    int tamanho = fila.N;

    for(int i = 0; i < tamanho; i++){
        pilha.empilha(fila.frente());
        fila.desenfileira();
    }

    for(int i = 0; i < tamanho; i++){
        fila.enfileira(pilha.topo());
        std::cout << pilha.topo() << std::endl;
        pilha.desempilha();
    }

    fila.libera();
    pilha.libera();

    return 0;
}