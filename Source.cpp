class binarysearchtree {
private:
	struct node
	{
		int data;
		node* left;
		node* right;
	};

	node* root;

	void clear(node* &r)
	{
		if (r == NULL)
		{
			return;
		}
		else
		{
			clear(r->left);
			clear(r->right);
		}
		delete r;
	}

	node* insert(node* r, int n)
	{

		if (r == NULL)
		{
			r = new node;
			r->data = n;
			r->left = NULL;
			r->right = NULL;
		}
		else if (n > r->data)
		{
			r->right = insert(r->right, n);
		}
		else
		{
			r->left = insert(r->left, n);
		}
		return r;
	}
	
	node* deletegiven(node* r, int n)
	{
		if (r == NULL)
		{
			return NULL;
		}
		else if (n > r->data)
		{
			r->right = deletegiven(r->right, n);
		}
		else if (n < r->data)
		{
			r->left = deletegiven(r->left, n);
		}
		else
		{
			if (r->left == NULL && r->right == NULL)
			{
				delete r;
				r = NULL;
			}
			else if (r->left != NULL && r->right == NULL)
			{
				node* temp = r;
				r = r->left;
				delete temp;
			}
			else if (r->left == NULL && r->right != NULL)
			{
				node* temp = r;
				r = r->right;
				delete temp;
			}
			else
			{
				node* temp = r->right;
				while (temp->left != NULL)
				{
					temp = temp->left;
				}
				temp->left = r->left;
				temp = r;
				r = r->right;
				delete temp;
			}

		}

		return r;
	}
	
	node* findlargest(node* r)
	{
		if (r->right == NULL)
		{
			return r;
		}
		else
		{
			return findlargest(r->right);
		}

	}
	

	node* findsmallest(node* r)
	{
		if (r->left == NULL)
		{
			return r;
		}
		else
		{
			return findsmallest(r->left);
		}
	}

	void printinorder(node* r)
	{
		if (r != NULL)
		{
			printinorder(r->left);
			cout << r->data << " ";
			printinorder(r->right);
		}
		else
		{
			return;
		}
	}

	void find(node* r, int v)
	{
		if (r == NULL)
		{
			cout << "not found";
		}
		else if (r->data == v)
		{
			cout << "found";
		}
		else if (v < r->data)
		{
			return find(r->left, v);
		}
		else
		{
			return find(r->right, v);
		}
	}

public:
	binarysearchtree()
	{
		root = NULL;
	}

	~binarysearchtree()
	{
		clear(root);
	}

	void insert(int n)
	{
		root = insert(root, n);
	}

	void deletegiven(int n)
	{
		root = deletegiven(root, n);
	}

	void clear()
	{
		clear(root);
	}

	void findsmallest()
	{
		findsmallest(root);
	}

	void displaylargest()
	{
		findlargest(root);
	}

	void printinorder()
	{
		printinorder(root);
	}

	void find(int n)
	{
		find(root, n);
	}

	
};
