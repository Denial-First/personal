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
	//void init(char);
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

bool operator_check(char symbol);
bool parentheses_check(string line, int num);
void print_tree(Node* node, int space);
void print_tree(Tree tree);
void AddElement(Node*&, string);
void NLR(Node node);
void LNR(Node node);
void LRN(Node node);
