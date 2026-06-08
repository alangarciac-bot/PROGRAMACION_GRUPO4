// PRÁCTICA ADICIONAL 2T
// Materia: Programación I
//Paralelo 4 
// Autor: Angel Jose Amaru Llojlla 
// Fecha creación: 27/05/2026

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Encontrar(vector<string>& a,vector<string>& b);
void ImprimirVector(const vector<string>& n);

int main ()
{
    system("cls");
    vector<string> listaA = {"Juan", "Maria", "Pedro", "Ana", "Luis"};
    vector<string> listaB = {"Ana", "Carlos", "Pedro", "Sofia", "Luis"};

    ImprimirVector(listaA);
    cout<<endl;
    ImprimirVector(listaB);
    cout<<endl;
    Encontrar(listaA,listaB);
    
    

    return 0;
}


void Encontrar(vector<string>& a,vector<string>& b)
{
    
    for(int i = 0; i < a.size(); i++)
    {
        for(int j = 0; j < b.size(); j++)
        {
            if (a[i] == b[j])
            {
                cout<<a[i]<<" ";
            }
            
    }
    cout<<endl;
    }
}

void ImprimirVector(const vector<string>& n)
{
    for(int i = 0; i < n.size(); i++)
        {cout << n[i] << ",";

        }
        cout<<endl;

}
