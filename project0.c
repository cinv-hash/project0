#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct character{
    unsigned char c[5];
    int count;
    int first;
};
typedef struct character character;
struct character ch[250000];
int szOfStruct = 0;


int charOccurence(char *c){
    int idx = -1;
    for(int i = 0; i < szOfStruct; i++){
        if(strcmp(c,ch[i].c) == 0){ //if it's not duplicate return the index
            idx = i;
            break;
        }
    }
    return idx;
}

int charcountcmp(const void * left, const void * right) {

    const character *a = (const void*) left;
    const character *b = (const void*) right;
    return -(*a).count + (*b).count;
}

int main() {

    unsigned char temp[5] = {};
    int byteCount = 0;

    while(scanf("%c", &temp[0]) != EOF){

	    byteCount++;
	    if ( temp[0] > 239)
	    {
	        scanf("%3s", &temp[1]);
	        byteCount+=3;
	    }
	    else if ( temp[0] > 223)
	    {

	        scanf("%2s", &temp[1]);
	        byteCount+=2;
	    }
	    else if ( temp[0] > 191)
	    {
	        scanf("%1s", &temp[1]);
	        byteCount++;
	    }
	    else
	    {
	    }
	    int i = charOccurence(temp);

	    if(i == -1){//Unique
	        strcpy(ch[szOfStruct].c, temp); //when unique, cpy the content from buffer to struct's char.
	        ch[szOfStruct].count++; //count the occurence as only 1 time.
	        ch[szOfStruct].first = byteCount; //set location to first
	        szOfStruct++;//arrsizestruct++
	    }
	    else{//duplicate
	        ch[i].count++; //increment the occurence of that character
	    }

	    memset(temp, '\0', 5);

    }

    qsort(ch->c, szOfStruct, sizeof(character), charcountcmp);

    for(int i = 0; i < szOfStruct; i++){
        printf("%s->%d\n", ch[i].c, ch[i].count);
    }

    return 0;
}
