#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define readString(x) freadString(x, stdin)

#define VALID_INSTRUCTIONS "+-<>.,[]"

#define EMULATED_MEM_SIZE 3000



char* freadString(char breakChar,FILE *rfile){ // '\0' reserved, read until EOF
	#define INITIAL_SIZE 100
	#define INCREMENT_SIZE 50


    char* str = (char*)malloc(INITIAL_SIZE * sizeof(char));
    if(str == NULL){
        fprintf(stderr, "ERROR: string malloc() FAILED\n");
        exit(2);
    }

    char tempC = '\0';
    int i = 0;
    int currentSize = INITIAL_SIZE;
    while(tempC != EOF){
        tempC = fgetc(rfile);

        if (i == currentSize) {
            currentSize += INCREMENT_SIZE;
            char* tCh = realloc(str, currentSize * sizeof(char));
            if (tCh==NULL){
                free(str);
                break;
            }
            str = tCh;
        }

        if (tempC == breakChar){
            str[i] = '\0';
            break;
        }
        str[i] = tempC;
        i++;
    }
    if(tempC == EOF){
		if(breakChar == '\0'){
			str[i-1] = '\0';

            char* tCh = realloc(str, i * sizeof(char)); //resize to take up least space possible
            if (tCh==NULL){
                free(str);
                exit(2);
            }
            str = tCh;
		}
		else{
			free(str);
        	str = NULL;
            fprintf(stderr, "ERROR: reached EOF mid read!");
		}
    }
	return str;
}


//====== input parsing
//------ code handling



int run_code(char *code, int *instruction_pointer, char* memory, int *mem_pointer){
	while(true){

		char current_instruction = code[*instruction_pointer];


		*instruction_pointer += 1;



		if(current_instruction == '\0'){ return 1; } //* reached end of code

		// printf("%c; int_ptr:%d; mem_ptr:%d; mem:%d\n", current_instruction, *instruction_pointer, *mem_pointer, memory[*mem_pointer]);


		//* value shift
		if(current_instruction == '+'){ memory[*mem_pointer] += 1; }
		
		else if(current_instruction == '-'){ memory[*mem_pointer] -= 1; }
		
		//* ptr shift
		else if(current_instruction == '>'){
			*mem_pointer += 1;
			if(*mem_pointer >= EMULATED_MEM_SIZE){
				*mem_pointer = 0;
			}
		}

		else if(current_instruction == '<'){
			*mem_pointer -= 1;
			if(*mem_pointer < 0){
				*mem_pointer = EMULATED_MEM_SIZE-1;
			}
		}

		//* I/O
		else if(current_instruction == '.'){ printf("%c", memory[*mem_pointer]); }

		else if(current_instruction == ','){
			char temp_ch = getchar();
			if(temp_ch == EOF) temp_ch = 0;
			memory[*mem_pointer] = temp_ch;
		}

		//* Loop
		else if(current_instruction == '['){
			int check_mem_ptr = *mem_pointer; // save the cell to watch
			int instruction_return_ptr = *instruction_pointer;
			
			while(memory[check_mem_ptr] != 0){ // end execution of loop when check mem is zero
				*instruction_pointer = instruction_return_ptr;
				//printf("entering loop\n");
				int ret = run_code(code, instruction_pointer, memory, mem_pointer);
			
				if(ret == 1) return 1; //* program EOF
			}
		}

		else if(current_instruction == ']'){ return 0; }


	}
}




int main(int argc, char *argv[]){

	char *code_string = freadString('|', stdin);
	
	// printf("%s\n", code_string); //TODO RM
	
	char memory[EMULATED_MEM_SIZE];
	for(int i=0; i<EMULATED_MEM_SIZE; i++){
		memory[i] = 0;
	}

	int instruction_ptr = 0;
	int emulated_mem_ptr = 0;

	run_code(code_string, &instruction_ptr, &memory[0], &emulated_mem_ptr);

    putchar('\n');

	return 0;
}