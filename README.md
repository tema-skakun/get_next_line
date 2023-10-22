# get_next_line

## Mandatory part

Calls (e.g., using a loop) to my get_next_line() function could let you read the text file pointed to by the file descriptor, one line at a time.

Because I have to read files in get_next_line(), added this option to your compiler call: -D BUFFER_SIZE=n. It define the buffer size for read().

## Bonus part

Here are the bonus part requirements:
    • Developed get_next_line() using only one static variable.
    • My get_next_line() can manage multiple file descriptors at the same time.

I can read from the file descriptors 3, 4 and 5, I can to read from a different fd per call without losing the reading thread of each file descriptor or returning a line from another fd.
It means that I can to call get_next_line() to read from fd 3, then fd 4, then 5, then once again 3, once again 4, and so forth.
