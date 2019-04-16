/* This source has been formatted by an unregistered SourceFormatX */
/* If you want to remove this info, please register this shareware */
/* Please visit http://www.textrush.com to get more information    */

/* This source has been formatted by an unregistered SourceFormatX */
/* If you want to remove this info, please register this shareware */
/* Please visit http://www.textrush.com to get more information    */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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


int SearchInt(list l, int n)
{
  if ((!l) || (l->val > n))
    return 0;
  else if (l->val == n)
    return 1;
  else
    return SearchInt(l->next, n);
}

//EX1
//iterative
int InverseInt(int n)
{
  int n2 = 0;
  while (n)
  {
    n2 = (n2 *10) + (n % 10);
    n = n / 10;
  }
  return n2;
}


int length(int n)
{
  if (n)
  {
    return 1+(length(n / 10));
  }
}


//recursive
int InverseIntRec(int n)
{
  if (n)
  {
    return ((n % 10) *pow(10, length(n / 10)) + InverseIntRec(n / 10));
  }
  return n;
}

//EX2

//1
int ListIncluded(list L1, list L2)
{
  list nav = L2->next;
  //le vide est inclus dans tout les listes
  if (!L1)
    return 1;
  else if (!L2)
  //le vide ne contient aucune liste 
    return 0;
  // si tete l1 est dans l2 on refait le traitement avec la reste de l1
  else if (SearchInt(L2, L1->val))
    return ListIncluded(L1->next, L2);
  else
    return 0;
}

//2
list DeleteNegativeNodes(list l)
{
  if (!l)
    return l;
  else if (l->val < 0)
  {
    list temp = l->next;
    free(l);
    //si la tete < 0 on retourne la reste de liste 
    return DeleteNegativeNodes(temp);
  }
  else
  //sinon on retourne la tete lie a la reste de liste sans valeur negative 
    return adjt(DeleteNegativeNodes(l->next), l->val);
}

//EX3 
// retourne une liste qui ne contient aucun 'n'
list DeleteElement(list l, int n)
{
  if (!l)
    return l;
  else if (l->val == n)
  {
    list temp = l->next;
    free(l);
    return DeleteElement(temp, n);
  }
  else
    return adjt(DeleteElement(l->next, n), l->val);
}


//retourne une liste qui contient l'entier n au max une fois 
list listUniqe(list l, int n)
{
  if (!l)
  {
    return NULL;
  }
  else if (l->val == n)
  {
    //si on trouve n  la fonction retourne l'element contenant n , lie a une liste sans aucun 'n' 
    return adjt(DeleteElement(l->next, n), n);
  }
  else
  //sinon on passe a l'element suivant 
    return adjt(listUniqe(l->next, n), l->val);
}

//Fonction principale 
//une liste redondance simple ayant comme valeur dans la tete 'n', est une liaison entre la tete
// et la reste de la liste avec redondance simple et contient n au max une fois (listeUnique n)
list redondanceSimple(list l)
{
  if (!l)
    return NULL;
  else
    return adjt(redondanceSimple(listUniqe(l->next, l->val)), l->val);
}


int main()
{
  list l1;
  // lire 10 element dans l1;
  l1 = readList(l1, 10);
  l1 = DeleteNegativeNodes(l1);
  printf("\n");
  printlist(l1);
  return 0;
}
