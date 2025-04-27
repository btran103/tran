struct Person
{
	string name;
	int yearOfBirth;
};
struct BFT 
{	
	Person data;
	BFT *left, *right;
};

//create a node
BFT* createNode(Person p, BFT* left, BFT* right)
{
return new BFT{p, left, right};
}
//a)create the specify BFT
BFT* createBFT()
{
BFT *n1, *n2, *n3, *n4, *n5, *n6;
n1 = createNode({"Nguyen D", 1960}, nullptr, nullptr);
n2 = createNode({"Nguyen B", 1930}, nullptr, n1);
n3 = createNode({"Nguyen E", 1965}, nullptr, nullptr);
n4 = createNode({"Nguyen F", 1970}, nullptr, nullptr);
n5 = createNode({"Nguyen C", 1935}, n3, n4);
n6 = createNode({"Nguyen A", 1900}, n2, n5);
return n6;
}

//b)prints a binary family tree in a pre-order traversal
void printBFT(BFT* root)
{
if (root)
{
cout << root->data.name << " " << root->data.yearOfBirth << endl;
printBFT(root->left);
printBFT(root->right);
}
}

//c)count persons in BFT
int countPersons(BFT* root)
{
if (!root) return 0;
return 1 + countPersons(root->left) + countPersons(root->right);
}

//d)height of BFT
int height(BFT* root)
{
if (!root) return 0;
return 1 + max(height(root->left), height(root->right));
}

//e)Count the number of people whose birth year is less than a specific
year
int countPersonsLessThan(BFT* root, int year)
{
if (!root) return 0;
else
if (root->data.yearOfBirth < year)
return countPersonsLessThan(root->left, year) +
countPersonsLessThan(root->right, year)+1;
else
return 0;
}

//f)find a person in BFT by name
BFT* findPerson(BFT* root, string name)
{
if (!root) return nullptr;
if (root->data.name == name) return root;
BFT* left = findPerson(root->left, name);
if (left) return left;
return findPerson(root->right, name);
}

//g)check pName is parent of cName
bool isParent(BFT* root, string pName, string cName)
{
BFT* parent;
parent = findPerson(root, pName);
if (!parent)
return false;
else
return (parent->left && parent->left->data.name==cName) ||
(parent->right && parent->right->data.name==cName);
}

//h)Give the name of attribute x which is in the tree.
int levelOfPerson(BFT* root, string name)
{
	if(!root) return 0;
	else if(root->data.name == name) return 1;
	else 
	{
		int h1,h2;
		h1 = count(root->left);
		h2 = count(root->right);
		if(h1!=0)
		{
			return levelOfPerson(h1,name)+1;
		}
		else if(h2!=0)
		{
			return levelOfPerson(h2,name)+1;
		}
		else 
		{
			return 0;
		}
	}
}
//i)Check if person named y is a descendant of person named x?
bool isDescendants(BFT* root, string x, string y)
{
	BFT* uncle;
	uncle = findPerson(root,x)
	if(uncle == nullptr)
	return false;
	
	BFT* child
	child = findPerson(root,y)
	if(child == nullptr)
	return false;
	
	BFT* Persons(BFT* uncle,BFT* child)
	if(child=nullptr)
	return false;
	else if(uncle==child)
	return true;
	else 
	return 0;
}
//j) List all descendants of person named x.
void printDescendants(BFT* root, string x)
{
	BFT* uncle;
	uncle=findPerson(root,x)
	if(!uncle)
	cout << x;
	else if(uncle==)
	
}	
	
	
	







int main()
{
BFT *root, *result;
root = createBFT();
printBFT(root);
cout << "Number of persons in BTS is: " << countPersons(root) <<
endl;
cout << "Height of BTS is: " << height(root) << endl;
result = findPerson(root, "Nguyen E");
if (result)

{
cout << result->data.name <<" "<<result->data.yearOfBirth<< endl;
}
else
cout << "Not found!";
cout << "Number person YOB < 1965 is: " <<
countPersonsLessThan(root, 1965) << endl;
string pName = "Nguyen B", cName = "Nguyen E";
bool chk = isParent(root, pName, cName);
if (chk)
cout << pName << " is parent of " << cName << endl;
else
cout << pName << " is not parent of " << cName << endl;
return 0;
}
