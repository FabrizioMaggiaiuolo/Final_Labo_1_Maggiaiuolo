#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
	LinkedList* this;
    this = (LinkedList*) malloc (sizeof(LinkedList));
    this->pFirstNode = NULL;
    this->size = 0;
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* index;

	int contador;
	contador = 0;

	Node* pNodoAuxiliar;

	index = NULL;

	if(this != NULL && this->size > nodeIndex && nodeIndex >= 0)
	{

		pNodoAuxiliar = this->pFirstNode;

		while(contador<nodeIndex && pNodoAuxiliar->pNextNode != NULL)
		{
			pNodoAuxiliar = pNodoAuxiliar->pNextNode;
			contador++;
		}
		index = pNodoAuxiliar;
	}


    return index;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;

    Node* nodeNuevo;
    Node* nodoAuxiliar;

    if(this != NULL && nodeIndex <= ll_len(this) && 0 <= nodeIndex )
	{
    	nodeNuevo = (Node*) malloc (sizeof(Node));
    	nodeNuevo->pElement = pElement;
    	nodeNuevo->pNextNode = NULL;

    	if(nodeIndex != 0)
    	{
			nodoAuxiliar = getNode(this, nodeIndex-1);

			if(nodoAuxiliar != NULL)
			{
				nodeNuevo->pNextNode = nodoAuxiliar->pNextNode;
				nodoAuxiliar->pNextNode = nodeNuevo;
			}

    	}
    	else
    	{
    		nodeNuevo->pNextNode = this->pFirstNode;
    		this->pFirstNode = nodeNuevo;
    	}

    	this->size++;
    	returnAux = 0;
	}

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = addNode(this, ll_len(this), pElement);
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux;
    returnAux = NULL;

    if(this != NULL && index <= ll_len(this) && index >= 0)
   {
    	Node* nodo;

    	nodo = getNode(this, index);

    	if(nodo != NULL)
    	{
    		void* pElement;

    		pElement = nodo->pElement;

			returnAux = pElement;
    	}
   }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;

    if(this != NULL && index <= ll_len(this) && index >= 0)
    {
    	Node* nodoDevuelto;
    	nodoDevuelto = getNode(this, index);
    	if(nodoDevuelto != NULL)
    	{
    		nodoDevuelto->pElement = pElement;
			returnAux = 0;
    	}
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;

    if(this != NULL && index <= this->size && index >= 0)
    {
    	Node* nodo;
		nodo = getNode(this, index);

		if(nodo != NULL)
		{
			if(index == 0)
			{
				this->pFirstNode = nodo->pNextNode;
			}
			else
			{
				Node* nodoAnterior;
				nodoAnterior = getNode(this, index-1);
				if(nodoAnterior != NULL)
				{
					nodoAnterior->pNextNode = nodo->pNextNode;
				}
			}

			free(nodo);
			this->size--;
			returnAux = 0;
		}
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	while(ll_len(this) > 0)
    	{
    		ll_remove(this, 0);
    	}
    	returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
	{
		returnAux = ll_clear(this);
		if(returnAux == 0)
		{
			free(this);
		}
	}

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
		void* auxiliar;

		for(int i = 0; i < ll_len(this); i++)
		{
			auxiliar = ll_get(this, i);
			if(auxiliar == pElement)
			{
				returnAux = i;
				break;
			}
		}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = 1;

    	if(ll_len(this) != 0)
    	{
    		returnAux = 0;
    	}

    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && index <= ll_len(this) && index >= 0)
    {
    	addNode(this, index, pElement);
    	returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this != NULL && index <= ll_len(this)&& index >= 0)
    {
    	Node* nodo;
    	nodo = getNode(this, index);

    	if(nodo != NULL)
    	{
    		returnAux = nodo->pElement;
    		ll_remove(this, index);
    	}
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = 0;

    	if(ll_indexOf(this, pElement) != -1)
    	{
    		returnAux = 1;
    	}

    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;

    int existe;

    void* aux;

    if(this != NULL && this2 != NULL)
    {
    	returnAux = 1;

    	for(int i = 0; i<ll_len(this2) ;i++)
    	{
    		aux = ll_get(this2, i);

    		if(aux != NULL)
    		{
    			existe = ll_contains(this, aux);

				if(existe == 0)
				{
					returnAux = 0;
					break;
				}
    		}

    	}

    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    void* auxiliar;

    if(this != NULL && from >= 0 && from < ll_len(this) && to > from && to <= this->size)
    {
    	cloneArray = ll_newLinkedList();

    	for(int i = from; i < to;i++)
    	{
    		auxiliar = ll_get(this, i);
    		if(auxiliar != NULL)
    		{
    			ll_add(cloneArray, auxiliar);
    		}
    	}
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
    	 cloneArray = ll_subList(this, 0, this->size);
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux;
    returnAux = -1;

    if(this != NULL && (order == 1 || order == 0) && pFunc != NULL)
    {

    	if(order == 0)
    	{
    		order = -1;
    	}

    	void* aux1;
    	void* aux2;

    	int retorno;

    	for(int i = 0;i<ll_len(this)-1;i++)
    	{
			for(int j = i+1; j<ll_len(this);j++)
			{
				aux1 = ll_get(this, i);
				aux2 = ll_get(this, j);

				if(aux1 != NULL && aux2 != NULL)
				{

					retorno = pFunc(aux1,aux2);

					if(order == retorno)
					{
						ll_set(this, i, aux2);
						ll_set(this, j, aux1);
						returnAux = 0;
					}
					else
					{
						ll_set(this, i, aux1);
						ll_set(this, j, aux2);
						returnAux = 1;
					}

				}
				else
				{
					break;
				}
			}
    	}
    }

    return returnAux;

}

/** \brief Filtra los elementos de la lista utilizando la funcion fn
 * \param pList LinkedList* Puntero a la lista
 * \param fn Puntero a la funcion criterio (1 si cumple - 0 si NO cumple)
 * \return lista de elementos que cumplen el criterio de fn
 */
LinkedList* ll_filter(LinkedList* this, int (*fn)(void*))
{

	LinkedList* listaResultado = ll_newLinkedList();

	if(this != NULL && fn != NULL)
	{
		void* aux;

		int retorno;

		for(int i = 0;i<ll_len(this);i++)
		{
			aux = ll_get(this, i);
			if(aux != NULL)
			{
				retorno = fn(aux);
				if(retorno == 1)
				{
					ll_add(listaResultado, aux);
				}

			}
			else
			{
				break;
			}
		}
	}

	return listaResultado;
}

/** \brief Modifica elementos de la lista que cumplan el criterio de fn
 * \param pList LinkedList* Puntero a la lista
 * \param fn Puntero a la funcion criterio y modificacion (1 si cumple - 0 si NO cumple)
 * \return 0 si la lista o fn es NULL - 1 si se pudo realizar
 */
LinkedList* ll_map(LinkedList* this, void (*fn)(void*))
{
	LinkedList* newList;
	newList = ll_clone(this);

	if(this != NULL && fn != NULL)
	{
		void* auxNew;

		for(int i = 0; i<ll_len(this);i++)
		{
			auxNew = ll_get(newList, i);

			if(auxNew != NULL)
			{
				fn(auxNew);
			}
		}
	}
	return newList;
}

/** \brief Cuenta los elemntos que cumplen el criterio de la funcion fn
 * \param pList LinkedList* Puntero a la lista
 * \param fn Puntero a la funcion criterio (1 si cumple - 0 si NO cumple)
 * \return cantidad de elementos que cumplen el criterio - -1 si la lista o la funcion es NULL
 */
int ll_count(LinkedList* this, int (*fn)(void*))
{
	int retorno;
	retorno = -1;
	if(this != NULL && fn != NULL)
	{
		void* aux;

		int respuesta;

		int contador;
		contador = 0;

		for(int i = 0; i<ll_len(this);i++)
		{
			aux = ll_get(this, i);
			if(aux != NULL)
			{
				respuesta = fn(aux);
				if(respuesta == 1)
				{
					contador++;
				}
			}
		}

		retorno = contador;
	}
	return retorno;
}
