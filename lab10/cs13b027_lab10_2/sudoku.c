/*
* Author: <Insert your name>
* Roll No: <Insert roll Number>
*/

#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define BOARD_SIZE 9

void sudoku_solve(int **);
GtkWidget* wid[BOARD_SIZE][BOARD_SIZE], *window;

//Creates the menu widget
void menu_event(GtkWidget* widget, gpointer data){
	int i,j;
	int*** temp_board = data;
	int** board = *temp_board;
	if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(widget)), "New")==0)
	{
		for(i = 0;i<BOARD_SIZE;i++){
			for(j=0; j<BOARD_SIZE;j++){
				board[i][j]=0;
				gtk_entry_set_text(GTK_ENTRY(wid[i][j]),"0");
			}
		}
	}

	else if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(widget)),"Open")==0){

		FILE *fr;
		GtkWidget* dialog;
		dialog = gtk_file_chooser_dialog_new("Choose a file", GTK_WINDOW(window), GTK_FILE_CHOOSER_ACTION_OPEN, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, GTK_STOCK_OK, GTK_RESPONSE_OK,NULL);

		gtk_widget_show_all(dialog);

		gint resp=gtk_dialog_run(GTK_DIALOG(dialog));

		if(resp==GTK_RESPONSE_OK){
			fr = fopen(gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog)),"rt");
			int box_input=0;
			int counter = 0;

			while(fscanf(fr,"%d", &box_input)==1){

				char c[2];
				c[0] = box_input+48; c[1] = '\0';
				gtk_entry_set_text(GTK_ENTRY(wid[counter/BOARD_SIZE][counter%BOARD_SIZE]),c);
				counter++;
			}

			fclose(fr);
			gtk_widget_destroy(dialog);

		}

		else
			printf("No file given.\n");
	
	}

	else if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(widget)),"Exit")==0){
		gtk_main_quit();
	}

}



//============================================== Back end functions start=================================================//




//Initializes the board with all 0's.
void initialize_board(int** board){

	int i,j;

	for(i=0; i<BOARD_SIZE; i++)
		for(j=0; j< BOARD_SIZE; j++)
			board[i][j] = 0;// 0 indicates that the cell still needs to be filled

}

//Allocates memory for the board
int** makeBoard(int** board){

	board = (int**)malloc(BOARD_SIZE*sizeof(int*));

	int i;

	for(i = 0; i<BOARD_SIZE; i++)
		board[i] = (int*)malloc(BOARD_SIZE*sizeof(int));

	initialize_board(board);

	return board;
}


//TODO:==========================================Implement the Backtracking algorithm below============================================


//Implement your backtracking functions here which solve the sudoku board.


//This function should call the backtracking algorithm which solves the board.
//NOTE: The board variable points to a memory 9x9 in size. You DO NOT need to allocate a new memory for it again. Work with the given
//board variable. board[i][j] contains the (i,j)th entry in the board.
//The "board" variable is NOT a global variable. You have to pass it to different functions inside which you need it.

//main function which calls sudoku_solve function which implements the backtracking algorithm

void solveBoard(int** board){
	int i,j;
	printf("Solving the board ...\n");
	//TODO: Call your backtracking algorithm from here. Implement all the functions above this function.
	sudoku_solve(board);
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			printf("%d ",board[i][j]);
		}
		printf("\n");
	}
	printf("Solved the board ...\n");

}

//this function is used for debugging purposes also used for console version of the game

void print_board(int **board){

	int i,j;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			printf("%d ",board[i][j]);
		}
		printf("\n");
	}

}

int validateBoard(int **);
int validateCell(int** , int , int );

// function which implements backtrack algorithm for solving the sudoku

void sudoku_solve(int **board){

	int j,num,i;
	if(validateBoard(board) == 1)
		return;
	for(i=0;i<BOARD_SIZE;i++){
		for(j=0;j<BOARD_SIZE;j++){
			if(board[i][j] == 0){

				for(num=1;num<=9;num++){
					board[i][j] = num;
					if(!validateCell(board, i, j)){
						//count++;
						board[i][j] = 0;
/*						if(count == 9){
							//printf("blah");
							//sudoku_solve(board);
							return;
						}*/
						if(num == 9){
							//printf("blah");
							//sudoku_solve(board);
							return;
						}
						continue;
					}
					else{
						sudoku_solve(board);
						if(validateBoard(board) == 1)
							return;
						board[i][j] = 0;
					}
				}

			}
			if(board[i][j] == 0)
				return;
		}
	}
	return;
}
//TODO:==========================================Implement the Backtracking algorithm above============================================



//Prints the board on the terminal
void printBoard(int** board){
	int i,j;
	for(i=0;i<BOARD_SIZE;i++){
		for(j=0;j<BOARD_SIZE;j++){
			printf("%d ",board[i][j]);
		}
		printf("\n");
	}
}

//This is a subroutine used by validateBoard function to check whether a cell has a valid number.
int validateCell(int** board, int row, int column){
	
	int i,j;

	for(i = 0; i<BOARD_SIZE; i++){
		if(i!=column){
			if(board[row][i]==board[row][column]){
				//printf("Cells %d %d and %d %d have the same number.\n",(row+1),(i+1),(row+1),(column+1));
				return 0;// multiple copies found
			}
		}
	}

	for(i = 0; i<BOARD_SIZE; i++){
		if(i!=row){
			if(board[i][column]==board[row][column]){
				//printf("Cells %d %d and %d %d have the same number.\n",(i+1),column+1,row+1,column+1);
				return 0;// multiple copies found
			}
		}
	}
	

	for(i = (row/3)*3;i<(row/3)*3+3;i++){
		for(j = (column/3)*3; j<(column/3)*3+3; j++){
			if(!(i==row && j==column)){
				if(board[i][j]==board[row][column]){
					//printf("Cells %d %d and %d %d have the same number.\n",i+1,j+1,row+1,column+1);
					return 0;// multiple copies found
				}
			}
		}
	}
	return 1;
}


//Validates the entire board.
//Returns 1 if valid. Returns 0 if invalid. Returns -1 if the board is yet to be solved. Returns -2 if the board has an entry other than 0-9.
int validateBoard(int** board){
	int i,j;
	int flag = 1;//1 indicates that the board has no 0 in it.
	for(i = 0;i<BOARD_SIZE;i++){
		for(j=0;j<BOARD_SIZE;j++){
			if(board[i][j]>=1&&board[i][j]<=BOARD_SIZE){
				int returnVal = validateCell(board,i,j);
				if(returnVal==0)
					return 0;//Invalid cell found. Return 0.
			}
			else if(board[i][j]==0)
				flag = 0;//Indicates that there are unfilled cells in the board.
			else
				return -2;//The code wouldn't usually reach here as each cell has a number only from 0-9.
		}
	}

	if(flag==0)
		return -1;//Indicates that the board has unsolved cells.

	return 1;//Indicates that the entire board was solved successfully.
}

//============================================== Back end functions end =================================================//


void solveClicked(GtkWidget* widget, gpointer data){

	int*** tempBoard = data;
	int** board = *tempBoard;

	int i,j;

	for(i=0;i<BOARD_SIZE;i++)
		for(j=0;j<BOARD_SIZE;j++)
			board[i][j] = atoi(gtk_entry_get_text(GTK_ENTRY(wid[i][j])));
		
		
	
	printf("\n\n=============================================\n");
	int returnVal = validateBoard(board);
	if(returnVal==0){
		printf("Input board is invalid.\n");
		return;
	}
	else if(returnVal==-1){
		printf("The input board has unsolved cells.\n");
	}
	else if(returnVal==-2){
		printf("The board has numbers out of range.\n");
		return;
	}


	//TODO: This function calls the backtracking algorithm that you need to implement.
	solveBoard(board);

	
	returnVal = validateBoard(board);
	if(returnVal==0){
		printf("The solved board is invalid.\n");
		return;
	}
	else if(returnVal==-1){
		printf("The board has not been solved yet.\n");
		return;
	}
	else if(returnVal==-2){
		printf("Solved board has numbers out of range.\n");
		return;
	}
	else
		printf("The Solved Board is valid.\n");

	char c[2];
	c[1]='\0';

	for(i=0;i<BOARD_SIZE;i++){
		for(j=0;j<BOARD_SIZE;j++){
			c[0] = board[i][j]+48;
			gtk_entry_set_text(GTK_ENTRY(wid[i][j]),c);
		}
	}
	
}


int main(int argc, char** argv){


	int** board;

	int i = 0, j = 0;
	const char* file[] = {"New","Open","Exit"};

	board = makeBoard(board);



	//Making the GUI by packing widgets into the window

	gtk_init(&argc, &argv);
	GtkWidget *vbox, *hbox, *separator, *button, *file_menu, *menu_bar, *menu_item;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	vbox = gtk_vbox_new(0,0);

	file_menu = gtk_menu_new();
	menu_bar = gtk_menu_bar_new();
	menu_item = gtk_menu_item_new_with_label("File");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item),file_menu);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_item);

	for(i=0;i<3;i++){
		menu_item = gtk_menu_item_new_with_label(file[i]);
		gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), menu_item);
		g_signal_connect(menu_item, "activate", G_CALLBACK(menu_event), &board);
	}

	gtk_box_pack_start(GTK_BOX(vbox),menu_bar,0,0,0);


	for(i=0;i<BOARD_SIZE;i++)
	{
		hbox=gtk_hbox_new(0,0);

		for(j = 0; j<BOARD_SIZE;j++){
			wid[i][j]=gtk_entry_new();
			gtk_entry_set_max_length(GTK_ENTRY(wid[i][j]),1);
			gtk_widget_set_size_request(wid[i][j],30,30);
			gtk_box_pack_start(GTK_BOX(hbox), wid[i][j],0,0,0);
			if((j+1)%3==0&&j!=(BOARD_SIZE-1)){
				separator=gtk_vseparator_new();
				gtk_box_pack_start(GTK_BOX(hbox),separator,10,0,5);
			}
		}

		gtk_box_pack_start(GTK_BOX(vbox),hbox,0,0,0);

		if((i+1)%3==0 && i!=(BOARD_SIZE-1)){
			separator=gtk_hseparator_new();
			gtk_box_pack_start(GTK_BOX(vbox),separator,10,0,5);
		}

	}

	button = gtk_button_new_with_label("Solve");
	g_signal_connect(button, "clicked",G_CALLBACK(solveClicked),&board);

	gtk_box_pack_start(GTK_BOX(vbox),button,0,0,0);

	g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
	gtk_container_add(GTK_CONTAINER(window),vbox);
	gtk_widget_show_all(window);
	gtk_main();
	//GUI construction done
	free(board);
	return 0;
}
