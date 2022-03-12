#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


int main()
{
   

    char m[60];
    int i=0;

    cout<<"\t\t======================================================="<<endl<<
	      "\t\t=        Digite um conjunto de nomes:                 ="<<endl<<
		  "\t\t======================================================="<<endl<<
		  "Exemplo: Ana Maria Daniel"<<endl<<endl;
    fflush(stdin);
    gets(m);


    while (m[i] != '\0')
    {
        if(m[i] == ' ')
        {
            m[i] = '\n';
        }

        i++;
    }
    
    
    FILE *fp;
	fp = fopen("fich1.txt", "a");fclose(fp);//a para criar ficheiro
	fp = fopen("fich1.txt", "w");//abrir em w para começar a escrever no inicio do ficheiro
    i=0;

    if (fp != NULL)
    {
        for (; m[i]; i++)
        {
            fputc(m[i], fp);
        }
        cout<<endl<<endl<<"_________________________________________________________________________________________________________________"<<endl<<"Texto escrito com sucesso"<<endl<<endl;

        fclose(fp);
    }
    else
    {
        cout<<endl<<endl<<"_________________________________________________________________________________________________________________"<<endl<<"ERRO"<<endl<<endl;fclose(fp);
    }


    system("pause");
    return 0;}
