#include "lab3.h"


/*For this function, I use the globaly declared BOARD_SIZE variable to both declare the size of malloc and iterate through the array initilizing
every cell to 0. I also added space for the hidden variables of score, hits, and shots for later then returned the board. I return NULL if the malloc fails*/
int * newBoard(){
    int*board;
    if((board = malloc((BOARD_SIZE*sizeof(int))+(2*sizeof(int))+sizeof(float)))){
        board += 2;
        //[-1] == score
        // [-2] == succesful hits
        //[-3] == total shots
        (float *)board++;

        for(int i = 0; i < BOARD_SIZE; i++){
            board[i] = 0;
        }

        return board;
    }
    return NULL;
}


/*for this function I first increment the shots taken, then check to see if the guessed cell has a ship or not, if it does I adjust the array, 
and increment the hits while returning 1. If there is no ship i simply return 0*/
int takeShot(int *board, int cell){
    board[-3]++;
    if(*(board + cell) == 1){
        *(board + cell) = -1;
        board[-2]++;
        return 1;
    } else {
        return 0;
    }
}


/* for this function I simply iterate through the array checking for any 1s that represent there is a ship, then return the amount of ships found.*/
int countRemainingShips(int *board){
    int shipsLeft = 0;
    for(int i = 0; i < BOARD_SIZE; i++){
        if(board[i] == 1){
            shipsLeft++;
        }
    }
    return shipsLeft;
}

/*for this function i return board[-3] which is where I'm hiding the shots*/
int getShotsTaken(int *board){
    return board[-3];
}

/*for this function I return board[-2] where I hide the hits*/
int getHits(int *board){
    return board[-2];
}

/*for this function I return the float value of board[-1] where I hide the score*/
float getScore(int *board){
    return *((float*)board-1);
}

/*for this function I convert the intiger values of hits and shots into floats then divide them per the instructions
to find the score, before updating board[-1] to match the new score*/
void updateScore(int *board){
    float score = ((float)getHits(board))/((float)getShotsTaken(board));
    *((float*)board-1) = score;
    return;
}

/*in this function I decrement the array to go back to what I originally malloced, I then free the pointer*/
void endGame(int *board){
    board -= 2;
    (float*)board--;
    free(board);
    return;
}