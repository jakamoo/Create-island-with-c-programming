#include <stdio.h>
#define MAX 512


typedef struct {
	
	int terrain_info;
	int class;
	
}island;

int create_island(island str[][MAX],int level_info, int i, int j ,int k );// creating island which above water level
int count_island(island str[][MAX],int data);//counting island 
int in_the_map(int row , int column);//controlling island size 

int main(){

island arr[MAX][MAX];
FILE *ptr;
FILE *fp;
fp=fopen("output.txt","w");
ptr=fopen("input.txt","r");

int i,j,k=1 ,terrain_count=1;
int level_info;
fscanf(ptr,"%d ",&level_info);


for(i=0 ; i<MAX;i++){  // taking from input.txt data  and making class 0 them.

	for(int j=0;j<MAX;j++){

		fscanf(ptr,"%d ",&arr[i][j].terrain_info);
		arr[i][j].class=0;
	}
}

for(i=0;i<MAX;i++){ // travelling every point and decides island

	for(j=0;j<MAX;j++){

		if(arr[i][j].terrain_info>level_info && arr[i][j].class==0 ){
			create_island(arr,level_info,i,j,k);
			k++;
			 
		}
	}
}

for(i=0 ; i<MAX;i++){// counting island num

	for(j=0;j<MAX;j++){


		
		if(arr[i][j].class==terrain_count){
		
			count_island(arr,terrain_count);
			terrain_count++;
		}

	


	}

}

terrain_count--; // when dont exit the loop , terrain count more +1 so that we need the decrease them

fprintf(fp, "%d  \n",terrain_count); // printing to the outputfile num of island
int temp=1;


for(i=0 ; i<MAX;i++){

	for(j=0;j<MAX;j++){


		
		if(arr[i][j].class==temp){
		
			fprintf(fp, "x_coordinate:%d y_coordinate:%d \n",j,i );
			temp++;
		}

	


	} // printing to the file of island's one x and y coordinates

}

fclose(fp);
fclose(ptr);



}

int create_island(island str[][MAX],int level_info, int i, int j ,int k ){

	str[i][j].class=k;


	if(in_the_map(i,j+1)){
		
			if (str[i][j+1].class==0 && str[i][j+1].terrain_info>level_info  ){
					
					 create_island(str,level_info,i,j+1,k);
					 

			}

		
	}

	
	
	if( in_the_map(i+1,j)){
		

		if (str[i+1][j].class==0 && str[i+1][j].terrain_info>level_info){
			
			 create_island(str,level_info,i+1,j,k);
			

		}
		

	}

	if( in_the_map(i,j-1) ){
			
			if (str[i][j-1].class==0 && str[i][j-1].terrain_info>level_info ){
				
				create_island(str,level_info,i,j-1,k);
			

		}
		
	}
	 if( in_the_map(i-1,j) ){
		
			if (str[i-1][j].class==0 && str[i-1][j].terrain_info>level_info ){
				
				 create_island(str,level_info,i-1,j,k);
				

		}
		

	}

	return 0;
} 


int count_island(island str[][MAX],int data){

	int i,j;
	int num=0;

	for(i=0;i<MAX;i++){

		for(j=0;j<MAX;j++){
			if (str[i][j].class==data)
				num++;

		}
	}

	return num;
}

int in_the_map(int row , int column){
	int dimension =MAX;
	if (row>=0 && column>=0){
		if((row<dimension) && (column < dimension)  )
				return 1;
	}
	return 0;
}
