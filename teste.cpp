#include <iostream>
#include <stdio.h>
#include <queue>

class Fila {
  public:
  int N;                   
  std::queue<char> fila1; 
  
  void cria(){
    this->N = 0;
  };
  void libera(){};
  char frente(){
    return fila1.front();
  };
  void enfileira(char dado){
   fila1.push(dado);
   this->N++;
  };
  char desenfileira(){
    char r = fila1.front();
    fila1.pop();
    this->N--;
   return r;
  };
};

int main()
{
  Fila fila1;
  Fila fila2;
  Fila fila3;

  fila1.cria();
  fila2.cria();
  fila3.cria();
  
  
  int aux = 1;
  
  fila1.enfileira('A');
  fila1.enfileira('B'); 
  fila1.enfileira('C');
  fila1.enfileira('D');
  fila1.enfileira('E');

  int limite = fila1.N;
  
  fila2.enfileira(fila1.desenfileira());
  fila3.enfileira(fila1.desenfileira());
  fila3.enfileira(fila2.desenfileira());
  

  for(int i = 0; i < limite - 2; i++){
      
    if(fila2.N > fila3.N){
      
      fila3.enfileira(fila1.desenfileira());
      
      for(int i = 0; i <= aux; i++){
        fila3.enfileira(fila2.desenfileira());
      };
      
      aux++;
      
    } else {
      
      fila2.enfileira(fila1.desenfileira());
      
      for(int i = 0; i <= aux; i++){
        fila2.enfileira(fila3.desenfileira());
      };
      aux++;
 
    };
  };

  if(fila2.N > fila3.N){
        for(int i = 0; i < limite; i++){
            fila1.enfileira(fila2.frente());
            std::cout << fila2.frente() << std::endl;
            fila2.desenfileira();
        }
    } 

    else{
        for(int i = 0; i < limite; i++){
            fila1.enfileira(fila3.frente());
            std::cout << fila3.frente() << std::endl;
            fila3.desenfileira();
        }

    }

  return 0;
}





