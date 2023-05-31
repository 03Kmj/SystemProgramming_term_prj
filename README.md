# Similarity Check Application

## Overview
Similarity Check is a command-line application that calculates the similarity between C code files. It compares a main file with a set of sub files and generates a similarity score for each comparison. The application uses a progress bar to indicate the progress of each comparison and stores the results in a text file.

## Features
- Drag and drop C code files for comparison
- Display progress bar for each comparison
- Generate similarity scores and store them in a result file
- Print colored similarity results

## Prerequisites
- C compiler (gcc or any compatible compiler)
- GTK library
- GIO library

## Usage
1. Compile the source code: gcc test.c -o test `pkg-config —cflags —libs gtk+-3.0`
2. Execute the application: ./similarity_check
3. Drag and drop the C code files you want to compare into the application window. The main file will be automatically selected as the first file, and the rest will be treated as sub files.

4. Click the "Start Similarity Check!" button to begin the comparison process.

5. The application will display a progress bar for each sub file, indicating the progress of the comparison.

6. Once the comparison is completed, the similarity scores will be stored in the "similarity_result.txt" file.

7. The application will print the similarity results, highlighting them with different colors based on the similarity score.

## Note
- The application assumes that the main file and sub files are C code files (.c extension).
- Ensure that the "ls_c" command is available in the current directory to list available C code files. If not, you can modify the code to use a different mechanism for listing the files.

## License
This project is licensed under the [MIT License](LICENSE).

