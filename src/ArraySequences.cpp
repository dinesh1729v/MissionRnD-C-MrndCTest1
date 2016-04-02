/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int* detectAp(int *a, int len,int start)
{
	int ans[2] = {-1,-1},i;
	for (i = start; i < len - 2; i++)
	{
		if (((a[i + 1] - a[i]) == (a[i + 2] - a[i + 1]))&&ans[0]==-1) ans[0] = i;
		if (((a[i + 1] - a[i]) == (a[i + 2] - a[i + 1])))continue;
		else if (ans[0] != -1){
			ans[1] = i+1;
			break;
		}
	}
	if (i == len - 2)
		if ((a[i] - a[i - 1]) == (a[i + 1] - a[i]))ans[1]=i + 1;
	return ans;
}

int *detectGp(int *a, int len)
{
	int i,ans[2] = {-1,-1};
	float diff1, diff2;
	for (i = 0; i < len - 2; i++)
	{
		diff1 = (a[i + 1] * 1.0 / a[i]);
		diff2 = (a[i + 2]*1.0 / a[i + 1]);

		if (diff1 == diff2&&ans[0]==-1)ans[0] = i;
		if (diff1 == diff2)continue;
		else if (ans[0] != -1){
			ans[1] = i+1;
			break;
		}
	}
	if ((i == len - 2))
	{
		diff1 = (a[i] * 1.0 / a[i-1]);
		diff2 = (a[i + 1] * 1.0 / a[i]);
		if (diff1 == diff2)ans[1] = i+1;
	}
	return ans;
}
int * find_sequences(int *arr, int len){
	//Return final array which has 6indexes [AP1_S,AP1_E,AP2_S,AP2_E,GP1_S,GP2_E]
	if (arr == NULL || len <= 0)return NULL;
	int *seIndex;
	int *result = (int *)malloc(6*sizeof(int));
	seIndex = detectAp(arr, len,0);
	result[0] = seIndex[0];
	result[1] = seIndex[1];
	seIndex = detectAp(arr, len,result[1]);
	result[2] = seIndex[0];
	result[3] = seIndex[1];
	seIndex = detectGp(arr, len);
	result[4] = seIndex[0];
	result[5] = seIndex[1];
	return result;
}