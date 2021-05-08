//Questão 5 Letra B- Inverter fila com duas filas
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

//Programa principal onde será feita a inversão
int main(){  
    QueueEnc fila1;
    QueueEnc fila2;
    QueueEnc fila3;

    fila1.cria();
    fila2.cria();
    fila3.cria();

    fila1.enfileira('A');
    fila1.enfileira('B');
    fila1.enfileira('C');

    int tamanho = fila1.N;
    int aux = 1;

    fila2.enfileira(fila1.frente());
    fila1.desenfileira();
    fila3.enfileira(fila1.frente());
    fila1.desenfileira();
    fila3.enfileira(fila2.frente());
    fila2.desenfileira();

    for(int i = 0; i < tamanho - 2; i++){
        if(fila2.N > fila3.N){
            fila3.enfileira(fila1.frente());
            fila1.desenfileira();

            for(int i = 0; i <= aux; i++){
                fila3.enfileira(fila2.frente());
                fila2.desenfileira();
            }
        
            aux++;
        }

        else{
            fila2.enfileira(fila1.frente());
            fila1.desenfileira();

            for(int i = 0; i <= aux; i++){
                fila2.enfileira(fila3.frente());
                fila3.desenfileira();
            }

            aux++;
        }
    }

    if(fila2.N > fila3.N){
        for(int i = 0; i < tamanho; i++){
            fila1.enfileira(fila2.frente());
            std::cout << fila2.frente() << std::endl;
            fila2.desenfileira();
        }
    } 

    else{
        for(int i = 0; i < tamanho; i++){
            fila1.enfileira(fila3.frente());
            std::cout << fila3.frente() << std::endl;
            fila3.desenfileira();
        }

    }

    fila1.libera();
    fila2.libera();
    fila3.libera();

    return 0;
}