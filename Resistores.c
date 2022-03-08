//Clayton B. de Sousa
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

/*Variaveis globais*/
double e_tensao1,e_tensao2,e_r1,e_r2,e_r3,s_equivalente1,s_corrente1,
		s_corrente2,s_corrente3,s_potencia1,s_vk1,s_vk2,s_vk3;

void desenha_circuito(int opcao){
	switch (opcao){
		case 1:
			printf("Circuito 1\n");
			printf("   ------| R1 |------------\n");
			printf("   |                |      |\n");
			printf("   |                |      |\n");
			printf("   |                _      _\n");
			printf("+_____ V            R2     R3\n");
			printf("- ---               _      _\n");
			printf("   |                |      |\n");
			printf("   |                |      |\n");
			printf("   ------------------------\n");
		break;
		
		case 2:
			printf("Circuito 2\n");
			printf("    --->                   <---\n");
			printf("     IR1                    IR2 \n");
			printf("   ------| R1 |-------| R2 |----\n");
			printf("   |              |             |\n");
			printf("   |              | --->        |\n");
			printf("   |              _  IR3        |\n");
			printf("+_____ V1         R3         +_____ V2 \n");
			printf("- ---             _          - ---\n");
			printf("   |              |             |\n");
			printf("   |              |             |\n");
			printf("   -----------------------------\n");
		break;
	}
}

/*Calcula a resistência de 2 resist em série*/
double em_serie(double r1, double r2){
	return r1 + r2;
}
/*Calcula a resistência de 2 resist em paralelo*/
double em_paralelo(double r1, double r2){
	return (1/((1/r1) + (1/r2)));
}
/*Calcula a corrente do circuito*/
double corrente_circuito(double volts, double resistencia){
	return (volts/resistencia);
}
/*Calcula a potencia do circuito*/
double potencia_circuito(double corrente, double tensao){
	return (corrente * tensao);
}
/*Queda de tensao resistor*/
double queda_tensao(double corrente, double resistencia){
	return (corrente * resistencia);
}
/*VKR2*/
double corrente_2(){
	return  0;
}
void le_valores(int opcao){
	desenha_circuito(opcao);
	switch (opcao){
		case 1:		
			printf("Entre com um valor de Tensao V: ");
			scanf("%lf",&e_tensao1);
			printf("Entre com um valor de R1: ");
			scanf("%lf",&e_r1);
			printf("Entre com um valor de R2: ");
			scanf("%lf",&e_r2);
			printf("Entre com um valor de R3: ");
			scanf("%lf",&e_r3);
			s_equivalente1 = em_serie(e_r1 ,em_paralelo(e_r2,e_r3));
			s_corrente1 = corrente_circuito(e_tensao1,s_equivalente1);
			s_potencia1 = potencia_circuito(s_corrente1,e_tensao1);
			printf("\nRESULTDOS\n");
			printf("Resistencia equivalente = %lf ohms\n",s_equivalente1);
			printf("Corrente = %lf A\n",s_corrente1);
			printf("Potencia = %lf W\n\n",s_potencia1);
		break;
		
		case 2:
			printf("Entre com um valor de Tensao V1: ");
			scanf("%lf",&e_tensao1);
			printf("Entre com um valor de Tensao V2: ");
			scanf("%lf",&e_tensao2);
			printf("Entre com um valor de R1: ");
			scanf("%lf",&e_r1);
			printf("Entre com um valor de R2: ");
			scanf("%lf",&e_r2);
			printf("Entre com um valor de R3: ");
			scanf("%lf",&e_r3);
			//Calculos Fonte V1
			s_equivalente1 = em_serie(e_r1 ,em_paralelo(e_r2,e_r3));
			s_corrente1 = corrente_circuito(e_tensao1,s_equivalente1);
			s_vk1 = queda_tensao(s_corrente1,e_r1);
			s_corrente2 = corrente_circuito((e_tensao1 - s_vk1),e_r2);
			s_corrente3 = corrente_circuito((e_tensao1 - s_vk1),e_r3);
			double s_it = s_corrente3;
			printf("\nRESULTADOS para Fonte %lf Volts\n",e_tensao1);
			printf("Req %lf ohms\nIt %lf A\nVKR1 %lf volts\nIR1 %lf A\nIR2 %lf A\nIR3 %lf A\n", 
				s_equivalente1,s_corrente1,s_vk1,s_corrente1,s_corrente2,s_corrente3);
			//Calculos Fonte V2
			s_equivalente1 = em_serie(e_r2 ,em_paralelo(e_r1,e_r3));
			s_corrente1 = corrente_circuito(e_tensao2,s_equivalente1);
			s_vk2 = queda_tensao(s_corrente1,e_r2);
			s_corrente2 = corrente_circuito((e_tensao2 - s_vk2),e_r1);
			s_corrente3 = corrente_circuito((e_tensao2 - s_vk2),e_r3);
			printf("\nRESULTADOS para Fonte %lf Volts\n",e_tensao2);
			printf("Req %lf ohms\nIt %lf A\nVKR2 %lf volts\nIR2 %lf A\nIR1 %lf A\nIR3 %lf A\n", 
				s_equivalente1,s_corrente1,s_vk2,s_corrente1,s_corrente2,s_corrente3);
			s_it = s_corrente3+s_it;
			if(s_it > 0){
				printf("Corrente Total em R3 = %lf A\n Saindo do noh",s_it);
			}else{
				s_it = s_it * (-1);
				printf("Corrente Total em R3 = %lf A\n Entrando no noh",s_it);
			}
			
			
		break;	
	}
}

int main(){
	printf("Vamos calcular a Resistencia equivalente\nPotencia e Corrente\nPara o circuito abaixo!\n");
	le_valores(1);
	le_valores(2);
	return 0;
}