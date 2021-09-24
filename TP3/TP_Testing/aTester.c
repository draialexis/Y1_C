#include<stdio.h>

/* Fonctions a tester */

void afficheBool(int b)
{
	if (b==0)
	{
		printf("Faux\n");
	}
	else if (b==1)
	{
		printf("Vrai\n");
	}
	else
	{
		printf("Ni 0, ni 1\n");
	}
}

int estPremier1(int n)
{
	if (n<2)
	{
		printf("Appel incorrect de estPremier1 sur %d\n", n);
		return -1;

	}
	else
	{
		return (n%2);
	}

}

int estPremier2(int n)
{
	if (n<2)
	{
		printf("Appel incorrect de estPremier2 sur %d\n", n);
		return -1;

	}
	else
	{
		switch(n)
		{
			case 2:
			case 3:
			case 5:
			case 7:
			case 11:
			case 13:
			case 17:
			case 19:
			case 23:
				return 1;
				break;
			default:
				return 0;
		}
	}
}

int maxTab1(int tab[], int n)
{
	int max=0;
	int i;
	for (i=0; i<n; i++)
	{
		if (tab[i]>max)
		{
			max=tab[i];
		}
	}
	
	return max;

}

int maxTab2(int tab[], int n)
{
	int max=tab[0];
	int i;
	for (i=1; i<n; i++)
	{
		if (tab[i]>max)
		{
			max=tab[i];
		}
	}
	
	return max;

}

int maxTab3(int tab[], int n)
{
	int max=tab[1];
	int i;
	for (i=1; i<n; i++)
	{
		if (tab[i]>max)
		{
			max=tab[i];
		}
	}
	
	return max;

}