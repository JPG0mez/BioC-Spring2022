//Author: Juan Pablo Gomez Postigo
//Date: 01/25/2022
//Description: This code will open a text file filled with 20 random numbers and will add them all up.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int i;								// Variable used to traverse array storing values in file
	float a[20];						// Buffer to contain value found in file
	float sum; 							// Variable holding current summed value of file
	FILE *fp;							// File variable
	FILE *output;
	fp = fopen("num.txt","r");			// Open file num.txt
	//Set variable values to 0
	i = 0;
	sum = 0;
	//Navigate through file storing values found in buffer until end of file is reached
	while(fscanf(fp,"%g",&a[i])!=EOF)
	{
		sum = sum + a[i];				// Add new value to existing sum
	}	
	fclose(fp);	 						// Close file
	output = fopen("output.txt","w");
	fprintf(output,"The sum of the numbers found in the file is %f\n",sum); // Print value to new file
	
	return 0;
}	
