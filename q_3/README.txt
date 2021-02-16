To compile this program:

1. Run the command: "make"

To run this program:
2. Run: "sudo ./set_policy <policy number><priority number>"
3. In a different terminal (but on the same directory) run: "chrt -p <pid>" with the server's pid printed on the first terminal you opened

If you'd like to compile and run it at once, run: "make && sudo ./set_policy <policy number><priority number>" and go back to step 3
If you'd like to erease compiled files run the command: "make clean"

** Note: policies 1 and 2 must run with priority larger than 0 **

