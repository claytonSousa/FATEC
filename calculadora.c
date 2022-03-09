/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

double soma(double a, double b){
    return (a+b);
}
double subtracao(double a, double b){
    return (a-b);
}
double multiplicacao(double a, double b){
    return (a*b);
}
double divisao(double a, double b){
    return (a/b);
}

int main(){
    double a,b;
    char e_op = 'R';
    printf("CALCULADORA\n");
    while(e_op != 'S'){
        printf("Entre c/ primeiro numero: ");
        scanf("%lf",&a);
        printf("Entre c/ segundo numero: ");
        scanf("%lf",&b);
        printf("Entre c/ a operacao +,-,*,/ ou S para sair ");
        scanf("%c",&e_op);
        scanf("%c",&e_op);
    
        switch(e_op){
            case '+':
                printf("RESULTADO: %lf %c %lf = %lf\n",a,e_op,b,(soma(a,b)));
            break;
            case '-':
                printf("RESULTADO: %lf %c %lf = %lf\n",a,e_op,b,(subtracao(a,b)));
            break;
            case '*':
                printf("RESULTADO: %lf %c %lf = %lf\n",a,e_op,b,(multiplicacao(a,b)));
            break;
            case '/':
                if(b != 0){
                    printf("RESULTADO: %lf %c %lf = %lf\n",a,e_op,b,(divisao(a,b)));
                }else{
                    printf("11º Mandamente: Jamais Dividiras por ZERO\n");
                }
            break;
            case 'S':
            printf("FIM DA EXECUCAO\n");
            break;
            default:
                printf("ERRO de OPERACAO!");
        }
    }
    return 0;
}