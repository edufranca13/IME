#include <stdio.h>
#include <stdlib.h>

void justifica(char s[], int coluna, int j, int i){

	int N = coluna - i + j;
	
	int k;
	int esp = 0;
	for (k = j; k < i; k++){
		if (s[k] == ' '){
			esp++;
			s[k] = '_';
		}
	}
	printf("%d %d\n", N, esp);

	int esp2 = 0;
	for (k = j; k < i; k++){

		if(s[k]=='_'){
			esp2++;
		}

		if (N < esp){
			if (s[k] == '_' && esp2 >= esp - N+1){
				printf("_ ");
			}
			printf("%c", s[k]);
		}
		else{

			printf("%c", s[k]);
		}
	}
	printf("\n");


}


void teste(char s[], int coluna){

	int comp = 0;
	int i = 0;
	int j = 0;

	while (s[i] != '\0'){

		comp++;
		i++;

		if (s[i] == ' ' && comp >= coluna){
			justifica(s, coluna, j, i);
			comp = 0;
			j = i+1;
		}
		if (s[i] != ' ' && comp > coluna){
			while (s[i] != ' '){
				i--;
			}
			justifica(s, coluna, j, i);
			comp = 0;
			j = i+1;
		}
		if (s[i] == '\0'){
			justifica(s, coluna, j, i);
		}
	}
}



int main() {

	char s[] = "38:1 Then the LORD answered Job out of the whirlwind, and said, 38:2 Who is this that darkeneth counsel by words without knowledge?  38:3 Gird up now thy loins like a man; for I will demand of thee, and answer thou me.";
//	char s[] = "38:4 Where wast thou when I laid the foundations of the earth?  declare, if thou hast understanding.";
//	char s[] = "38:5 Who hath laid the measures thereof, if thou knowest? or who hath stretched the line upon it?  38:6 Whereupon are the foundations thereof fastened? or who laid the corner stone thereof; 38:7 When the morning stars sang together, and all the sons of God shouted for joy?  38:8 Or who shut up the sea with doors, when it brake forth, as if it had issued out of the womb?  38:9 When I made the cloud the garment thereof, and thick darkness a swaddlingband for it, 38:10 And brake up for it my decreed place, and set bars and doors, 38:11 And said, Hitherto shalt thou come, but no further: and here shall thy proud waves be stayed?  38:12 Hast thou commanded the morning since thy days; and caused the dayspring to know his place; 38:13 That it might take hold of the ends of the earth, that the wicked might be shaken out of it?  38:14 It is turned as clay to the seal; and they stand as a garment.";

	teste(s, 65);


	return 0;
}