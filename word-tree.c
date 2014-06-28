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

void display(char *sw, struct node **leaf, char *prev) {
	char weak[5], strong[5], *w, *s;
	strcpy(weak, "w"); strcpy(strong, "s");
	w = weak; s = strong;

	if(leaf != 0) 
	{
		if(strcmp(prev, (*leaf)->word) == 0) 
		{
			if(strcmp(weak, sw) == 0) 
			{
				display(w, &(*leaf)->left, (*leaf)->word);
			}
			else if(strcmp(strong, sw) == 0) 
			{
				display(s, &(*leaf)->right, (*leaf)->word);
			} 
			else 
			{
			printf("Error!\n");
			}
		} 
		else 
		{
			if(strcmp(weak, sw) == 0) 
			{	
				printf("%s is weaker than %s\n", (*leaf)->word, prev);
			} 
			else 
			{
				printf("%s is stronger than %s\n", (*leaf)->word, prev);
			}
		display(w, &(*leaf)->left, (*leaf)->word);
		display(s, &(*leaf)->right, (*leaf)->word);
		}
	}
}

void search(char *word, char *sw, struct node **leaf) {
	if( leaf != 0 ) {
		if(strcmp(word, (*leaf)->word) == 0) {
			display(sw, &(*leaf), word);
		}
		else {
			search(word,sw, &(*leaf)->right);
			search(word,sw, &(*leaf)->left);
		}
	} 
}

int main() {
	char word_a[20], word_b[20], dir[5], *input, *word, *sw;
	input = word_a;
	word = word_b;
	sw = dir;
	int count = 5;
	struct node *root = 0;
	while(count > 0) {
		printf("Enter a word: ");
		scanf("%s", input);
		insert(input, &(root));
		count--;
	}
	printf("Word to find: ");
	scanf("%s", word);
	printf("Stronger or weaker? ");
	scanf("%s", sw);
	search(word, dir, &(root));
	return 0;
}