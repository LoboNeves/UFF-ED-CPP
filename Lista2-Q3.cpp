//Questão 3 - Criação e operações com árvore binária
#include <iostream>
//Criação do nó da árvore, com seu valor e os endereços dos seus filhos
class No{
    public:
        int valor;
        No* esq;
        No* dir;
};

//Criação da árvore com o dado e o endereço da raiz
class Arvore{
    public:
        No* raiz;
};

//Funções
int add = 0;  //Váriaveis usadas para as funções de soma e multiplicação dos nós
int mult = 1;
int nivel = 1;

int soma(No* no){
    if(no){
        add += no->valor;
        soma(no->esq);
        soma(no->dir);
    }
    return add;
}

void posordem(No* no){
    if(no){
        posordem(no->esq);
        posordem(no->dir);
        std::cout << no->valor << " ";
    }
}

void emordem(No* no){
    if(no){
        emordem(no->esq);
        std::cout << no->valor << " ";
        emordem(no->dir);
    }
}

void preordem(No* no){
    if(no){
        std::cout << no->valor << " ";
        preordem(no->esq);
        preordem(no->dir);
    }
}

int produto(No* no){
    if(no){
        mult *= no->valor;
        produto(no->esq);
        produto(no->dir);
    }
    return mult;
}

int main(){
    //Árvore usada:
    //         20
    //     10      15
    //   4    7  8    3
    // 1  2

    //Montando a árvore:
    No* no1 = new No{.valor = 1, .esq = 0, .dir = 0};
    No* no2 = new No{.valor = 2, .esq = 0, .dir = 0};
    No* no4 = new No{.valor = 4, .esq = no1, .dir = no2};
    No* no7 = new No{.valor = 7, .esq = 0, .dir = 0};
    No* no10 = new No{.valor = 10, .esq = no4, .dir = no7};
    No* no8 = new No{.valor = 8, .esq = 0, .dir = 0};
    No* no3 = new No{.valor = 3, .esq = 0, .dir = 0};
    No* no15 = new No{.valor = 15, .esq = no8, .dir = no3};
    No* no20 = new No{.valor = 20, .esq = no10, .dir = no15};

    Arvore ArvoreExemplo{.raiz = no20};

    //Questão A: Somar as folhas
    std::cout << "A soma eh: " << soma(ArvoreExemplo.raiz) << std::endl;
    std::cout << std::endl;

    //Questão B: Percurso de pós ordem
    std::cout << "Percurso de pos-ordem:" << std::endl;
    posordem(no20);
    std::cout << std::endl << std::endl;

    //Questão C: Percurso de em ordem
    std::cout << "Percurso de em-ordem:" << std::endl;
    emordem(no20);
    std::cout << std::endl << std::endl;

    //Questão D: Percurso de pré ordem
    std::cout << "Percurso de pre-ordem:" << std::endl;
    preordem(no20);
    std::cout << std::endl << std::endl;

    //Questão H: Produto das folhas
    std::cout << "O produto eh: " << produto(ArvoreExemplo.raiz) << std::endl;
    std::cout << std::endl;

    return 0;
}