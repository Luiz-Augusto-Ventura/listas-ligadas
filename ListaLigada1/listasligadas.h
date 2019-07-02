#include <iostream>
using namespace std;

struct no
{
	int info;
	no *prox;
};

void insereIn(no **L, int X)
{
	no *AUX = new no;
	AUX->info = X;
	AUX->prox=*L;
	*L = AUX;
}

void insereFi(no **L, int X)
{
	no *AUX = new no;
	AUX->info = X;
	AUX->prox=NULL;
	if (*L == NULL)
	{
		*L = AUX;
	}
	else
	{
		no *Q = *L;
		while (Q->prox != NULL)
		{
			Q = Q->prox;
		}
		Q->prox = AUX;
	}
}

int removePri(no **L)
{
	if (*L != NULL)
	{
		no *AUX = *L;
		*L = (*L)->prox;
		int X = AUX->info;
		delete AUX;
		return X;
	}
}

int removeUlt(no **L)
{
	if (*L != NULL)
	{
		no *Q = *L;
		if (Q->prox == NULL)
		{
			int X = Q->info;
			delete Q;
			*L = NULL;
			return X;
		}
		else
		{
			while (Q->prox->prox != NULL)
			{
				Q = Q->prox;
			}
			int X = Q->prox->info;
			delete(Q->prox);
			Q->prox = NULL;
			return X;
		}
	}
}

int contaOcorrencia(no **L,int X)
{
	if (*L != NULL)
	{
		no *Q = *L;
		int Y=0;
		while (Q != NULL)
		{
			if (Q->info == X)
			{
				Y++;
			}
			Q = Q -> prox;
		}
		if (Y > 0)
			return Y;
		else
			return -1;
	}
}

int removDeterminado(no **L, int X)
{
	if (*L != NULL)
	{
		no *Q = *L;
		if (Q->info == X)
		{
			*L = (*L)->prox;
			delete Q;
			return 1;
		}
		else
		{
			while ((Q->prox != NULL) && (Q->prox->info != X))
				Q = Q->prox;
			if (Q->prox->info == X)
			{
				no *AUX = Q->prox;
				Q->prox = AUX->prox;
				delete(AUX);
				return 1;
			}
			else
				return 0;
		}
	}
}

void removTodos(no **L)
{
	no *Q = *L;
	delete Q;
	*L = NULL;
}

void mostra(no *L)
{
	if (L != NULL)
	{
		cout << "[";
		while (L != NULL)
		{
			cout << L->info;
			if (L->prox != NULL)
			{
				cout << ",";
			}
			L = L->prox;
		}
		cout << "]";
	}
}

int maiorElemento(no *L)
{
	if (L)
	{
		int mae=L->info;
		L = L->prox;
		while (L)
		{
			if (L->info > mae)
				mae = L->info;
			L = L->prox;
		}
		return mae;
	}
}

float mediaAritmetica(no *L)
{
	if (L)
	{
		int soma=0;
		int ne=0;	
		float m;
		while (L)
		{
			soma += L->info;
			ne++;
			L = L->prox;
		}
		m = (float)soma / ne;
		return m;
	}
}

void inverteLista(no **L)
{
	if (*L)
	{
		no *Q = *L;
		no *prox = NULL;
		no* anter = NULL;
		while (Q)
		{
			prox = Q->prox;
			Q->prox = anter;
			anter=Q;
			Q = prox;
		}
		*L = anter;
	}
}

char empty(no *L)
{
	return L == NULL;
}
