#include <stdio.h>
#include <stdlib.h>

struct node
{
	int key_value;
	struct node *left;
	struct node *right;
};

void insert(int key, struct node **leaf) {
	if(*leaf == 0) {
		*leaf = (struct node*) malloc ( sizeof (struct node) );
		(*leaf)->key_value = key;
		(*leaf)->left = 0;
		(*leaf)->right = 0;
	}
	else if(key < (*leaf)->key_value) {
		insert(key, &(*leaf)->left);
	}
	else if(key > (*leaf)->key_value) {
		insert(key, &(*leaf)->right);
	}
}

int search(int key, struct node *leaf) {

	if( leaf != 0 ) {
		if(key == leaf->key_value) {
			return leaf->key_value;
		}
		else if(key < leaf->key_value) {
			return search(key, leaf->left);
		}
		else {
			return search(key, leaf->right);
		}
	} else {
		return 0;
	}
}

int main() {

	struct node *root = 0;
	insert(5, &(root));
	insert(3, &(root));
	insert(2, &(root));
	insert(7, &(root));
	printf("%i\n", search(7, root));
}