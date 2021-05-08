//Questão 7 - Notação Polonesa Reversa
#include <stdio.h>
#include <stack>
#include <queue>
#include <cstring>

int isOperator(char val){
    const char operatorsList[] = { '+', '-', '*', '/', '(', ')'};
    int isTrue = 0;
    
    for(int i = 0; i < 6; i++){
        if( val == operatorsList[i]){
            isTrue = 1;
        }    
    }
    
    return isTrue;
};

int main()
{
    const char *expression  = "((A+B)*(C-(F/D)))";
    
    std::stack <char> operators;
    std::queue <char> operands;
    
    int expressionSize = strlen(expression);
   
    for(int i = 0; i < expressionSize; i++){
        
        if(isOperator(expression[i])){
            switch(expression[i]){
                case '+':
                    if(!operators.empty() && (
                        operators.top() == '-' ||
                        operators.top() == '*' ||
                        operators.top() == '/' )){
                            
                            operands.push(operators.top());
                            operators.pop();
                        } else {
                            operators.push(expression[i]);
                        }
                break;
                
                case '-':
                    if(!operators.empty() && (
                        operators.top() == '+' ||
                        operators.top() == '*' ||
                        operators.top() == '/' )){
                            
                            operands.push(operators.top());
                            operators.pop();
                        } else {
                            operators.push(expression[i]);
                        }
                break;
                
                case '/':
                 if(!operators.empty() && operators.top() == '*'){
                            
                            operands.push(operators.top());
                            operators.pop();
                        } else {
                            operators.push(expression[i]);
                        }
                break;
                
                case '*':
                if(!operators.empty() && operators.top() == '/'){
                            
                            operands.push(operators.top());
                            operators.pop();
                        } else {
                            operators.push(expression[i]);
                        }
                break;
                
                case ')':
                    while( operators.top() != '('){
                        operands.push(operators.top());
                        operators.pop();
                    
                    }
                break;
                
                default: // case (
                    operators.push(expression[i]);
                break;
            }
        } 
        else operands.push(expression[i]);
    };
    
    while(operators.size() != 0){
        if(operators.top() != '(' && operators.top() != ')') operands.push(operators.top());
         
        operators.pop();
    };
    
    
    while(operands.size() != 0){
        printf("%c", operands.front());    
        operands.pop();
    };
    
    
    return 0;
};
