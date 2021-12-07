#include <stdio.h>
#include <iostream>


// number of frames.
int number_of_frames; 

// total size of reference strings.
int size_of_ref;      

// hold current number of frame
int current_size;         

int get_index(int[], int[], int);
void main_algo(int[]);


int main(){

    // taking input

    // printf("Length of the reference string\n");
    scanf("%d", &size_of_ref);

    int reference_string[size_of_ref];
    
    // printf("Reference string\n");
    for(int i = 0; i < size_of_ref; ++i){
        scanf("%d", &reference_string[i]);
    }

    // printf("Size of frame\n");
    // scanf("%d", &number_of_frames);
    number_of_frames = 3;

    main_algo(reference_string);

    return 0;
}


void main_algo(int reference_string[]){
    int page_fault_count = 0; // store number of misses

    int frames[number_of_frames]; 
    int reference, found, rep_ind;

    for(int i = 0; i < number_of_frames; i++){
        frames[i] = -1;
    }


    for(int i = 0; i < size_of_ref; i++){
        reference = reference_string[i];
        found = 0;

        // if there are empty frames
        for(int i = 0; i < current_size; i++){
            if(frames[i] == reference){
                found = 1; // we find the reference
            }
        }

        if(found){ // page hit for current reference
            continue;
        }

        // page fault
        page_fault_count++;

        // if frames is empty
        if(current_size < number_of_frames){
            // add a page to the first empty frame
            frames[current_size] = reference;

            current_size++;
            continue;
        }

        rep_ind = get_index(reference_string, frames, i); 

        // replace the page which has the farthest next referene with next page
        frames[rep_ind] = reference;

        }

    // printf("Page Faults\n%d", page_fault_count);
    printf("%d\n", page_fault_count);
} 

int get_index(int reference_string[], int frames[], int curr_ind){

    int min_occu = -1, repInd = -1;
    int occurences;
    int j;

    for(int i = 0; i < number_of_frames; i++){
        occurences = 0;

        j = curr_ind - 1;

        while( (j >= 0) && (j > curr_ind - 4)){

            if(frames[i] == reference_string[j] ){
                occurences++;
            }
            j--;
        }

        j = curr_ind + 1;

        while( (j < curr_ind + 4) && (j < size_of_ref) ){

            if(frames[i] == reference_string[j] ){
                occurences++;
            }
            j++;
        }



        if(occurences <= min_occu){
            if(repInd == -1){
                min_occu = occurences;
                repInd = i;
                
            }else if (repInd != -1 && frames[i] < frames[repInd]){
                min_occu = occurences;
                repInd = i;
            }
        }
    }

    return repInd;
