# graph_in_c
Test with the examples
For Example 1:
Create a test file:
bashecho "3 3
0 1
2 1
0 2" > test1.txt
Run the test:
bash./exercise < test1.txt
Expected output:
0: 2 1
1:
2: 1
For Example 2:
bashecho "5 4
0 3
1 3
2 1
0 4" > test2.txt

./exercise < test2.txt
Expected output:
0: 4 3
1: 3
2: 1
3:
4:
5. Interactive testing
You can also run it interactively:
bash./exercise
Then type:
3 3
0 1
2 1
0 2
Press Ctrl+D (EOF) to finish input.
6. Debug if needed
If you want to add debug information:
bashgcc -g -o exercise exercise.c graph.c
7. Clean up
To remove compiled files:
bashrm exercise
Alternative: One-liner compilation and test
bashgcc -o exercise exercise.c graph.c && echo "3 3
0 1
2 1
0 2" | ./exercise
