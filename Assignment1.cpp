/*Name: Yen Pham
CS3110
Assignment 1
*/


#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

void insertion_sort(double array[500], int L, int H) //insertion sort
{
	double temp;
	for (int k = L+1; k <=H; k++)
	{
		temp = array[k];//array[k] is current element
		int di = k-1; //di is the previous index
		while (di >= L)
		{
			//swap 2 element if the element before > element after
			if (temp < array[di])
			{
				array[di+1]= array[di];
				array[di] = temp;
				di--;
			}
			else
			{
				break;
			}
		}
	}
}

void merge_halves(double array[500], int L, int H, int mid_index)
{
	int first = L;
	int last = mid_index+1;

	double *temp = new double[H+1];
	
	for (int i=L; i<=H; i++)
	{
		if(first <= mid_index && (last > H || array[first] <= array[last]))
		{
			temp[i] = array[first]; //take element from the first half and put it to temp array if it is smaller than the other one from the second half
			first++;
		}

		else
		{
			temp[i] = array[last]; ////take element from the second half and put it to temp array if it is smaller than the other one from the first half

			last++;
		}
	}
	//pass all the sorted elements back to the array
	for (int i=L; i <=H; i++)
	{
		array[i]=temp[i];
	}
}

void merge_sort(double array[500], int L, int H)
{
	if((H-L) <=8)
	{
		insertion_sort(array, L, H); //call insertion sort
	}
	else
	{
		int mid_index = (H+L)/2; //get middle index
		merge_sort(array, 0, mid_index); //call merge sort from beginning to half
		merge_sort(array, mid_index+1, H); //call merge sort from half to end
		merge_halves(array, L, H, mid_index);
	}
}

int main()
{
	ifstream fin("data1.txt"); //input file
	ofstream fout("out1.txt"); //output file
	string line;
	int count;
	double number;

	//Read line
	while(getline(fin, line))
	{
		double array[500];
		count = 0;
		stringstream is(line);
		while(is >> number)
		{
			array[count] = number;
			count++;
		}
		merge_sort(array, 0, count-1);

		for (int i = 0; i < count; i++)
		{
			fout << array[i] << " ";
		}
		fout << endl;
	}

	return 0;
}