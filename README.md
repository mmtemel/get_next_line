<h1 align="center">
	<a href="https://en.wikipedia.org/wiki/C_(programming_language)"> <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/c/c-original.svg" alt="C Programming Language" width="100"height="100"></a>
	<a href="https://unix.org/"> <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/unix/unix-original.svg" alt="UNIX" width="100" height="100"></a>
	<br>
	Get Next Line
</h1>

The main objective of this project is to create a custom function that retrieves a line of text from a given file descriptor. This function is designed to be reusable, allowing subsequent calls to return the following line in the file. To ensure that the program is efficient and doesn't cause memory leaks, proper memory allocation and deallocation are critical components of the project. As such, the function will allocate memory for the line read from the file and free it once it has been processed to prevent memory leaks. This project requires careful consideration and implementation of these memory management techniques to ensure the program runs smoothly and effectively.

<h2>Usage</h2>
<h3>Requirements</h3>
The function is written in C language and thus needs the gcc compiler and some standard C libraries to run.

<h3>Instructions</h3>
<p><b>1. Using it in your code</b></p>

To use the function in your code, simply include its header:

<p><code>#include "get_next_line.h"</code> <p>
and, when compiling your code, add the source files and the required flag:

<p><code>get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=&#60;size&#62;</code></p>
<h2>Testing</h2>
<p>You only have to edit the get_next_line.c file and uncomment the main function and headers inside it. You can edit test.txt files to put another text if you wish to test othe cases. Then simply run this command (change "xx" with desired buffer size) :</p>

<code>gcc -Wall -Werror -Wextra -D BUFFER_SIZE=xx get_next_line.c get_next_line_utils.c -o get_next_line && ./get_next_line</code>
