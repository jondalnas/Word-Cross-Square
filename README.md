# Word Cross Square
A cli based word cross square generator

## What is a word cross square?
A word cross square is a square of two words of same length, who match eachother on a specific character, placed in a cross.

<pre>
 c 
good
 o
 k
</pre>
 
 ## How to use
 First of all, you need to compile the binaries, to do this, run the make command
 
 <pre>make</pre>
 
 Then get a dictionary file (You can get many of them from [here](https://github.com/titoBouzout/Dictionaries)) and place it in the dic/ folder.
 
 Run the program, specifying what dictionary to use, how long the word should be and which character to match
 
 <pre>./a.out DICTIONARY_LOCATION WORD_LENGTH MATCH_LOCATION</pre>
 
 ## TODO List
 - [x] Add support for other dictionaries
 - [ ] Add stdin loading of dictionaries
 - [ ] Add more descriptive help screen
 - [ ] Add specific word searching
