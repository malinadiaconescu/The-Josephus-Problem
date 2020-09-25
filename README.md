# The-Josephus-Problem
Solving the Josephus problem with circular lists.
## The Problem
People are standing in a circle waiting to be executed. Counting begins at a
specified point in the circle and proceeds around the circle in a specified di
rection. After a specified number of people are skipped, the next person is
executed. The procedure is repeated with the remaining people, starting with
the next person, going in the same direction and skipping the same number of
people, until only one person remains, and is freed.<br/>
The problem - given the number of people, starting point and number to
be skipped - is to choose the position in the initial circle to avoid execution.
## The Algorithmic Part
The algorithm is easy: we will have a circular list and we keep on erasing nodes
until we are left with only one node, which is, in fact, the position that survives.
We will only have to go one way and will have a variable that counts the positions
traveled.
## The Implementation
It took me some full days to implement this (not knowing what classes are
exactly), but I mainly implemented this by the golden rule of programming:
"write it, make it work, make
it work better".<br/>
First, I created a class for a node of the list. This contains the value of the
node and an address to the next node. I made this class to simplify my work
and in my head made more sense, because the list I needed to implement needed
to contain more nodes. This way, the class created for a node makes everything
more clearer and accessible.<br/>
To be honest, in my first day of implementing this project I only tried to make an unique class for the node, but then I realized that I do not exactly know how
to implement the rest of the methods inside the class, I was able to do them
only outside the class, as functions. That was because I did not find a way to
get to the next node. On my second day on this homework, I found this solution
that I was able to finish it.<br/>
For my list, I created a new class that is formed of one node (the node I explained before). Besides the constructor of the class, I also added new methods:
add node, print elements, delete element and josephus.
### ADD_NODE METHOD
This one was very easy to implement. I just searched for the last node and I
tied the new node to the last one. The address for the last one changed to the
new node and the address of the new node takes us to the first node of the list.
### PRINT_ELEMENTS METHOD
This contains a dofgwhile that works until we get again to the first note. It
prints the data of each element and then go to the next one.
### DELETE_ELEMENT METHOD
This one was a bit tricky for me to find a way to solve. I thought that I solved
until I got to the Josephus part of the project and my program got in an infinite
loop because I forgot to delete the pointer from the memory. Once I deleted the
address of the pointer in memory, everything worked just fine.<br/>
The way I thought to do this was the following: I tied the node before the
node to be erased to the next node after it. I used auxiliary pointers to re
member their addresses and I deleted the address of the pointer that we needed
deleted.<br/>
I transmitted as a parameter the value to be erased because I think it sim
plifies the work. Moreover, I read the Josephus problem and I understand that
there are n people in the game. Numbering them like the first man, the second
man,..., the nth man, led us to having unique values (having in mind that the
problem says that the xth man is taken out of the game, where x is between 1
and n, this also is an argument of using an integer value as parameter).
### JOSEPHUS METHOD
Josephus method of the class List basically solves the Josephus Problem. As I
said before, solving the delete an element part of the homework played a huge
role in implementing this method, because I used a little part of the code.
First, it gets to the value we need to start the algorithm from with the help
of while. It is an easy crossing of the list.<br/>
What Josephus method does is easy: it runs until we have more than one
node in the list and deletes the pasth element, where pas is transmitted as a
parameter. The method returns the value of the remained element.
### Encountered Problems
I think the action of starting on working on this project was the worst. Like, I
knew exactly what my program has to do but I did not know how to write it.
It took me some hours of staying at the desk and just thinking of how I should
do what I had to do and designing the code. As I said before, I have another
code where I have an unique class, but the methods are functions outside the
class, which worked more than fine, but it looked more like a high school-level
coding.<br/>
Another problem I had mentioned before was the part of deleting an element,
which took me around 2 days to solved honestly:)), but I am glad that I could.
Another issue worth mentioning was using the this pointer in C++. This way,
my program is capable of sustaining more than one object of the type list.<br/>
Another issue I had was when I tried removing the first element (the one with
the value 1) form the list. Why? Because my program got confused about
where it should start the print method, the first element being deleted from the
memory. I fixed that by remembering what the first value was before deleting
anything (first->data), and setting that by being minim. If the user will try to
erase a value that is equal with minim, the head will be changed. If I did not do
this, my program run into an infinite loop when trying to print the elements.
### What can my program do?
Not only it does solve the Josephus problem, my program also represents a good
template for circular lists that can be used for other problems. It has the most
important things that you need: it creates a list, it inserts new elements and
deletes certain elements that you need. I tried some things with my program
in order to verify if it works before submitting it in and I want to share with you:
- I tried different values for pas. Which worked just fine. Every time, I
was left with a single value. My program did not run in any infinite loop like it
did when I did not have the "delete" element in delete element.
- I tried adding just one new element to an empty list. Initially, I tried doing this before adding anything else. Just treating the problem casually did
not worked for me. This is why my program checks if the list is empty or not.
- I think it is a special case.
- I tried having more lists. This is how I got to the point of using this pointer.
- I tried deleting all the elements of the list. The list will contain NULL
when this happens. Also, the program will output something like "The list is
empty".
Another important episode of the implementation of this program would be
being able to print all the elements without running into an infinite loop. I
know it is not much, but I was proud very proud of myself when I done it. :)
- I tried removing different values from the list. This is regarding the issue
- I had mentioned before. It works well anything you would remove from the list.
Even if you remove the value 1 and then the value 2, it works well because my
program knows which is the first value (aka the most little one) and does its job.
- I tried having more nodes with the same value and trying to delete
that value. Which is why my program only deletes the first node with the
value given through parameter. This simplifies things and you know exactly
what you delete. <br/> P.S.: everything I said I had tried, it works in the final form of the code.
