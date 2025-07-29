#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Portuguese");
	
	int j, peca, sem, valor = 0, numIng = 0, valorTotal = 0, totalIngressos = 0;
	char cpeca[3], csem[3];
	char *semana, *nomePeca;
	char caminho[30];
	char arquivo[25] = "BancoDados.txt";
	char pArq[40][10];
	FILE *arquivoDados;
	
	for (peca=1; peca<3; peca++)
	{
		if (peca == 1) nomePeca = "Shakespeare   \t ";
		if (peca == 2) nomePeca = "Musical da Broadway ";
		
		printf("Peça %sVendidos / Arrecadado\n\n", nomePeca);
		
		for (sem=1; sem<8; sem++)
		{
			
			switch(sem)
			{
				case 1: semana = "Domingo, 02-Dez-2018\t";break;
				case 2: semana = "Segunda-feira, 03-Dez-2018";break;
				case 3: semana = "Terça-feira, 04-Dez-2018";break;
				case 4: semana = "Quarta-feira, 05-Dez-2018";break;
				case 5: semana = "Quinta-feira, 06-Dez-2018";break;
				case 6: semana = "Sexta-feira, 07-Dez-2018";break;
				case 7: semana = "Sábado, 08-Dez-2018\t";break;
				default:printf("Escolha um dia da semana válido!"); exit(1);
			}
			
			sprintf(cpeca, "%d", peca);
			sprintf(csem, "%d", sem);
			
			strcat(caminho, cpeca);
			strcat(caminho, csem);
			strcat(caminho, arquivo);
			
			arquivoDados = fopen(caminho, "r");
			
			for(j=0; j<40; j++)
			{
				fscanf(arquivoDados, "%s", pArq[j]);
			}
			fscanf(arquivoDados, "%d", &valor);
			fscanf(arquivoDados, "%d", &numIng);
			
			printf("%s \t", semana);
			printf("%d / ", numIng); //Ingressos vendidos: 
			printf("%d\n", valor); //Total arrecadado: 
			
			totalIngressos += numIng;
			valorTotal += valor;
			
			strcpy(caminho, "");
		}
		printf("\n**********************************************************\n\n");
	}
	printf("Ingressos vendidos : %d\n", totalIngressos);
	printf("Total arrecadado: %d\n\n", valorTotal);
	system("pause");
	
	return 0;
}
