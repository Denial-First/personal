#pragma once
#include <iostream>
#include <string>
using namespace std;

const char operators[] = {'+', '-', '*', '/'};

struct Node
{
	char symbol;
	Node* left;
	Node* right;
	Node();
	Node(char);
	void init(char);
};


struct Tree
{
	Node* root;
	Tree(string);
};


class Stack
{
	int top;
	
public:
	Stack();
	void push(char value);
	char pop();
	char* first;
};

void print_tree(string line);
bool operator_check(char symbol);
bool parentheses_check(string line, int num);
Node build_tree(string line);
int levels(Node* node);
void print_tree(Node* node, int space);
void print_tree(Tree tree);
void AddElement(Node*&, string);

