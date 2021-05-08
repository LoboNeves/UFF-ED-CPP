#include <iostream>

//Criação do deque com o dado e o endereço do próximo
class NoDeque{
    public:
        char dado;
        NoDeque* prox;
};

//Criação do deque para encadear, com suas váriaveis e funções
class DequeEnc{
    public:
        NoDeque* inicio;
        NoDeque* fim;
        int Nfim;
        int Ninicio;
        void cria();
        void libera();
        char buscaInicio();
        char buscaFim();
        void insereInicio(char dado);
        void insereFim(char dado);
        char removeInicio();
        char removeFim();
};

//Definindo as funções de DequeEnc separadamente
void DequeEnc::cria(){
    this->Nfim = 0;
    this->Ninicio = 0;
    this->inicio = 0;
    this->fim = 0;
}

void DequeEnc::libera(){
    while(this->Nfim > 0){
        NoDeque* p = this->fim->prox;
        delete this->fim;
        this->fim = p;
        this->Nfim--;
    }

    while(this->Ninicio > 0){
        NoDeque* p = this->inicio->prox;
        delete this->inicio;
        this->inicio = p;
        this->Nfim--;
    }
}

char DequeEnc::buscaInicio(){
    return this->inicio->dado;
}

char DequeEnc::buscaFim(){
    return this->fim->dado;
}

void DequeEnc::insereInicio(char x){
    auto* no = new NoDeque{.dado = x, .prox = this->inicio};
    this->inicio = no;
    this->Ninicio++;
}

void DequeEnc::insereFim(char x){
    auto* no = new NoDeque{.dado = x, .prox = this->fim};
    this->fim = no;
    this->Nfim++;
}

char DequeEnc::removeInicio(){
    NoDeque* p = this->inicio->prox;
    char r = this->inicio->dado;
    delete this->inicio;
    this->inicio = p;
    this->Ninicio--;
    return r;
}

char DequeEnc::removeFim(){
    NoDeque* p = this->fim->prox;
    char r = this->fim->dado;
    delete this->fim;
    this->fim = p;
    this->Nfim--;
    return r;
}

//Programa principal(Testando cada função)
int main(){
    DequeEnc d;
    d.cria();
    d.insereFim('A');
    d.insereFim('B');
    d.insereFim('C');
    d.insereInicio('1');
    d.insereInicio('2');
    d.insereInicio('3');
    std::cout << d.buscaFim() << std::endl;
    std::cout << d.buscaInicio() << std::endl;
    std::cout << d.removeFim() << std::endl;
    std::cout << d.removeInicio() << std::endl;
    d.insereFim('D');
    d.insereInicio('4');
    while(d.Nfim > 0) std::cout << d.removeFim() << std::endl;
    while(d.inicio > 0) std::cout << d.removeInicio() << std::endl;
    d.libera();
    return 0;
}