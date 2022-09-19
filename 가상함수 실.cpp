#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class node {
	char* name;
	class node* link;

public:
	~node() {
		delete[] name;
		delete[] link;
	}
	int getname(char* pname)
	{
		int i = 0; char c;
		while (((c = getchar()) != '\n') && c != EOF)
		{
			*(pname + i++) = c;
		}
		if (c == '\n')
			*(pname + i) = '\0';
		if (c == EOF)
			*pname = EOF;
		return *pname;
	}

	class node* addlist(class node* p, char* w)
	{
		if (p == NULL)
		{
			p = (class node*)malloc(sizeof(class node));
			p->name = namecopy(w);
			p->link = NULL;
		}
		else
			p->link = addlist(p->link, w);
		return p;
	}

	char* namecopy(char* s)
	{
		char* p; int i = 0;
		p = (char*)malloc(strlen(s) + 1);
		while ((*(p + i) = *(s + i)) != '\0')
			i++;
		return p;
	}

	void listprint(class node* p)
	{
		while (p != NULL)
		{
			printf("%s\n", p->name);
			p = p->link;
		}
	}

	class node* invert(class node* lead)
	{
		class node* trail, * middle;
		middle = NULL;

		while (lead != NULL)
		{
			trail = middle;
			middle = lead;
			lead = middle->link;
			middle->link = trail;
		}
		return middle;
	}
};

int main()
{
	class node* root;
	char name[80];
	root = NULL;
	while (root->getname(name) != EOF)
	{
		root = root->addlist(root, name);
	}
	root->listprint(root);

	root = root->invert(root);
	printf("------------invert-----------\n");
	root->listprint(root);

	return 0;
}