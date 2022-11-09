# File-Compression System Using Huffman Coding in C++
The project is to design compression and decompression programs using Huffman Coding. The idea is to assign variable length codes to input characters based on their frequencies. The more the frequency of the character the shorter the code assigned to it.

#Implementation:

The program has been implemented in C++ language. The idea is to reduce the weighted expected storage by means of assigning shorter codes to frequently occurring characters.

#Compression:

Provide the input.
Note the frequency of all the characters in the input.
Construct a min priority queue with respect to the frequencies of the characters.
Construct Huffman Tree from the priority queue.
Encode the file, store the encoding table and compress the input based on the encoding table.

The codes are stored as bits and each character is provided a prefix code which is a string of bits.

![image](https://user-images.githubusercontent.com/113370126/200725768-3d1f4a4c-906f-4e73-83b5-2f74ee28f90e.png)

#Decompression:

Open the file and reconstruct the Huffman Tree based on the Encoded table.
Decode the file and store it to the desired file.

![image](https://user-images.githubusercontent.com/113370126/200725740-99b9e91b-67f3-411b-b28d-fc267eece50c.png)

#Finding Compression Rate:

A compression varying from 6-7% of the initial input file is achieved.

![image](https://user-images.githubusercontent.com/113370126/200725687-c985e97a-933e-4c22-a4e6-904cca9bef29.png)

#Output:
1) Codes -
![OutPut](https://user-images.githubusercontent.com/113370126/200725852-a50400b4-310e-4964-b8e7-04838b44b222.png)

2) Output -
![OutPut1](https://user-images.githubusercontent.com/113370126/200725868-b5d7cafb-932c-479f-816d-f10380771a39.png)

