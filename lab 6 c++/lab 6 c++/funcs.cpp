#include "Header.h"


void Stack::push(char value)
{
	first[top++] = value;
}


Stack::Stack()
{
	top = 0;
	first = new char[100];
}


char Stack::pop()
{
	if (top > 0)
		return first[--top];
	else
		return 0;
}


Node::Node()
{
	symbol = NULL;
	left = NULL;
	right = NULL;
}


//void Node::init(char symbol)
//{
//	this->symbol = symbol;
//}


Node::Node(char value)
{
	symbol = value;
	left = NULL;
	right = NULL;
}


bool operator_check(char symbol)
{
	for (int i = 0; i < 4; i++)
	{
		if (symbol == operators[i])
			return true;
	}
	return false;
}


bool parentheses_check(string line, int num)
{
	Stack stack;
	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] == '(')
			stack.push('(');
		else if (line[i] == ')')
			stack.pop();
		if (i == num)
		{
			if (stack.pop() == 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}


Tree::Tree(string expression)
{
	root = new Node;
	AddElement(root, expression);
}


void AddElement(Node*& node, string line)
{
	if (line.length() == 1)
	{
		node = new Node(line[0]);
		return;
	}
	else
	{
		if (line[0] == '(' && line[line.length() - 1] == ')')	
		{														
			line.erase(0, 1);
			line.erase(line.length() - 1, 1);
		}
		bool check = true;
		for (int i = 0; i < line.length(); i++)
		{
			if ((line[i] == '+' || line[i] == '-') && parentheses_check(line, i))		//9+(8*(7+(1+(6*(5+4)-(3-2)))))
			{
				check = false;
				node = new Node(line[i]);
				AddElement(node->left, line.substr(0, i));
				AddElement(node->right, line.substr(i + 1, 123123));
				return;
			}
		}
		if (check)
		{
			for (int i = 0; i < line.length(); i++)
			{
				if ((line[i] == '*' || line[i] == '/') && parentheses_check(line, i))
				{
					node = new Node(line[i]);
					AddElement(node->left, line.substr(0, i));
					AddElement(node->right, line.substr(i + 1, line.length() - i - 1));
					return;
				}
			}
		}
	}
}


void print_tree(Node* node, int space) 
{
	if (node == NULL) return;
	print_tree(node->right, ++space);
	for (int i = 1; i < space; i++) 
	{
		cout << '\t';
	}
	cout << node->symbol << endl;
	print_tree(node->left, space);
}

void print_tree(Tree tree) 
{
	cout << "________________________________________\n";
	cout << endl;
	print_tree(tree.root, 0);
	cout << "________________________________________\n";
}


void NLR(Node node)
{
	cout << node.symbol << " ";
	if (node.left != NULL && node.right != NULL)
	{
		cout << "(";
		NLR(*node.left);
		NLR(*node.right);
		cout << ")";
	}
}


void LNR(Node node)
{
	bool check = false;
	if (node.left != NULL && node.right != NULL)
	{
		if (isdigit(node.left->symbol))
		{
			cout << "(";
			check = true;
		}
		LNR(*node.left);
	}
	cout << node.symbol;
	if (node.left != NULL && node.right != NULL)
	{
		LNR(*node.right);
		if (check)
			cout << ")";
	}
}


void LRN(Node node)
{
	if (node.left != NULL && node.right != NULL)
	{
		cout << "(";
		LRN(*node.left);
		LRN(*node.right);
		cout << ")";
	}
	cout << node.symbol << " ";
}

