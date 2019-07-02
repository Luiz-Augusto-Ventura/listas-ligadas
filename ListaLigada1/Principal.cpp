#include <iostream>
#include "listasligadas.h"

using namespace std;

int OP,X;
no *L1 = NULL;

void main()
{
	do
	{
		system("CLS");
		cout << "=======================Listas Ligadas======================" << endl;
		cout << "1. Insere no Inicio" << endl;
		cout << "2. Insere no Final" << endl;
		cout << "3. Remove o Primeiro" << endl;
		cout << "4. Remove o Ultimo" << endl;
		cout << "5. Conta o numero de ocorrencias de um determinado elemento" << endl;
		cout << "6. Remove um determinado elemento da lista" << endl;
		cout << "7. Maior elemento da lista" << endl;
		cout << "8. Media aritmetica dos elementos da lista" << endl;
		cout << "9. Apaga todos os elementos da lista" << endl;
		cout << "10. Inverte os elementos da lista" << endl;
		cout << "11. Sair" << endl;
		cout << "===========================================================" << endl;
		cout << "Lista:";
		mostra(L1);
		cout << endl << "===========================================================" << endl;
		cout << "Sua opcao:";
		cin >> OP;
		switch (OP)
		{
		case 1:
			cout << "Elemento: ";
			cin >> X;
			insereIn(&L1, X);
			break;
		case 2:
			cout << "Elemento: ";
			cin >> X;
			insereFi(&L1, X);
			break;
		case 3:
			if (!empty(L1))
			{
				cout << "Elemento removido: " << removePri(&L1) << endl;
				system("pause");
			}
			break;
		case 4:
			if (!empty(L1))
			{
				cout << "Elemento removido: " << removeUlt(&L1) << endl;
				system("pause");
			}
			break;
		case 5:
			if (!empty(L1))
			{
				cout << "Elemento: ";
				cin >> X;
				if (contaOcorrencia(&L1, X) > 0)
				{
					cout << "Elemento repete " << contaOcorrencia(&L1, X) << " vezes" << endl;
					system("pause");
				}
				else
				{
					cout << "Elemento nao encontrado" << endl;
					system("pause");
				}
			}
			break;
		case 6:
			if (!empty(L1))
			{
				cout << "Elemento: ";
				cin >> X;
				if (removDeterminado(&L1, X) > 0)
				{
					cout << "Elemento removido" << endl;
					system("pause");
				}
				else
				{
					cout << "Elemento nao encontrado" << endl;
					system("pause");
				}
			}
			break;
		case 7:
			if (!empty(L1))
			{
				cout << "Maior elemento: " << maiorElemento(L1) << endl;
				system("pause");
			}
			break;
		case 8:
			if (!empty(L1))
			{
				cout << "Media dos elementos: " << mediaAritmetica(L1) << endl;
				system("pause");
			}

			break;
		case 9:
			removTodos(&L1);
			break;
		case 10:
			if (!empty(L1))
			{
				inverteLista(&L1);
			}
			break;
		default:
			break;
		}
	} while (OP != 11);
}