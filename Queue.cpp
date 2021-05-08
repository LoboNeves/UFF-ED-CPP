/* #include <iostream>
using namespace std;
constexpr int MAXN = 100;

//Criação da fila, com suas variáveis e funções
class Queue{
    public:
        char elementos[MAXN];
        int N;
        void cria(); 
        void libera();
        char frente();
        void enfileira(char dado);
        char desenfileira();
};

//Definindo as funções separadamente
void Queue::cria(){
    this->N = 0;
}

void Queue::libera(){
    // nenhum recurso dinâmico para desalocar
}

char Queue::frente(){
    return this->elementos[0];
}

void Queue::enfileira(char dado){
    this->elementos[N] = dado;
    this->N++;
}

char Queue::desenfileira(){
    char r = this->elementos[0];
    for(int i = 0; i<N-1; i++) this->elementos[i] = this->elementos[i+1];
    this->N--;
    return r;
}

//Programa principal
int main(){
    Queue p;
    p.cria();
    p.enfileira('A');
    p.enfileira('B');
    p.enfileira('C');
    cout << p.frente() << endl;
    cout << p.desenfileira() << endl;
    p.enfileira('D');
    while(p.N > 0) cout << p.desenfileira() << endl;
    p.libera();
    return 0;
}

//Metódo 2: sem realocação de elementos da fila a cada remoção

#include <iostream>
using namespace std;
constexpr int MAXN = 100;

//Criação da fila, com suas variáveis e funções
class Queue{
    public:
        char elementos[MAXN];
        int N;
        int inicio;
        int fim;
        void cria(); 
        void libera();
        char frente();
        void enfileira(char dado);
        char desenfileira();
};

//Definindo as funções separadamente
void Queue::cria(){
    this->N = 0;
    this->inicio = 0;
    this->fim = 0;
}

void Queue::libera(){
    // nenhum recurso dinâmico para desalocar
}

char Queue::frente(){
    return this->elementos[inicio];
}

void Queue::enfileira(char dado){
    this->elementos[fim] = dado;
    this->fim++;
    this->N++;
}

char Queue::desenfileira(){
    char r = this->elementos[inicio];
    this->inicio++;
    this->N--;
    return r;
}

//Programa principal
int main(){
    Queue p;
    p.cria();
    p.enfileira('A');
    p.enfileira('B');
    p.enfileira('C');
    cout << p.frente() << endl;
    cout << p.desenfileira() << endl;
    p.enfileira('D');
    while(p.N > 0) cout << p.desenfileira() << endl;
    p.libera();
    return 0;
}
*/

//Metódo 3: estratégia circular

#include <iostream>
using namespace std;
constexpr int MAXN = 100;

//Criação da fila, com suas variáveis e funções
class Queue{
    public:
        char elementos[MAXN];
        int N;
        int inicio;
        int fim;
        void cria(); 
        void libera();
        char frente();
        void enfileira(char dado);
        char desenfileira();
};

//Definindo as funções separadamente
void Queue::cria(){
    this->N = 0;
    this->inicio = 0;
    this->fim = 0;
}

void Queue::libera(){
    // nenhum recurso dinâmico para desalocar
}

char Queue::frente(){
    return this->elementos[inicio];
}

void Queue::enfileira(char dado){
    this->elementos[fim] = dado;
    this->fim = (fim + 1) % MAXN; //Linha que muda para o metódo 3
    this->N++;
}

char Queue::desenfileira(){
    char r = this->elementos[inicio];
    this->inicio = (inicio + 1) % MAXN; //Linha que muda para o metódo 3
    this->N--;
    return r;
}

//Programa principal
int main(){
    Queue p;
    p.cria();
    p.enfileira('A');
    p.enfileira('B');
    p.enfileira('C');
    cout << p.frente() << endl;
    cout << p.desenfileira() << endl;
    p.enfileira('D');
    while(p.N > 0) cout << p.desenfileira() << endl;
    p.libera();
    return 0;
}