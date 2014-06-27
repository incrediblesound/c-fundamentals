#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	char word[20];
	struct node *left;
	struct node *right;
};

void insert(char *word, struct node **leaf) {
	char inpt[5], weak[5], strong[5];
	strcpy(weak, "w");
	strcpy(strong, "s");
	if(*leaf == 0) {
		*leaf = (struct node*) malloc ( sizeof (struct node) );
		strcpy((*leaf)->word, word);
		(*leaf)->left = 0;
		(*leaf)->right = 0;
	}
	else {
		printf("Is %s stronger(s) or weaker(w) than %s? ", word, (*leaf)->word);
		scanf("%s", inpt);
		if(strcmp(inpt, weak) == 0) {
			insert(word, &(*leaf)->left);
		}
		else if(strcmp(inpt, strong) == 0) {
			insert(word, &(*leaf)->right);
		} 
	}
}

/*int search(char *word, struct node *leaf) {

	if( leaf != 0 ) {
		if(word == leaf->word) {
			return leaf->word;
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
}*/

int main() {
	char word_a[20], *input;
	input = word_a;
	int count = 5;
	struct node *root = 0;
	while(count > 0) {
		printf("Enter a word: ");
		scanf("%s", input);
		insert(input, &(root));
		count--;
	}
	return 0;
}