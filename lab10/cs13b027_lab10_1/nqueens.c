#include <stdio.h>

int n;

//function to initialise the board of nqueens with all zeros
//A zero represents presence of a queen at that position

void board_initialise(int board[][n]){
	
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			board[i][j] = 0;
		}
	}
}

//function to check if we can put a queen at some position

int isvalid(int board[][n], int x, int y){

	int i= x, j = y;
	while(i>=0){
		if(board[i][y] == 1)
			return 0;
		i--;
	}
	i=x;
	while(i<n){
		if(board[i][y] == 1){
			return 0;
		}
		i++;
	}
	while(j>=0){
		if(board[x][j] == 1)
			return 0;
		j--;
	}
	j=y;
	while(j<n){
		if(board[x][j] == 1)
			return 0;
		j++;
	}
	i=x;
	j=y;
	while(i>=0 && j<n){
		if(board[i][j] == 1)
			return 0;
		i--;
		j++;
	}
	i=x;
	j=y;
	while(i<n && j>=0){
		if(board[i][j] == 1)
			return 0;
		i++;
		j--;
	}
	i=x;
	j=y;
	while(i>=0 && j>=0){
		if(board[i][j] == 1)
		return 0;
		i--;
		j--;
	}
	i=x;
	j=y;
	while(i<n && j<n){
		if(board[i][j] == 1)
			return 0;
		i++;
		j++;
	}
	return 1;
}

//used to print the board on the console used for debugging purposes

void print_board(int board[][n]){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//count no. of 1's in the board if it's equal to n then we have got all the queens required

int count(int board[][n]){
	int ans = 0, i, j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(board[i][j] == 1)
				ans++;
		}
	}
	return ans;
}

//main function which implements backtrack algorithm

int evaluate_nqueens(int board[][n], int i){

	int num = 0 ,j;
	if(i == n){
		//printf("blah");
		return 0;
	}
	for(j=0;j<n;j++){
		//printf("%d and %d\n",i,j);
		//printf("%d\n",isvalid(board, i, j));
		if(!isvalid(board, i, j)){
			if(board[i][j] == 1)
				num+=evaluate_nqueens(board,i+1);
			//printf("%d %d\n",i,j);
			continue;
		}
		else{
			board[i][j] = 1;
			//print_board(board);
			if(i == n-1 && count(board) == n){
				//printf("count: %d\n", count(board));
				num++;
			}
			num+=evaluate_nqueens(board, i+1);
			board[i][j] = 0;
		}
	}
	return num;
}

//verify if the given board is valid or not
 
int verify(int board[][n]){

	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(board[i][j] == 1){
				board[i][j] = 0;
				if(!isvalid(board,i,j)){
					board[i][j] = 1;
					return 0;
				}
				board[i][j] = 1;
			}
		}
	}
	return 1;
}

//main function which takes input as given in the problem statement

int main(){

	int t, m, x, y;
	scanf("%d",&t);
	scanf("%d",&n);
	int board[n][n];
	board_initialise(board);
	
	if(!t){
		printf("%d\n",evaluate_nqueens(board,0));
	}
	else{
		scanf("%d",&m);

		while(m){
			scanf("%d%d",&x,&y);
			board[x][y] = 1;
			m--;
		}
		if(verify(board)){
			//printf("all most there\n");
			printf("%d\n",evaluate_nqueens(board,0));
		}
		else
			printf("Not a valid configuration\n"); 
	}
	return 0;
}
