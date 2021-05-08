//Questão 3 - Fazer uma fila com duas pilhas
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

//Criação da fila, com suas variáveis e funções
class Queue{
  public:
    int N;
    StackEnc p1;
    StackEnc p2;
    void cria(); 
    void libera();
    char frente();
    void enfileira(char dado);
    char desenfileira();
};

//Definindo as funções separadamente

void Queue::cria(){
  this->N = 0;
  this->p1.cria();
  this->p2.cria();
}

void Queue::libera(){
    // nenhum recurso dinâmico para desalocar
}

char Queue::frente(){
    char x;
    for(int i = 0; i < this->N - 1; i++){
        this->p2.empilha(this->p1.topo());
        this->p1.desempilha();
    }

    x = this->p1.topo();
    this->p2.empilha(this->p1.topo());
    this->p1.desempilha();

    for(int i = 0; i < this->N; i++){
        this->p1.empilha(this->p2.topo());
        this->p2.desempilha();
    }

    return x;
}

void Queue::enfileira(char dado){
    this->p1.empilha(dado);
    this->N++;
}

char Queue::desenfileira(){
    char x;
    for(int i = 0; i < this->N - 1; i++){
        this->p2.empilha(this->p1.topo());
        this->p1.desempilha();
    }

    x = this->p1.topo();
    this->p1.desempilha();
    this->N--;
    
    for(int i = 0; i < this->N; i++){
        this->p1.empilha(this->p2.topo());
        this->p2.desempilha();
    }
    return x;
}

//Programa principal
int main(){
    Queue f;
    f.cria();
    f.enfileira('A');
    f.enfileira('B');
    f.enfileira('C');
    std::cout << f.frente() << std::endl;
    f.enfileira('D');
    while(f.N > 0) std::cout << f.desenfileira() << std::endl;
    f.libera();
    
    return 0;
}
