typedef struct tuple {

	int index;
	int value;

} tuple;

tuple *createTuple(int *numbers, int n);

void printTuple(tuple *v, int n);