#include "Header.h"

int main()
{
	string expression = "9+(8*(7+(1+(6*(5+4)-(3-2)))))";
	Tree tree(expression);
	print_tree(tree);
	cout << "NLR: ";
	NLR(*tree.root);
	cout << endl;
	cout << "LNR: ";
	LNR(*tree.root);
	cout << endl;
	cout << "LRN: ";
	LRN(*tree.root);
	cout << endl;
}
