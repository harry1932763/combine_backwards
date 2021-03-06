/* Author : Harry Dean
   Date.  : 27/11/21
   version: 1.1
*/  

#include <stdio.h> /*printf(), scanf()*/
#include <string.h> /*strlen(), strcpy()*/
#include <stdlib.h> /*malloc(), free()*/

const char * combine(char input_sentence_1[],char input_sentence_2[]); /*function proto-type */
const char * reversed(char string_array[]); /*function proto-type */

int main(void) {
  // varibles to store user inputted sentences
  char input_sentence_1[100];
  char input_sentence_2[100]; 
  // since the combine returns a pointer another pointer pointing to the same thing has to be used and freed in the main function. 
  char *result_of_merge = malloc(200 * sizeof(char));
  char *result_of_reverse = malloc(200 * sizeof(char));
  // prompt user for sentences
  printf("\nenter first sentence\n");
  // scan console until a newline is found, %*c reads the \n but doesn't scan it into input_sentence_1, this is to prevent scanf("%[^\n]") from cancelling imidietly. 
  scanf("%[^\n]%*c", input_sentence_1);
  printf("enter second sentence\n");
  scanf("%[^\n]%*c", input_sentence_2);
  // print the users sentences for easier comparison and comfirmation of the code working
  printf("sentence 1_________: %s\nsentence 2_________: %s", input_sentence_1, input_sentence_2);
  // the memory needs to be freed from reversed lst which is stored onto result_of_merge so freeing result_of_merge which points to the same memory as reversed_lst frees both. 
  strcpy(result_of_merge, combine(input_sentence_1,input_sentence_2)); 
  strcpy(result_of_reverse, reversed(result_of_merge));
  // print the result which was stored in result_of_merge 
  printf("\nmerged_____________: %s", result_of_merge);
  printf("\nreversed merge_____: %s", result_of_reverse);
  // free the memory that result_of_merge is pointing to. 
  free(result_of_merge); 
  free(result_of_reverse);
  return 0;
}

const char * combine(char input_sentence_1[],char input_sentence_2[]){
  // declare variables
  // smaller_lst & longer_lst are used to determine which list is bigger, 
  // the lengths are also used for the same reason 
  int smaller_lst, longer_lst, length_sentence_1, length_sentence_2; 
  // store the length value onto the variables.  
  length_sentence_1 = strlen(input_sentence_1);
  length_sentence_2 = strlen(input_sentence_2); 
  // biggest_lst will be used to deal with the last part of the array which can't be merged with the other due to it being shorter. 
  char *biggest_lst = malloc((length_sentence_1+length_sentence_2+1)*sizeof(char));
  // combined_lst will store the merged list of sentence_1 and sentence_2
  char *combined_lst = malloc((length_sentence_1+length_sentence_2+1)*sizeof(char)); 
  // this if else statement will determine which sentence is the bigger and smaller one and copy the sentence on to the biggest_lst 
  if (length_sentence_1 > length_sentence_2){
    smaller_lst = length_sentence_2;
    longer_lst = length_sentence_1;
    strcpy(biggest_lst, input_sentence_1);
  }
  else{
    smaller_lst = length_sentence_1;
    longer_lst = length_sentence_2;
    strcpy(biggest_lst, input_sentence_1);
  }
  //counters to through the input sentences 1 index at a time. 
  int sentence_1_counter = 0;
  int sentence_2_counter = 0;
  // smaller_lst*2 has been choosen as the two sentences will merge as long as they are equal length i've decided to sort out the merging parts first and then add the last part of the bigger file onto the end. 
  for (int i = 0; i < smaller_lst*2; i++){
    // this if stament acts as a switch every time 'i' is even the sentence_1 index gets added to the combined list and when 'i' is odd the sentence_2 gets added, taking turn which results in the merge. 
    if (i % 2 == 0){
    combined_lst[i] = input_sentence_1[sentence_1_counter];
    // increament the counter so the next index of sentnce_1 is added each time 
    sentence_1_counter++;
    }
    else{
      combined_lst[i] = input_sentence_2[sentence_2_counter];
      // increament the counter so the next index of sentnce_2 is added each time 
      sentence_2_counter++;
    }
  }
  // the biggest_lst_counter is equal to the smaller_lst and that's where the merge stopped happing.
  int biggest_lst_counter = smaller_lst; 
  for (int i = smaller_lst*2; i < (length_sentence_1+length_sentence_2); i++){
    // adding the last parts of the bigger_lst to the combined_lst 1 item at a time.
    combined_lst[i] = biggest_lst[biggest_lst_counter];
    // increament the counter so the next index of biggest_lst is added each time
    biggest_lst_counter++; 
  }
  free(biggest_lst);
  return combined_lst;
} 

const char * reversed(char string_array[]){
  int string_length = strlen(string_array);
  char * reversed_lst = malloc((string_length) * sizeof(char));
  // counter is used to keep track of array position.
  int counter_4 = 0; 
  // for loop is used to store the combined_lst in reversed order to the reversed_combined storage. 
  for (int i = string_length-1; i>=0 ;i--){
    // store each combined_lst 1 item at a time in reversed_lst. 
    reversed_lst[counter_4] = string_array[i];
    counter_4++;
  }
  return reversed_lst;
}