#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
#include <random>
using namespace std;

/*
Exo 1 :
ecrire un programme qui effectue 4 operations add sous mult div
qui peut prendre int int / double double / float float mais aussi / int double / double int etc....

---------------------------------------------------------------------------------------------------

Exo 2 :
Cr�ez une fonction "trier" pour trier un tableau de 10 donn�es avec un tri par selection. 
Le tableau devra �tre de n'importe quel type. 
Cette fonction utilisera une autre fonction, "�changer", pour �changer les �l�ments du tableau.
*/

template <typename T, typename C> auto add(T num1, C num2)
{
    return num1 + num2;
}

template <typename T, typename C> auto sous(T num1, C num2)
{
    return num1 - num2;
}

template <typename T, typename C> auto mult(T num1, C num2)
{
    return num1 * num2;
}

template <typename T, typename C> auto divis(T num1, C num2)
{
    return num1 / num2;
}

// Exo 2

// Permet d'�changer 2 �l�ments
template <typename E> void echanger(E& el1, E& el2)
{
    E temp = el1;
    el1 = el2;
    el2 = temp;
}

// Permet de trier un tableau
template <typename T> T trier(T tableau, int size)
{
    int n = size - 1;
    int min;

    // Pour i allant de 0 � n-1
    for (int i = 0; i <= n-1; i++)
    {
        // min prend la valeur de i
        min = i;
         
        // Pour j allant de i+1 � n
        for(int j = i+1; j <= n; j++)
        {
            // Si tableau[j] est inf�rieur � tableau[min]
            if (tableau[j] < tableau[min])
            {
                // min prend la valeur de j
                min = j;

            }
        }

        // Si min est diff�rent de i
        if (min != i)
        {
            // �changer tableau[i] et tableau[min]
            echanger(tableau[i], tableau[min]);
        }
    }

    /*
    i = 3;
    min = 3;
    j = 4;

    tab[0] = 3;
    tab[1] = 4;
    tab[2] = 5;
    tab[3] = 10;
    tab[4] = 24;
    tab[5] = 20;
    tab[6] = 32;
    tab[7] = 8;
    tab[8] = 39;
    tab[9] = 47;
    */

    return tableau;
}

int main()
{
    // Exo 1
    /*int num1 = 10, num2 = 5;
    double num3 = 10.5, num4 = 5.5;
    float num5 = 10.3, num6 = 5.7;

    // cout << "Addition       : " << add(num1, num2) << endl;
    // cout << "Soustraction   : " << sous(num3, num1) << endl;
    // cout << "Multiplication : " << mult(num5, num6) << endl;
    // cout << "Division       : " << divis(num3, num4) << endl;
    cout << "Soustraction   : " << typeid(sous(3.8, 2)).name() << endl;
    cout << "Soustraction   : " << typeid(sous(3.2, 1.2)).name() << endl;
    cout << "Soustraction   : " << typeid(sous(3, 1)).name() << endl;*/

    // Exo 2
    int taille = 10;
    vector<int> tab, tabTrie;
    default_random_engine moteur(time(0));
    uniform_int_distribution<int> distribution{ 0, 50 };

    cout << "Exo 2"  << endl << endl << endl;

    // Initialisation des valeurs du tableau
    for (int i = 0; i <= taille-1; i++)
    {
        // Si la size est inf�rieure ou �gale � i, c'est qu'on rajoute un nouvel �l�ment
        // sinon c'est qu'on r��crit une valeur du tableau car d�j� pr�sente dans les �l�ments pr�c�dents
        if (tab.size() <= i)
        {
            // On donne une valeur al�atoire � la fin du tableau
            tab.push_back(distribution(moteur));
        }
        else
        {
            // On donne une valeur al�atoire � l'�l�ment i de notre tableau
            tab[i] = distribution(moteur);
        }

        // Pour chaque �l�ment pr�c�dent du tableau
        for (int j = 0; j < i; j++)
        {
            // On v�rifie si le nouvel �l�ment n'a pas la m�me valeur
            if (tab[i] == tab[j])
            {
                // Si c'est le cas, on refait un tirage pour notre �l�ment i
                i--;
                break;
            }
        }
    }

    // On affiche le tableau
    for (int i = 0; i <= taille-1; i++)
    {
        cout << "tab[" << i << "] = " << tab[i] << endl;
    }

    // On trie le tableau
    tabTrie = trier(tab, taille);

    cout << endl;

    // On affiche le tableau tri�
    for (int i = 0; i <= taille-1; i++)
    {
        cout << "tabTrie[" << i << "] = " << tabTrie[i] << endl;
    }

    system("pause");
    return 0;
}
