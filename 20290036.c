

/// QUTAIBA ALASHQAR, 20290036;
/// DATA STRUCURE, LAB_8;


#include<stdio.h>
#include<stdlib.h>


int size = 50;
int list_of_tree[50];

int null_value = NULL;

char LLL = ('L');
char RRR = ('R');
char BBB = ('B');
char random_str = ('A');


struct Tree{

	struct Tree *left;
	int index1;
	int height;
    int parent;
	int balance;
    char charr;
	struct Tree *right;
};


int height();
int maximum(int, int);

struct Tree *function_right();
struct Tree *function_left();

int function_balance();

struct Tree *function_insert(struct Tree *AVL_tree, int, int, char);

void function_orderone();
void function_ordertow();
void function_dol(struct Tree *AVL_tree, int);
void function_out(struct Tree *AVL_tree, int, int);


int height(struct Tree *AVL_tree){

	if (AVL_tree == null_value){

		return 0;
	}

	else{

        int random = (AVL_tree-> height);
        return (random);
	}
}


int maximum(int number1, int number2){

	if (number1 > number2){

        return (number1);
	}

    else{

        return (number2);
    }
}


struct Tree *function_right(struct Tree *AVL_tree){

    int flag = 1;

    struct Tree *ptr_left = (AVL_tree-> left);
	struct Tree *ptr_right = (ptr_left-> right);

	(ptr_left-> right) = (AVL_tree);
    (ptr_left-> parent) = (AVL_tree-> parent);
    (ptr_left-> charr) = (AVL_tree-> charr);

	(AVL_tree-> left) = (ptr_right);
    (AVL_tree-> parent) = (ptr_left-> index1);
    (AVL_tree-> charr) = RRR;

    if((AVL_tree-> left) != (null_value)){

        flag = 0;
        (ptr_right-> charr) = LLL;
        (ptr_right-> parent) = (AVL_tree-> index1);
    }

    int random1 = (maximum(height(AVL_tree-> left), height(AVL_tree-> right)) + 1);
	(AVL_tree-> height) = (random1);
	int random2 = (maximum(height(ptr_left-> left), height(ptr_left-> right)) + 1);
	(ptr_left-> height) = random2;

	return (ptr_left);
	return (0);
}


struct Tree *function_left(struct Tree *AVL_tree){

    int flag = 1;

    struct Tree *ptr_right = (AVL_tree-> right);
    struct Tree *ptr_left = (ptr_right-> left);

    (ptr_right-> left) = (AVL_tree);
    (ptr_right-> parent) = (AVL_tree-> parent);
    (ptr_right-> charr) = (AVL_tree-> charr);

    (AVL_tree-> right) = (ptr_left);
    (AVL_tree-> parent) = (ptr_right-> index1);
    (AVL_tree-> charr) = LLL;

    if ((AVL_tree-> right) != null_value){

        flag = 0;
        (ptr_left-> charr) = RRR;
        (ptr_left-> parent) = (AVL_tree-> index1);
    }

    int random1 = (maximum(height(AVL_tree-> left), height(AVL_tree-> right)) + 1);
    (AVL_tree-> height) = (random1);
    int random2 = (maximum(height(ptr_right-> left), height(ptr_right-> right)) + 1);
	(ptr_right-> height) = (random2);

	return (ptr_right);
	return (0);
}


int function_balance(struct Tree *AVL_tree){

	if (AVL_tree == null_value){

		return (0);
	}

	else{

        int random = (height(AVL_tree-> left) - height(AVL_tree-> right));
        return (random);
	}

	return (0);
}


struct Tree* function_insert(struct Tree* AVL_tree, int index1, int parent, char charr){

    int flag = 1;
	if (AVL_tree == null_value){

        struct Tree* AVL_tree = (struct Tree*)malloc(sizeof(struct Tree));
        (AVL_tree-> left) = null_value;
        (AVL_tree-> index1) = index1;
        (AVL_tree-> parent) = parent;
        (AVL_tree-> charr) = charr;
        (AVL_tree-> height) = flag;
        (AVL_tree-> right) = null_value;
        flag = 0;
        return (AVL_tree);
    }

    int random_in = (AVL_tree-> index1);
	if(index1 < random_in){

        int random_left = (AVL_tree-> left);
		(AVL_tree-> left) = function_insert(random_left , index1, random_in, LLL);
	}

	else if(index1 > (AVL_tree-> index1)){

        random_in = (AVL_tree-> index1);
        int random_right = (AVL_tree-> right);
		(AVL_tree-> right) = function_insert(random_right, index1, random_in, RRR);
	}

	else{

		return (AVL_tree);
	}

    int random = (1 + maximum(height(AVL_tree-> left), height(AVL_tree-> right)));
	(AVL_tree-> height) = random;

	int balance = function_balance(AVL_tree);
    int random1 = balance;

	if((balance > 1) && (index1 < (AVL_tree-> left-> index1))){

		return (function_right(AVL_tree));
	}

	if((balance < -1) && (index1 > (AVL_tree-> right-> index1))){

		return (function_left(AVL_tree));
	}

	if((balance > 1) && (index1 > (AVL_tree-> left-> index1))){

		(AVL_tree-> left) = function_left(AVL_tree-> left);
		return (function_right(AVL_tree));
	}

	if((balance < -1) && (index1 < (AVL_tree-> right-> index1))){

		(AVL_tree-> right) = function_right(AVL_tree-> right);
		return (function_left(AVL_tree));
	}

	return (AVL_tree);
	return (0);
}


void function_orderone(struct Tree *AVL_tree){

    int flag = 0;
    int list[10];
    if(AVL_tree != null_value){

        function_orderone(AVL_tree-> left);
        printf("%d\n", (AVL_tree-> index1));
        function_orderone(AVL_tree-> right);
        flag = 1;
    }

    return (0);
}


void function_ordertow(struct Tree *AVL_tree){

    int flag = 0;
    int height_num = height(AVL_tree);
    int i = 0;

    for(i = 1; i <= height_num; i++){

        printf("\n");
        int therightmost;
        function_dol(AVL_tree, i);

        for(int j = 0; j < size; j++){

            if((list_of_tree[j]) == (-1)){

                therightmost = (list_of_tree[j - 1]);
                flag = 1;
                break;
            }
        }

        function_out(AVL_tree, i, therightmost);

        for (int w = 0; w < size; w++){

            list_of_tree[w] = (-1);
        }
    }

    return (0);
}


void function_dol(struct Tree *AVL_tree, int orderl){

    int flag = 1;
    if(AVL_tree == null_value){

        flag = 0;
        return (0);
    }

    int one = 1;
    int one_neg = -1;
    if(orderl == one){

        for (int i = 0; i < size; i++){

            int list_number = list_of_tree[i];

            if (list_number == one_neg){

                int random1 = (AVL_tree-> index1);
                list_of_tree[i] = (random1);
                flag = 0;
                break;
            }
        }
    }

    else if(orderl > one){

        flag = 1;
        int random1 = (AVL_tree-> left);
        int random11 = (orderl - 1);
        function_dol(random1, random11);

        int random2 = (AVL_tree-> right);
        int random22 = (orderl - 1);
        function_dol(random2, random22);
    }

    return (0);
}


void function_out(struct Tree *AVL_tree, int orderl, int therightmost){

    int one = 1;
    int one_neg = -1;

    if(AVL_tree == null_value){

        return;
    }

    if(orderl == one){

        int random = (AVL_tree-> parent);
        if(random == one_neg){

            int random1 = (AVL_tree-> index1);
            printf("%d (%d %c)", random1, (function_balance(AVL_tree)), BBB);
        }

        else if((AVL_tree-> index1) == therightmost){

            int random_in = (AVL_tree-> index1);
            int random_pre =  (AVL_tree-> parent);
            int random_char = (AVL_tree-> charr);
            int random_fun = (function_balance(AVL_tree));

            printf("%d (%d %c) (%d %c)", random_in, random_pre, random_char, random_fun, BBB);
        }

        else{

            int random_in = (AVL_tree-> index1);
            int random_pre =  (AVL_tree-> parent);
            int random_char = (AVL_tree-> charr);
            int random_fun = (function_balance(AVL_tree));

            printf("%d (%d %c) (%d %c) ", random_in, random_pre, random_char, random_fun, BBB);
        }
    }

    else if(orderl > one){

        int random_lef = (AVL_tree-> left);
        int random_order = (orderl - 1);
        function_out(random_lef, random_order, therightmost);

        int random_right = (AVL_tree-> right);
        function_out(random_right, random_order, therightmost);
    }

    return (0);
}


int main(){

    struct tree *AVL_tree = null_value;

    int index;

    for(int i = 0; i < size; i++){
        list_of_tree[i] = -1;
    }

    scanf("%d", &index);

    int flag = -1;

    while(index != flag){
        AVL_tree = function_insert(AVL_tree, index, flag, random_str);
        scanf("%d", &index);
    }

    function_orderone(AVL_tree);
    function_ordertow(AVL_tree);

    return (0);
}

