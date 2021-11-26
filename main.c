// first attempt at combine backwards, 26/11/21

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


const char * combine_backwards(char sentence1[], char sentence2[]);


int main(void) {

  // allocate space for each sentence with 500chars of memory
  char *sentence_1 = malloc(500 * sizeof(char));
  char *sentence_2 = malloc(500 * sizeof(char));
  // prompt the user for 2 sentences 
  printf("enter sentence 1:\n");
  // each character is scanned and stored in sentence_1 and sentence_2, and stops when a newline is found the \n char is read but is not included in the scan so that when scanf is used again it doesn't just stop due to it always reading the \n character. 
  scanf("%[^\n]%*c", sentence_1 );
  printf("\nenter sentence 2:\n");
  scanf("%[^\n]%*c", sentence_2 );
  // print the sentences without editing them. 
  printf("\nsentence1 %s\nsentence2 %s", sentence_1, sentence_2);
  // find the length of the senetences to enable a more precise amount of memory for the 'pointer' so that it has enough space to store both sentences and an extra one for the NULL character.  
  int length1 = strlen(sentence_1);
  int length2 = strlen(sentence_2); 
  char *pointer = malloc((length1 + length2 +1)* sizeof(char));
  // copy the result of combine_backwards onto pointer as memory was allocated in the combine combine_backwards function and it needs to be freed, so now 'pointer' and 'reversed_combined' pointers point to the same memory so freeing 1 of them frees both.  
  strcpy(pointer, combine_backwards(sentence_1 , sentence_2));
  // print the results of the reversed and mearged sentences. 
  printf("\n%s", combine_backwards(sentence_1 , sentence_2));

  //any time malloc is used it must be freed at some point to prevent memory leaks, this is the last part of the main function so any unfreed memory has to be freed here. 
  free(pointer);
  free(sentence_1);
  free(sentence_2);

  return 0;
}

const char * combine_backwards(char sentence1[], char sentence2[]){
  
  // declare variables 
  // lengths of input sentences are stored to allocate enough memory without having an excess amount
  int sentence1_length = strlen(sentence1);
  int sentence2_length = strlen(sentence2);
  
  // shortest and longest are used when deciding how the lists will be mearged as the longer list will have it's excess added on at the end. 
  int shortest, longest;
  // counters have been used to track positions in arrays, this was probably possible with for-loops but decided this was the easier route for me. 
  int counter_1 = 0;
  int counter_2 = 0;
  int counter_3, counter_4;
  // bigger_sentence is used to make it a big more obvious where the sentences have stopped merging and show where the unmerged part is being added. 
  char *bigger_sentence = malloc((sentence1_length+sentence2_length+1)*sizeof(char)); 
  // this is storage allocated for the reversed result of the merged sentences 
  char *reversed_combined= malloc((sentence1_length+sentence2_length+1)*sizeof(char)); 

  // printf("\nlengths %d %d", sentence1_length, sentence2_length);
  char *combined_lst = malloc((sentence1_length+sentence2_length+1)*sizeof(char));
  // this is where i've determined whih sentence is longer and have set their lengths to shortest and longestffd this information is used to work out when to stop merging the lists as the shorter one will run out of characters to merge. 
  if (sentence1_length < sentence2_length) {
    shortest = sentence1_length;
    longest = sentence2_length;
    bigger_sentence = sentence2; 

  }
  else{
    shortest = sentence2_length;
    longest = sentence1_length;
    bigger_sentence = sentence1;
  }
  

  // since the merged part is going to be twice that of the shortest sentence the for - loop goes from 0 to shortest*2 
  for (int i = 0; i<shortest*2; i++ ){
    // this if statement lets me alternate between lists so that each list will store 1 item after the other until. 
    if (i % 2 == 0){
      // stores the letters from sentence_1 in the combined_lst
    combined_lst[i] = sentence1[counter_1];
    // counter is used to remember position in the array
    counter_1++;
    }
    else {
      // stores letters from sentence_2 in the combined_lst 
    combined_lst[i] = sentence2[counter_2];
    counter_2++;
    }
  }
  // in the previous statements the two sentences were combined up until the shortest length they share, 
  // counter_3 is going to be used to add items to the next index from where they stopped merging.  
  counter_3 = shortest*2;
  for(int i = shortest; i < longest; i++){
    // here the last part of the bigger_sentence is added onto the end of the combined_lst.
    combined_lst[counter_3] = bigger_sentence[i];
    counter_3++; 
  }

  int combined_length = strlen(combined_lst);
  // counter is used to keep track of array position.
  counter_4 = 0; 
  // for loop is used to store the combined_lst in reversed order to the reversed_combined storage. 
  for (int i = combined_length-1; i>=0 ;i--){
    // printf("\n%c", combined_lst[i]);
    reversed_combined[counter_4] = combined_lst[i];
    counter_4++;

  }
  
  // memory is freed. 
  free(combined_lst);

  char *final_result = reversed_combined; 
  return final_result; 
}