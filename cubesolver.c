#include <stdio.h>
#include <unistd.h> // sleep

// Count how many edge pieces are in the wrong place.
int countUnsolvedEdges(char state[24]){
	// There are 24 edge stickers.
	int numUnsolved = 24;
	for(int i = 0; i < 24; i++){
		// Correct state = {'A','B','C',...,'X'}
		if(state[i] == i + 'A'){
			numUnsolved--;
		}
	}
	// Since each piece contains two stickers solving one sticker
	//  automatically solves the other. Unsolved pieces are therefore
	//  half of unsolved stickers.
	numUnsolved /= 2;
	numUnsolved--; // Buffer piece does not count.
	return numUnsolved;
}

// Count how many edge pieces are in the wrong place.
int countUnsolvedCorners(char state[24]){
	// There are 24 corner stickers.
	int numUnsolved = 24;
	for(int i = 0; i < 24; i++){
		// Correct state = {'A','B','C',...,'X'}
		if(state[i] == i + 'A'){
			numUnsolved--;
		}
	}
	// Since each piece contains three stickers solving one sticker
	//  automatically solves the other two. Unsolved pieces are therefore
	//  one third of unsolved stickers.
	numUnsolved /= 3;
	numUnsolved--; // Buffer piece does not count.
	return numUnsolved;
}

void onSameCorner(char x, char ret[2]){
	
	// COUNTERCLOCKWISE ORDER
	switch(x){
		case 'A':
			ret[0] = 'M';
			ret[1] = 'T';
			return;
		case 'B':
			ret[0] = 'I';
			ret[1] = 'P';
			return;
		case 'C':
			ret[0] = 'E';
			ret[1] = 'L';
			return;
		case 'D':
			ret[0] = 'Q';
			ret[1] = 'H';
			return;
		case 'E':
			ret[0] = 'L';
			ret[1] = 'C';
			return;
		case 'F':
			ret[0] = 'X';
			ret[1] = 'K';
			return; 
		case 'G': 
			ret[0] = 'R';
			ret[1] = 'W';
			return;
		case 'H': 
			ret[0] = 'Q';
			ret[1] = 'D';
			return;
		case 'I': 
			ret[0] = 'P';
			ret[1] = 'B';
			return;
		case 'J':
			ret[0] = 'U';
			ret[1] = 'O';
			return;
		case 'K':
			ret[0] = 'F';
			ret[1] = 'X';
			return;
		case 'L':
			ret[0] = 'C';
			ret[1] = 'E';
			return;
		case 'M':
			ret[0] = 'T';
			ret[1] = 'A';
			return;
		case 'N': 
			ret[0] = 'V';
			ret[1] = 'S';
			return;
		case 'O': 
			ret[0] = 'J';
			ret[1] = 'U';
			return;
		case 'P': 
			ret[0] = 'B';
			ret[1] = 'I';
			return;
		case 'Q': 
			ret[0] = 'H';
			ret[1] = 'D';
			return;
		case 'R': 
			ret[0] = 'W';
			ret[1] = 'G';
			return;
		case 'S': 
			ret[0] = 'N';
			ret[1] = 'V';
			return;
		case 'T': 
			ret[0] = 'A';
			ret[1] = 'M';
			return;
		case 'U': 
			ret[0] = 'O';
			ret[1] = 'J';
			return;
		case 'V': 
			ret[0] = 'S';
			ret[1] = 'N';
			return;
		case 'W': 
			ret[0] = 'G';
			ret[1] = 'R';
			return;
		case 'X': 
			ret[0] = 'K';
			ret[1] = 'F';
			return;
	}
}

// What stickers are on the same edge?
char onSameEdge(char x){
	switch(x){
		case 'A': return 'Q';
		case 'B': return 'M';
		case 'C': return 'I';
		case 'D': return 'E';
		case 'E': return 'D';
		case 'F': return 'L';
		case 'G': return 'X';
		case 'H': return 'R';
		case 'I': return 'C';
		case 'J': return 'P';
		case 'K': return 'U';
		case 'L': return 'F';
		case 'M': return 'B';
		case 'N': return 'T';
		case 'O': return 'V';
		case 'P': return 'J';
		case 'Q': return 'A';
		case 'R': return 'H';
		case 'S': return 'W';
		case 'T': return 'N';
		case 'U': return 'K';
		case 'V': return 'O';
		case 'W': return 'S';
		case 'X': return 'G';
	}
}

void printCornerMove(char x){

	char* swap = "(R U' R' U' R U R' F' R U R' U' R' F R)";

	switch(x){
		case 'A':
			printf("R D' %s D R'\n", swap);
			break;
		case 'B':
			printf("F %s F'\n", swap);
			break;
		case 'C':
			printf("F R' %s R F'\n", swap);
			break;
		case 'E':
			printf("F2 %s F2\n", swap);
			break;
		case 'F':
			printf("D2 R %s R' D2\n", swap);
			break;
		case 'G':
			printf("D2 %s D2\n", swap);
			break;
		case 'I':
			printf("R2 D' %s D R2\n", swap);
			break;
		case 'J':
			printf("R F %s F' R'\n", swap);
			break;
		case 'K':
			printf("D %s D'\n", swap);
			break;
		case 'L':
			printf("F' D %s D' F\n", swap);
			break;
		case 'M':
			printf("R2 %s R2\n", swap);
			break;
		case 'N':
			printf("R %s R'\n", swap);
			break;
		case 'O':
			printf("%s\n", swap);
			break;
		case 'P':
			printf("R' %s R\n", swap);
			break;
		case 'R':
			printf("D' R %s R' D\n", swap);
			break;
		case 'S':
			printf("D' %s D\n", swap);
			break;
		case 'T':
			printf("R' F %s F' R\n", swap);
			break;
		case 'U':
			printf("D' F' %s F D\n", swap);
			break;
		case 'V':
			printf("D2 F' %s F D2\n", swap);
			break;
		case 'W':
			printf("D F' %s F D'\n", swap);
			break;
		case 'X':
			printf("F' %s F\n", swap);
			break;
	}
}

void printEdgeMove(char x, char even){
	switch(x){
		case 'A':
			printf("M2\n");
			break;
		case 'B':
			printf("R U R' U' M2 U R U' R'\n");
			break;
		case 'C':
			if(even) printf("U2 M' U2 M'\n");
			else printf("M U2 M U2\n");
			break;
		case 'D':
			printf("L' U' L U M2 U' L' U L\n");
			break;
		case 'E':
			printf("B L' B' M2 B L B'\n");
			break;
		case 'F':
			printf("B L2 B' M2 B L2 B'\n");
			break;
		case 'G':
			printf("B L B' M2 B L' B'\n");
			break;
		case 'H':
			printf("L B L' B' M2 B L B' L'\n");
			break;
		case 'I':
			if(even) printf("D M' U R2 U' M U R2 U' D' M2\n");
			else printf("M2' D U R2 U' M' U R2 U' M D'\n");
			break;
		case 'J':
			printf("U R U' M2 U R' U'\n");
			break;
		case 'L':
			printf("U' L' U M2 U' L U\n");
			break;
		case 'M':
			printf("B' R B M2 B' R' B\n");
			break;
		case 'N':
			printf("R' B' R B M2 B' R' B R\n");
			break;
		case 'O':
			printf("B' R' B M2 B' R B\n");
			break;
		case 'P':
			printf("B' R2 B M2 B' R2 B\n");
			break;
		case 'Q':
			printf("U B' R U' B M2 B' U R' B U'\n");
			break;
		case 'R':
			printf("U' L U M2 U' L' U\n");
			break;
		case 'S':
			if(even) printf("M2' D U R2 U' M' U R2 U' M D'\n");
			else printf("D M' U R2 U' M U R2 U' D' M2\n");
			break;
		case 'T':
			printf("U R' U' M2 U R U'\n");
			break;
		case 'V':
			printf("U R2 U' M2 U R2 U'\n");
			break;
		case 'W':
			if(even) printf("M U2 M U2\n");
			else printf("U2 M' U2 M'\n");
			break;
		case 'X':
			printf("U' L2 U M2 U' L2 U\n");
			break;
	}
}

void swapCorners(char state[24], char a, char b){
	// Swap stickers a and b.
	char temp = state[a];
	state[a] = state[b];
	state[b] = temp;

	char aCornerOther[2];
	onSameCorner(a+'A', aCornerOther);
	char bCornerOther[2];
	onSameCorner(b+'A', bCornerOther);

	// Swap stickers on same corners.
	temp = state[aCornerOther[0]-'A'];
	state[aCornerOther[0]-'A'] = state[bCornerOther[0]-'A'];
	state[bCornerOther[0]-'A'] = temp;

	temp = state[aCornerOther[1]-'A'];
	state[aCornerOther[1]-'A'] = state[bCornerOther[1]-'A'];
	state[bCornerOther[1]-'A'] = temp;
}

// Swap two edge pieces.
void swapEdges(char state[24], char a, char b){
	// Swap stickers a and b.
	char temp = state[a];
	state[a] = state[b];
	state[b] = temp;
	// Swap stickers on same edges.
	temp = state[onSameEdge(a+'A')-'A'];
	state[onSameEdge(a+'A')-'A'] = state[onSameEdge(b+'A')-'A'];
	state[onSameEdge(b+'A')-'A'] = temp;
}

char bufferSolved(char inBuffer, char edges){
	if(edges) return (inBuffer == 'U' || inBuffer == 'K');
	else return (inBuffer == 'D' || inBuffer == 'Q' || inBuffer == 'H');
}

char printSol(char state[24], int numUnsolved, char even, char edges){

	char bufferPos = edges ? 'U'-'A' : 'D'-'A';

	char inBuffer = state[bufferPos];

	while(!bufferSolved(inBuffer, edges)){
		// Print move.
		if(edges) printEdgeMove(inBuffer, even);
		else printCornerMove(inBuffer);
		if(!even) printf("\n");

		// Do the move.
		if(edges) swapEdges(state, bufferPos, state[bufferPos]-'A');
		else swapCorners(state, bufferPos, state[bufferPos]-'A');

		// Update buffer and solve info.
		inBuffer = state[bufferPos];
		numUnsolved--;
		even = !even;
	}
	if(numUnsolved >= 0){
		for(int i = 0; i < 24; i++){
			if(edges && i == 'U'-'A' || i == 'K'-'A') continue; // Does not matter if buffer is solved.
			if(!edges && i == 'D'-'A' || i == 'Q'-'A' || i == 'H'-'A') continue; // Does not matter if buffer is solved.
			if(state[i] != i + 'A'){
				if(edges){
					swapEdges(state, bufferPos, i);
					printEdgeMove(i+'A', even);
				}
				else{
					swapCorners(state, bufferPos, i);
					printCornerMove(i+'A');
				}
				if(even) printf("\n");
				else printf("\n\n"); // Print what is in U-position.
				even = !even;
				return printSol(state, numUnsolved, even, edges);
			}
		}
	}
	return even;
}

int main(){
	// F2 R2 D2 F2 D2 L' B2 L R2 B2 R' U' B' F' R B D L F' R U'
	// HOLD CUBE GREEN FRONT, WHITE UP
	// Stickers in positions A, B, C, ...
	char edges[24] = {
						'G','E','J','S',
						'W','M','L','K',
						'P','N','A','B',
						'D','C','O','T',
						'X','U','R','I',
						'Q','V','H','F'
					};
	// Stickers in positions A, B, C, ...
	char corners[24] = {
							'V','B','H','X',
							'D','G','T','F',
							'I','O','W','Q',
							'S','E','U','P',
							'K','A','C','N',
							'J','L','M','R'
						};

	// Count unsolved edges and print edge solution.
	int numUnsolvedEdges = countUnsolvedEdges(edges);
	char even = printSol(edges, numUnsolvedEdges, 1, 1);
	if(!even) printf("D' L2 D M2 D' L2 D\n\n");

	// Do the same for corners.
	int numUnsolvedCorners = countUnsolvedCorners(corners);
	printSol(corners, numUnsolvedCorners, 1, 0);
	return 0;
}
