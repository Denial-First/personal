#include "Header.h"

int main()
{
	string expression = "9+(8*(7+(1+(6*(5+4)-(3-2)))))";
	Tree tree(expression);
	print_tree(tree);
}
