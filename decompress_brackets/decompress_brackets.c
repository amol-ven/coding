#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <ctype.h>

/*
 * Given a compressed string in which a number followed by [] indicate how many times those characters occur, decompress the string
 * Eg. : a3[b2[c1[d]]]e will be decompressed as abcdcdbcdcdbcdcde.
 * Assume the string is well formed and number will always be followed by a [].
*/


void dec(char *res, char *str, size_t len)
{
	static int pos;
	static int level = 0;
	int numpos = -1;
	int rep = 1;
	char result_lower[128];   //result for lower levels of recurssion.
	char local[128];    //local string to pass up to upper levels of recurssion.
	int localpos = 0;
	//go down the recurssion
	//seek to a number
	memset(local, 0, 128); //clear local string
	memset(result_lower, 0, 128); //clear local string

	while (pos < len-1) {
		printf("level = %d   pos=%d   len=%d   char:%c\n", level, pos, (int)len, str[pos]);
		if (isdigit(str[pos])) {
			//we have a digit.
			//seek to '['
			numpos = pos;
			while (pos < len) {
				if (str[pos] == '[')
					break;
				pos++;
			}
			//pos is at a '['
			printf("POS=%d\n", pos);

			rep = strtol(&str[numpos], NULL, 10);
			pos+=1; //skip the '[' and point to next character
			
			printf("rep: %d.. pos=%d\n", rep, pos);
			//Now we have to repeat everything in level+1
			//recurssion level rep times.
			level = level+1;
			
			dec(result_lower, str, len);
			//result_lower populated
			//repeat this rep times.
			printf("result_lower = %s\n", result_lower);
			while (rep) {
				strcat(local, result_lower);
				localpos = strlen(local);
				rep--;
			}
			printf(">>>now local = %s\n", local);
			
			
		} else if (str[pos] == ']') {
			//here level better be more than 0
			//whatever you have put in local.. copy that into result buffer and return.
			if(level <= 0) {
				//This should never happen
				printf("WTF\n");
				exit(1);
			}
			printf("here  local=%s\n", local);
			strcpy(res, local);
			level--;
			return;   //pull out of recurssion
		} else {
			//pos is not a digit...continue...
			printf("localpos = %d......local=%s\n", localpos, local);
			local[localpos++] = str[pos];
		}
		pos++;
		printf("!local = %s\n", local);
	}
	level--;
	strcpy(res, local);
}
	


int main()
{
	//char string[] = "a3[b2[c1[d]]]e";
	//char string[] = "abd2[c10[g]]";
	//char string[] = "a100[b]";
	//char string[] = "a2[2[2[c]]]";
	char string[] = "abc";
	size_t len = sizeof(string);
	char result[128];
	memset(result, 0, 128);
	
	dec(result, string, len);

	printf("finalresult = %s\n", result);
}
