#-----------**Libraries I used**--------------

# - used <map> :
    > obviously u have to use it to store locations of characters that are inside the board.

# - use include <windows.h> :
    > ✿ for SetConsoleOutput so i can print unicode chars in terminal ✿ 
                (to make the ouija board look maybe moree niceeee than boring.)

    to use these unicode characters we have to write this line inside main()

-->     **SetConsoleOutputCP(CP_UTF8);**
        std::cout << "˖ ᡣ𐭩 ⊹ ࣪ ˚₊" << std::endl;

# - <thread>  
    use it specifically for 
    ✿ std::this_thread::sleep_for()
    without this c++ can't control time delay
# - <chrono>
   *how long to freeze*
    ✿ std::chrono::seconds(1) = exactly 1 second.
# - <cstdlib>  
    ✿ Needed for rand() and srand()
# - <ctime>    
    ✿ Needed for time()


                                ──── ୨୧ ────

# why use std::flush
    so when we print using std::cout yk it is stored in a temp storage area called buffer. C++ waits until this buffer/bucket sees a newline charac \n and then prints everything on screen. 
    When we have to use animations or changing text colors we are obvs not using  \n and so the change of color won't be shown on screen at the time we want it to. 
   *std::flush: Forces the terminal to update the screen immediately.*
    std::endl; does the same thing. endl creates a \n and then calls std::flush nd empties the buffer.
        **~~jus search it up if u don understand~~**

# for (char letter : word) { ..... }
    reads each letter one at a time of a string. 
    for example if word = FUCK
    then first loop F second loop U then third loop C and on and on.

#   int row = pos[letter].first; *grabs the Row you saved in your map for that letter.*
#   int col = pos[letter].second; *grabs the Column you saved in your map for that letter.*
    create variables row/col and store (for example) pos['A']={5 , 12} so 5 is stored in row and 12 in col.
    That's how you get the location of where a character is placed. 

     For testing you can try printing the row and col of that character like this:
     ✿ std::cout << letter << " is at Row " << row << ", Column " << col << "\n"; 

# std::cout << "\033[" << row << ";" << col << "H" << "\033[31m" << letter << "\033[0m" << std::flush;

    "\033[" << row << ";" << col << "H"
    This tells the terminal cursor where to jump.
-----*If row is 5 and col is 12, C++ sends **\033[5;12H**. The terminal reads that H at the end and immediately teleports the cursor to Row 5, Column 12.*-----
    << "\033[31m" << ~ "Every character you print after this line must be drawn in Red ink."
    << letter     << ~ This would print the "actual letter" in red. (or wtv color u use)
    << "\033[31m" << ~ "resets the terminal back to normal white text. If we don write this everything printed after
                        this line would stay red."

✿✿✿✿✿✿✿

srand(time(0)); --> We use it so everytime it chooses a random answer so there won't be like any pattern for choosing.

✿✿✿✿✿✿✿

# - placeText()
    used std::string text --> so I could print words like YES and NO and ABCD... in a single line easily without writing a single char one by one.

    addToMap: A simple True/False switch. If True, the letter locations are stored. If False, the text is printed but location is not stored inside pos. Use this because if you don't then i don wan tto explain. You can check yourself what happens if u don use that.

    grid[row][col] = c;  --> This jus places the letter on that specific row nd col

    if (addToMap) { pos[c] = {row, col}; }  --> This saves the location in the pos map.

    col += spacing; --> This jus adds up the spacing.

*JUS SEARCH UP AND ASK SOME AI*

anywayss

✿✿✿✿✿✿✿

# - renderBoard()
 ~   Drawing the Top Border:

    "+" prints the top-left corner.

    std::string(WIDTH, '-') creates a string of hyphens ----- exactly 50 characters wide (based on our WIDTH constant).

    "+" prints the top-right corner.

    std::endl moves to the next line.

    Result: +--------------------------------------------------+

 ~   for (int i=0 ; i < HEIGHT ; i++) { --> loops through every row

 ~   std::cout << "|" << grid[i] << "|" << std::endl;
            -->  grid[i] prints the actual string of text (letters, numbers, or spaces) stored in row i of our grid.

 ~ Ig that was pretty much it. Its easy.

✿✿✿✿✿✿✿

# - spellWord()
    now here *int answerCol = 10;* --> This would print the selected random answer in the 10th col of the umm I forgot the row. OH yes the row number is 20. 

    if (letter == ' ') {
            std::cout << "\033[20;" << answerCol << "H " << std::flush;
            answerCol++;
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
            continue;
        }
Handling Spaces: If the spirit is spelling a multi-word answer (like "LOOK BEHIND"), a space doesn't exist on the board.

It teleports to Row 20 at answerCol and prints a blank space.

Advances answerCol by 1.

Pauses briefly (300ms) so the typing rhythm feels natural, then skips the rest of the loop (continue).

other than that we added +3 to the row (accounting for the top border + terminal offset) and +2 to the column (accounting for the left border | + 1-based indexing).