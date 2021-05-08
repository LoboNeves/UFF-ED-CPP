#include <iostream>
using namespace std;
constexpr int MAXN = 100;

//Criação do deque, com suas variáveis e funções
class Deque{
    public:
        char elementos[MAXN];
        int inicio;
        int fim;
        void cria(); 
        void libera();
        char buscaInicio();
        char buscaFim();
        void insereInicio(char dado);
        void insereFim(char dado);
        char removeInicio();
        char removeFim();
};

//Definindo as funções separadamente
void Deque::cria(){
    this->inicio = -1;
    this->fim = 0;
}

void Deque::libera(){
    // nenhum recurso dinâmico para desalocar
}

char Deque::buscaInicio(){
    return this->elementos[inicio+1];
}

char Deque::buscaFim(){
    return this->elementos[fim-1];
}

void Deque::insereInicio(char dado){
    this->elementos[inicio] = dado;
    this->inicio--;
}

void Deque::insereFim(char dado){
    this->elementos[fim] = dado;
    this->fim++;
}

char Deque::removeInicio(){
    this->inicio++;
    return this->elementos[inicio];
}

char Deque::removeFim(){
    this->fim--;
    return this->elementos[fim];
}

//Programa principal(Testando cada função)
int main(){
    Deque d;
    d.cria();
    d.insereFim('A');
    d.insereFim('B');
    d.insereFim('C');
    d.insereInicio('1');
    d.insereInicio('2');
    d.insereInicio('3');
    cout << d.buscaFim() << endl;
    cout << d.buscaInicio() << endl;
    cout << d.removeFim() << endl;
    cout << d.removeInicio() << endl;
    d.insereFim('D');
    d.insereInicio('4');
    while(d.fim > 0) cout << d.removeFim() << endl;
    while(d.inicio < -1) cout << d.removeInicio() << endl;
    d.libera();
    return 0;
}