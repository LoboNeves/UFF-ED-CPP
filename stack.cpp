#include <iostream>
using namespace std;
constexpr int MAXN = 100;

//Criação da pilha, com suas variáveis e funções
class Stack{
    public:
        char elementos[MAXN];
        int N;
        void cria(); 
        void libera();
        char topo();
        void empilha(char dado);
        char desempilha();
};

//Definindo as funções separadamente
void Stack::cria(){
    this->N = 0;
}

void Stack::libera(){
    // nenhum recurso dinâmico para desalocar
}

char Stack::topo(){
    return this->elementos[N-1];
}

void Stack::empilha(char dado){
    this->elementos[N] = dado;
    this->N++;
}

char Stack::desempilha(){
    this->N--;
    return this->elementos[N];
}

//Programa principal
int main(){
    Stack p;
    p.cria();
    p.empilha('A');
    p.empilha('B');
    p.empilha('C');
    cout << p.topo() << endl;
    cout << p.desempilha() << endl;
    p.empilha('D');
    while(p.N > 0) cout << p.desempilha() << endl;
    p.libera();
    return 0;
}