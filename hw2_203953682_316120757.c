//hw2_203953682_316120757
//by furya_naor & meir_ariel.
//Course Number: 0061309-04
//Course Lecturer: dr. yulya kampner
//Course Practitioner: dr. shalom mordehai


#include <stdio.h>

void GreedyColoring();

void main() {
	GreedyColoring();
	int stoper;
	scanf_s("%d", &stoper);
}

void GreedyColoring() {
	int k; // just for stop terminal
	printf("please input k\n");
	scanf_s("%d", &k); // just for stop terminal

	//mycode!:



		//********************************************
	//printf("**gc done! - your input is: %d\n\n", k);
	int arr_size = k;
	int *start_arr = (int *)malloc(arr_size * sizeof(int));
	int *end_arr = (int *)malloc(arr_size * sizeof(int));

	int i = 0;
	int interval_start = 0;
	int interval_end = 0;

	//scaning intervals from user to array's
	for (i = 0; i < k; i++) {
		printf("%dth ", i + 1);
		printf("Interval: ");
		scanf_s("%d %d", &interval_start, &interval_end);
		start_arr[i] = interval_start;
		end_arr[i] = interval_end;
	}

	
	//printing the scaned intervals
	printf("****The intervals family is: \n");
	for (i = 0; i < k; i++) {
		printf("%dth ", i + 1);
		printf("Interval: ");
		printf("%d ", start_arr[i]);
		printf("%d ", end_arr[i]);
		printf("\n");
	}
	

	//sorting intervals arrays (by starters only)
	int temp, j;
	for (j = 0; j < k; j++) {
		for (i = 1; i < k; i++) {
			if (start_arr[i - 1] > start_arr[i]) {
				//swaping the start_array
				temp = start_arr[i - 1];
				start_arr[i - 1] = start_arr[i];
				start_arr[i] = temp;
				//swaping the end_array
				temp = end_arr[i - 1];
				end_arr[i - 1] = end_arr[i];
				end_arr[i] = temp;
			}
		}
	}

	/*
	//printing the sorters intervals
	printf("****The intervals family is: \n");
	for (i = 0; i < k; i++) {
		printf("%dth ", i + 1);
		printf("Interval: ");
		printf("%d ", start_arr[i]);
		printf("%d ", end_arr[i]);
		printf("\n");
	}
	*/

	////***finding edges***
	// (by checking of some interval is start after this interval and end before)
	int edgs = 0;
	//printf("****running about Intervals: \n");
	for (i = 0; i < k - 1; i++) {
		/*
		printf("%dth ", i + 1);
		printf("This Interval: ");
		printf("%d ", start_arr[i]);
		printf("%d ", end_arr[i]);
		printf("\n");
		*/
		for (j = i + 1; j < k; j++) {
			/*
			printf("%dth ", j + 1);
			printf("is now the checking Interval: ");
			printf("%d ", start_arr[j]);
			printf("%d ", end_arr[j]);
			printf("\n");
			*/
			if (end_arr[i] > start_arr[j])
				edgs++;
		}
	}
	printf("G Edges = ");
	printf("%d ", edgs);
	printf("\n");

	////***finding min&max deg ***
// (by checking of some interval is start after this interval and end before..)
	int min_deg = k-1;
	int max_deg = 0;
	int deg = 0;

	//printf("****running about start Intervals: \n");
	for (i = 0; i < k; i++) {
		/*
		printf("%dth ", i + 1);
		printf("This Interval: ");
		printf("%d ", start_arr[i]);
		printf("%d ", end_arr[i]);
		printf("\n");
		*/
		for (j = 0; j < k; j++) {
			/*
			printf("%dth ", j + 1);
			printf("is now the checking Interval: ");
			printf("%d ", start_arr[j]);
			printf("%d ", end_arr[j]);
			printf("\n");
			*/
			if ( (i != j) && !((end_arr[i] < start_arr[j]) || (start_arr[i] > end_arr[j])))
				deg++;
		}
		/*
		printf("deg = ");
		printf("%d ", deg);
		printf("\n");
		*/
		if (max_deg < deg)
			max_deg = deg;
		if (min_deg > deg)
			min_deg = deg;
		deg = 0;
	}
	printf("Maximum Degree of G = ");
	printf("%d\n", max_deg);
	printf("Minimum Degree of G = ");
	printf("%d\n", min_deg);


	////***finding the chromatic color***
	// (by using of count_array)
	int count_arr_size = 0;
	int chromatic_number = 0;

	//finding the size of the max interal (to build a count_array)
	for (i = 0; i < k; i++) {
		if (count_arr_size < end_arr[i])
			count_arr_size = end_arr[i];
	}
	count_arr_size++; // cause we most include the specific 'end' value
	// creating a count_array & set 0's ...
	int *count_arr = (int *)malloc(count_arr_size * sizeof(int));
	for (i = 0; i < count_arr_size; i++)
		count_arr[i] = 0;

	/*
	//printing the new empty count_array
	printf("****your new empty count_array: \n");
	for (i = 0; i < count_arr_size; i++) {
		printf("%dth: ", i);
		printf("%d ", count_arr[i]);
		printf("\n");
	}
	*/

	//"installing & suming" the intervals langh to array
	for (i = 0; i < k; i++) { // running all the intervals
		for (j = start_arr[i]; j <= end_arr[i]; j++) // running about any interval range
			(count_arr[j])++;
	}

	/*
	//printing count_array after install & sum intervals
	printf("****count_array after install & sum intervals: \n");
	for (i = 0; i < count_arr_size; i++) {
		printf("%dth: ", i);
		printf("%d ", count_arr[i]);
		printf("\n");
	}
	*/

	//set chromatic number of g to the max value of count_array
	for (i = 0; i < count_arr_size; i++) {
		if (chromatic_number < count_arr[i])
			chromatic_number = count_arr[i];
	}
	printf("Chromatic Number of G = ");
	printf("%d\n", chromatic_number);


	////***finding complement***
	// (by formula)
	printf("G's Complement Edges = ");
	printf("%d\n", (k*(k-1)/2 - edgs));
	printf("Maximum Degree of G's Complement = ");
	printf("%d\n", (k - 1) - min_deg);
	printf("Minimum Degree of G's Complement = ");
	printf("%d\n", (k - 1) - max_deg);


	////***finding optinal coloring ***
	// (by greedy coloring algo..)
	
	int *intervalColors_arr = (int *)malloc(k * sizeof(int));
	int *usedColors_arr = (int *)malloc(k * sizeof(int));

	for (i = 0; i < k; i++) // just put zero's as the defult color for all intervals
		intervalColors_arr[i] = 0;

	for (i = 0; i < k; i++) {
		for (j = 0; j < k; j++) // clearing the used colors list
			usedColors_arr[j] = 0;
		for (j = 0; j < k; j++) {
			if ((i != j) && !((end_arr[i] < start_arr[j]) || (start_arr[i] > end_arr[j])))
				usedColors_arr[intervalColors_arr[j]]++;
		}
		j = 0;
		while (usedColors_arr[j] != 0) // finding the smallest color that not in use.
			j++;
			intervalColors_arr[i] = j;
	}

	//printing the sorters intervals with the colors
	printf("****Optional Coloring: \n");
	for (i = 0; i < k; i++) {
		printf("%dth ", i + 1);
		printf("Interval: ");
		printf("%d ", start_arr[i]);
		printf("%d ", end_arr[i]);
		printf("- color: %d", intervalColors_arr[i] + 1);
		printf("\n");
	}


	printf("\n***end of GreedyColoring!\n");

}