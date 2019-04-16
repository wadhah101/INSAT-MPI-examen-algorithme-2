#include <stdio.h>
#include <stdlib.h>


// les fonctions standards de la liste chainé 
struct node
{
  int val;
  struct node *next;
};
typedef struct node Node;
typedef Node *list;


void printlist(list l)
{
  if (l)
  {
    printf("%d ", l->val);
    printlist(l->next);
  } 
}

//retourne la tete d'une liste (avec un seul element) ayant X comme un valeur 
list createnode(int x)
{
  list l;
  l = (list)malloc(sizeof(node));
  l->val = x;
  l->next = NULL;
  return l;
}


//adjonction tete 
list adjt(list l, int e)
{
  if (!l)
  {
    l = createnode(e);
    return l;
  }
  list temp = createnode(e);
  temp->next = l;
  return temp;
}


//adjonction queue (fin de la list)
list adjq(list l, int e)
{
  if (!l)
    return adjt(l, e);
  else
    return adjt(adjq(l->next, e), l->val);
}


//lire  une liste de n entier 
//la liste passé doit etre initialement vide 
list readList(list l, int n)
{
  if (n)
  {
    int x;
    scanf("%d", &x);
    l = createnode(x);
    l->next = readList(l->next, n - 1);
  }
  else
    return l;
}


//EX1
typedef struct
{
  int p, a, b;
} triplet;

void printTriplet(triplet x)
{
  printf("PGCD = %d , a = %d , b = %d\n", x.p, x.a, x.b);
}


// type constructor 
// retourne un triplet (x,y,z) apartir de 3 entier x y z  
triplet ConstructTriplet(int p, int a, int b)
{
  triplet temp;
  temp.p = p;
  temp.a = a;
  temp.b = b;
  return temp;
}

// la fonction PGCD retourne le PGCD , la valeur de a et b tel que 
// PGCD(x,y) = ax + by 
triplet pgcd(int x, int y)
{

  //cas pgcd(x,y), /  y != 0 
  if (y)
  {
    // p = p 
    // a = b'
    // b = a' - b'(x/y)
    triplet pgcdOld = pgcd(y, x % y);
    triplet pgcdNew = ConstructTriplet(pgcdOld.p, pgcdOld.b, pgcdOld.a - 
      (pgcdOld.b *(x / y)));
    printf("x = %d, y= %d\n", x, y);
    printTriplet(pgcdNew);
    return pgcdNew;
  }
  else
  // cas pgcd(x,0)
    return ConstructTriplet(x, 1, 0);
}



//EX2

//fonction qui retourne 1 si l'entier n appartient a la liste 
//sinon elle retourne 0 
int SearchInt(list l, int n)
{
  // on peut utiliser  la condition (l->val > n) si et seulement si  pour les listes croissantes 
  if ((!l) || (l->val > n))
  // la liste vide ne contient pas aucun valeur   
    return 0;
  // on trouve l'entier 
  else if (l->val == n)
    return 1;
  else
  //l'appel recursive declance si la tete de liste ne contient pas la valeur recherche
  //on passe l'element suivant comme la tete et le traitement se repete 
    return SearchInt(l->next, n);
}

// retourne la liste fonction par l'intersection de l1 et l2
list intersection(list l1, list l2)
{
  // intersection d'une liste vide avec une liste quelconque est une liste vide 
  if (!l1 || !l2)
    return NULL;
  else if (SearchInt(l2, l1->val))
  {
    //si l'element contenue dans la tete de l1 est trouvé dans l2 
    // on retourne cet element lié a l'intersection de la reste de l1 avec l2 
    //de facon que le premier element (verifiant la condition) est lié au deuxieme ,
    // lié au troisieme..  etc , lié a derniere element contenant le vide (NULL) (condition 1) 
    return adjt(intersection(l1->next, l2), l1->val);
  }
  else
  //si tete de l1 n'existe pas dans l2 la resultat d'intersection des deux listes forcement ne contient pas cet element 
  //on repete le traitement avec l'element suivant  
  {
    return intersection(l1->next, l2);
  }
}



list Union(list l1, list l2)
{
  //l'union d'une vide avec une autre liste est la liste derniere 
  if (!l1)
    return l2;
  else if (!l2)
    return l1;
  //l'union le de l1 et l2 est le premier element de l1 (la tete) lié avec (la reste de l1 union  l2 )
  else if (l1->val < l2->val)
    return adjt(Union(l1->next, l2), l1->val);
  //meme principe precedent 
  else if (l2->val < l1->val)
    return adjt(Union(l1, l2->next), l2->val);
  //on compare les element seulement pour avoir une liste resultante trié (vue que l1 et l2 sont trié )
  else
    return adjt(Union(l1->next, l2->next), l2->val);

}

list Disinclude(list l1, list l2)
{
  //une liste vide privé d'une autre liste quelconque est une liste vide 
  if (!l1)
    return NULL;
  //une liste quelconque privé d'une liste vide est la soi-meme
  else if (!l2)
    return l1;
  //si tete de l1 ne trouve pas dans l2
  // on retourne le tete lié a la reste de l1 privé de l2  
  else if (!SearchInt(l2, l1->val))
    return adjt(Disinclude(l1->next, l2), l1->val);
  // sinon on retourne la reste de l1 privé de l2 
  else
    return Disinclude(l1->next, l2);
}

list diffsym(list l1, list l2)
{
  return Disinclude(Union(l1, l2), intersection(l1, l2));
}



int main()
{
  pgcd(524, 184);
  return 0;
}
