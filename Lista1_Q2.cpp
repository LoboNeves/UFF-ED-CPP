//Questão 2 - Fazer uma pilha com duas filas
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

//Criação da pilha, com suas variáveis e funções
class Stack{
  public:
    int N;
    QueueEnc f1;
    QueueEnc f2;
    void cria();
    void libera();
    char topo();
    void empilha(char dado);
    char desempilha();
};

//Definindo as funções separadamente

void Stack::cria(){
  this->N = 0;
  this->f1.cria();
  this->f2.cria();
}

void Stack::libera(){
    // nenhum recurso dinâmico para desalocar
}

char Stack::topo(){
    char x;
    if(this->f1.N > this->f2.N){
        for(int i = 0; i < this->N - 1; i++){
            this->f2.enfileira(this->f1.frente());
            this->f1.desenfileira();
        }
        x = this->f1.frente();
        this->f2.enfileira(x);
        this->f1.desenfileira();
        return x;
    }

    else{
        for(int i = 0; i < this->N - 1; i++){
            this->f1.enfileira(this->f2.frente());
            f2.desenfileira();
        }
        x = f2.frente();
        this->f1.enfileira(x);
        this->f2.desenfileira();
        return x;
    }
}

void Stack::empilha(char dado){
    if(this->N == 0){
        this->f1.enfileira(dado);
        this->N++;
    }

    else{
        if(this->f1.N > this->f2.N){
            this->f1.enfileira(dado);
            this->N++;
        }
        else{
            this->f2.enfileira(dado);
            this->N++;
        }
    } 
}

char Stack::desempilha(){
    char x;
    if(this->f1.N > this->f2.N){
        for(int i = 0; i < this->N - 1; i++){
            this->f2.enfileira(this->f1.frente());
            this->f1.desenfileira();
        }
        this->N--;
        x = this->f1.frente();
        this->f1.desenfileira();
        return x;
    }

    else{
        for(int i = 0; i < this->N - 1; i++){
            this->f1.enfileira(this->f2.frente());
            this->f2.desenfileira();
        }
        this->N--;
        x = this->f2.frente();
        this->f2.desenfileira();
        return x;
    }
}

//Programa principal
int main(){
    Stack p;
    p.cria();
    p.empilha('A');
    p.empilha('B');
    p.empilha('C');
    std::cout << p.topo() << std::endl;
    p.empilha('D');
    while(p.N > 0) std::cout << p.desempilha() << std::endl;
    p.libera();
    
    return 0;
}