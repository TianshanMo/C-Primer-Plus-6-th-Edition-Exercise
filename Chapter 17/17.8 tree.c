/* tree.c -- tree support functions */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "17.8 tree.h"

/* local data type */
typedef struct pair {
	Trnode * parent;
	Trnode * child;
} Pair;

/* protototypes for local functions */
static Trnode * MakeNode(const Item * pi);
static bool ToLeft(const Item * i1, const Item * i2);
static bool ToLeftDupl(const Item * i1, const Item * i2);
static bool ToRight(const Item * i1, const Item * i2);
static bool ToRightDupl(const Item * i1, const Item * i2);
static void AddNode(Trnode * new_node, Trnode * root);
static bool AddDupl(const Item * pi, List pl);
static void InOrder(const Trnode * root, void(*pfun)(List pl));
static Pair SeekItem(const Item * pi, const Tree * ptree);
static void DeleteNode(Trnode **ptr);
static void DeleteAllNodes(Trnode * ptr);

/* function definitions */
void InitializeTree(Tree * ptree)
{
	ptree->root = NULL;
	ptree->size = 0;
}

bool TreeIsEmpty(const Tree * ptree)
{
	if (ptree->root == NULL)
		return true;
	else
		return false;
}

bool TreeIsFull(const Tree * ptree)
{
	if (ptree->size == MAXITEMS)
		return true;
	else
		return false;
}

int TreeItemCount(const Tree * ptree)
{
	return ptree->size;
}

bool AddItem(const Item * pi, Tree * ptree)
{
	Trnode * new_node;
	Pair dupl;

	if (TreeIsFull(ptree))
	{
		fprintf(stderr, "Tree is full\n");
		return false;             /* early return           */
	}
	if ((dupl.child = SeekItem(pi, ptree).child) != NULL)
	{
		if (AddDupl(pi, dupl.child->head))
		{
			ptree->size++;
			return true;
		}
		else
		{
			fprintf(stderr, "Couldn't add duplicate pets\n");
			return false;
		}
	}
	new_node = MakeNode(pi);      /* points to new node     */
	if (new_node == NULL)
	{
		fprintf(stderr, "Couldn't create node\n");
		return false;             /* early return           */
	}
	/* succeeded in creating a new node */
	ptree->size++;

	if (ptree->root == NULL)       /* case 1: tree is empty  */
		ptree->root = new_node;    /* new node is tree root  */
	else                           /* case 2: not empty      */
		AddNode(new_node, ptree->root); /* add node to tree  */

	return true;                   /* successful return      */
}

bool InTree(const Item * pi, const Tree * ptree)
{
	Trnode * look;
	List plist;
	List temp;
	look = SeekItem(pi, ptree).child;
	if (look == NULL)
		return false;
	else
	{
		if (look->head->next != NULL)
		{
			plist = look->head;
			if (strcmp(pi->petkind, plist->item.petkind) == 0)
				return true;
			else
			{
				do
				{
					temp = plist;
					plist = plist->next;
					if (plist == NULL)
						return false;
				} while (strcmp(pi->petkind, plist->item.petkind) != 0);
				return true;
			}
		}
		else
		{
			plist = look->head;
			if (strcmp(pi->petkind, plist->item.petkind) == 0)
				return true;
			else
				return false;
		}
	}

}

bool DeleteItem(const Item * pi, Tree * ptree)
{
	Pair look;
	List plist;
	List temp;
	look = SeekItem(pi, ptree);

	if (InTree(pi, ptree))
	{
		if (look.child->head->next != NULL)
		{
			plist = look.child->head;
			if (strcmp(pi->petkind, plist->item.petkind) == 0)
			{
				look.child->head = plist->next;
				free(plist);
			}
			else
			{
				do
				{
					temp = plist;
					plist = plist->next;
				} while (strcmp(pi->petkind, plist->item.petkind) != 0);
				temp->next = plist->next;
				free(plist);
			}
		}
		else
		{
			if (look.child == NULL)
				return false;
			if (look.parent == NULL)     /* delete root item         */
				DeleteNode(&ptree->root);
			else if (look.parent->left == look.child)
				DeleteNode(&look.parent->left);
			else
				DeleteNode(&look.parent->right);
		}
		ptree->size--;
		return true;
	}
	else
		return false;
}

void Traverse(const Tree * ptree, void(*pfun)(List pl))
{
	if (ptree != NULL)
		InOrder(ptree->root, pfun);
	else
		printf("failure!\n");
}

void DeleteAll(Tree * ptree)
{
	if (ptree != NULL)
		DeleteAllNodes(ptree->root);
	ptree->root = NULL;
	ptree->size = 0;
}

/* local functions */
static void InOrder(const Trnode * root, void(*pfun)(List pl))
{
	if (root != NULL)
	{
		InOrder(root->left, pfun);
		(*pfun)(root->head);
		InOrder(root->right, pfun);
	}
}

static void DeleteAllNodes(Trnode * root)
{
	Trnode * pright;
	if (root != NULL)
	{
		pright = root->right;
		DeleteAllNodes(root->left);
		free(root);
		DeleteAllNodes(pright);
	}
}

static void AddNode(Trnode * new_node, Trnode * root)
{
	if (ToLeft(&(new_node->head->item), &(root->head->item)))
	{
		if (root->left == NULL)           /* empty subtree       */
			root->left = new_node;        /* so add node here    */
		else
			AddNode(new_node, root->left);/* else process subtree*/
	}
	else if (ToRight(&(new_node->head->item), &(root->head->item)))
	{
		if (root->right == NULL)
			root->right = new_node;
		else
			AddNode(new_node, root->right);
	}
	else                          /* should be no duplicates */
	{
		fprintf(stderr, "location error in AddNode()\n");
		exit(1);
	}
}

static bool AddDupl(const Item * pi, List pl)
{
	Lnode * pnew;
	Lnode * scan = pl;

	pnew = (Lnode *)malloc(sizeof(Lnode));
	if (pnew == NULL)
		return false;
	pnew->item = *pi;
	pnew->next = NULL;
	while (scan->next != NULL)
		scan = scan->next;
	scan->next = pnew;

	return true;
}

static bool ToLeft(const Item * i1, const Item * i2)
{
	int comp1;

	if ((comp1 = strcmp(i1->petname, i2->petname)) < 0)
		return true;
	return false;
}

static bool ToLeftDupl(const Item * i1, const Item * i2)
{
	int comp1;

	if ((comp1 = strcmp(i1->petname, i2->petname)) < 0)
		return true;
	else if (comp1 == 0 && strcmp(i1->petkind, i2->petkind) < 0)
		return true;
	else
		return false;
}

static bool ToRight(const Item * i1, const Item * i2)
{
	int comp1;

	if ((comp1 = strcmp(i1->petname, i2->petname)) > 0)
		return true;
	return false;
}

static bool ToRightDupl(const Item * i1, const Item * i2)
{
	int comp1;

	if ((comp1 = strcmp(i1->petname, i2->petname)) > 0)
		return true;
	else if (comp1 == 0 && strcmp(i1->petkind, i2->petkind) > 0)
		return true;
	else
		return false;
}

static Trnode * MakeNode(const Item * pi)
{
	Trnode * new_node;

	new_node = (Trnode *)malloc(sizeof(Trnode));
	if (new_node != NULL)
	{
		new_node->head = (Lnode *)malloc(sizeof(Lnode));
		if (new_node->head != NULL)
		{
			new_node->head->item = *pi;
			new_node->head->next = NULL;
			new_node->left = NULL;
			new_node->right = NULL;
		}
	}

	return new_node;
}

static Pair SeekItem(const Item * pi, const Tree * ptree)
{
	Pair look;
	look.parent = NULL;
	look.child = ptree->root;
	if (look.child == NULL)
		return look;                        /* early return   */

	while (look.child != NULL)
	{
		if (ToLeft(pi, &(look.child->head->item)))
		{
			look.parent = look.child;
			look.child = look.child->left;
		}
		else if (ToRight(pi, &(look.child->head->item)))
		{
			look.parent = look.child;
			look.child = look.child->right;
		}
		else       /* must be same if not to left or right    */
			break; /* look.child is address of node with item */
	}

	return look;                       /* successful return   */
}

static void DeleteNode(Trnode **ptr)
/* ptr is address of parent member pointing to target node */
{
	Trnode * temp;

	if ((*ptr)->left == NULL)
	{
		temp = *ptr;
		*ptr = (*ptr)->right;
		free(temp);
	}
	else if ((*ptr)->right == NULL)
	{
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
	else    /* deleted node has two children */
	{
		/* find where to reattach right subtree */
		for (temp = (*ptr)->left; temp->right != NULL;
			temp = temp->right)
			continue;
		temp->right = (*ptr)->right;
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
}