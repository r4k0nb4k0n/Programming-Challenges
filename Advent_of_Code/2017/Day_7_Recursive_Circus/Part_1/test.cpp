#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> lines;

string trim(const string& s){
   if(s.length() == 0)
       return s;

   size_t beg = s.find_first_not_of(" \a\b\f\n\r\t\v");
   size_t end = s.find_last_not_of(" \a\b\f\n\r\t\v");
   if(beg == string::npos) // No non-spaces
       return "";

   return string(s, beg, end - beg + 1);
}

class Node{
private:
	string name;
public:
	Node* parent;
	Node(){
		name = "undefined";
		parent = nullptr;
	}
	Node(string& _name){
		name = _name;
		parent = nullptr;
	}
	string getName(){
		return name;
	}
};

class Tree{
private:
	vector<Node*> nodeList;
public:
	Tree(){
		
	}
	Node* findNodeByName(string name){
		for(int i=0; i<nodeList.size(); i++){
			if((nodeList[i]->getName()).compare(name) == 0){
				return nodeList[i];
			}
		}
		return nullptr;
	}
	Node* lastNode(){
		return nodeList[nodeList.size()-1];
	}
	void addNode(string name){
		Node n = Node(name);
		nodeList.push_back(&n);
	}
};

Tree tree = Tree();

int main(){
	ifstream file("input.txt");
	if (file.is_open()) {
    	string line;
    	while (getline(file, line)) {
    	    lines.push_back(trim(line));
    	}
    	file.close();
	}
	
	for(string line : lines){
		string parent = line.substr(0, line.find('(')-1);
		tree.addNode(parent);
		Node* p = tree.lastNode();
		vector<string> children;
		if(line.find('-') != string::npos){
			string listOfChildren = line.substr(line.find('-')+3);
			do{
				children.push_back(listOfChildren.substr(0, listOfChildren.find(",")));
				listOfChildren = listOfChildren.substr(listOfChildren.find(",")+2);
			}while(listOfChildren.find(",") != string::npos);
			children.push_back(trim(listOfChildren));
		}
		for(string child : children){
			tree.addNode(child);
			Node* n = tree.lastNode();
			n->setParent(p);
		}
	}
	
	Node* spotlight = tree.lastNode();
	Node* above = spotlight->getParent();
	
	while(above != nullptr){
		spotlight = above;
		above = spotlight->getParent();
	}
	
	cout << spotlight->getName() << "\n";
	
	return 0;
}