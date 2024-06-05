#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>


bool check(int Robot[9][9], int x, int y){
	if (Robot[x][y] == 1){	
		return true;
	} else{
		return false;
		}

}



int main(){

	int Robot[9][9];
	int target_x=3;
	int target_y=7;
	int i, j;
	int Path[9][9]={
			1,1,1,0,0,1,0,0,1,
			1,1,1,0,1,1,0,1,1,
			0,0,1,1,0,0,0,1,1,
			1,1,0,1,1,1,0,0,0,
			1,0,0,0,1,0,1,1,1,
			1,1,0,1,1,0,0,0,1,
			0,0,1,0,1,0,0,1,1,
			0,0,1,1,1,0,0,1,1,
			1,1,1,0,1,1,0,1,0};
	

	for (i=0; i<9; i++){
		for(j=0; j<9; j++){
		Robot[i][j] = 0;	
		}
	}
	

	for (i=0; i<9; i++){
		for(j=0; j<9; j++){
		
			if (Path[i][j] == 1) {
				Robot[i][j] = 1;
			}else{
				Robot[i][j] = 0;
				}
			
		}
		
	}	
	
	
assert (!check(Robot, target_x, target_y));

}
	







