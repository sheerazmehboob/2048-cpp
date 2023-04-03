<h1 align="center">2048 Game</h1>

<h2>Introduction</h2>
<hr>
<p>2048 is a puzzle game in which the player slides numbered tiles on a 4x4 grid. When two tiles of the same number touch, they merge into one tile with a value equal to the sum of the two. The objective of the game is to create a tile with a value of 2048.</p>
<p>This implementation of the game uses the console as its interface and the arrow keys to move the tiles. The game also features a score system that rewards the player for each merge they make and keeps track of the number of moves taken.
</p>

<h2>Features</h2>
<hr>
<p>The game includes the following features:<p>
<ul>
<li>Console-based interface</li>
<li>Arrow key controls</li>
<li>Score tracking</li>
<li>Highest score tracking</li>
<li>Pause and resume functionality</li>
</ul>

<h2>Pre-Requisites</h2>
<hr>
<ul>
<li>C++ compiler</li>
<li>conio.h library</li>
</ul>

<h2>How To Run?</h2>
<hr>
<ol>
<li>Clone this repository to your local machine or download the files.</li>
<li>Open the terminal and navigate to the project directory.</li>
<ul>
<li>For Windows</li>
<ol>
<li>Compile and run the 2048.cpp</li>
</ol>
</ul>
<ul>
<li>For Linux run file with the following command:</li>
<ol>
<li>g++ 2048.cpp -o 2048 </li>
<li>./2048 </li>
</ol>
</ul>
<li>Follow the instructions on the screen to play the game.</li>
</ol>

<h2>Rules of Game</h2>
<hr>
<ul>
<li>The game is played on a 4x4 grid.</li>
<li>Use arrow keys to move the tiles in different directions.</li>
<li>Tiles with the same number merge into one when they touch.</li>
<li>The game is won when a tile with a value of 2048 appears on the board.</li>
<li>The game is lost when there are no more moves to make.</li>
</ul>

<h2>Code Structure</h2>
<hr>
<p>The code is structured into several functions, each handling a specific task. Here is a brief explanation of each function:</p>
<ol>
<main(): Game will start from this function</li>
<li>display_board(): Displays the game board on the screen, along with the game instructions, score, moves, and highest score </li>
<li>first_turn(): Generates two random numbers 2 or 4 at random place</li>
<li>Generate_new_number(): Generates new numbers after every move </li>
<li>up_move(): Moves the tiles upwards on the board, combining them if they have the same value.</li>
<li>down_move(): Moves the tiles downwards on the board, combining them if they have the same value.</li>
<li>left_move(): Moves the tiles to the left on the board, combining them if they have the same value.</li>
<li>right_move(): Moves the tiles to the right on the board, combining them if they have the same value.</li>
<li>check(): Checks whether any tile is zero or not </li>
<li>check_win(): Checks whether the user wins the game </li>
<li>game_over(): Checks if the game is over (i.e., no more moves are possible).</li>
<li>generate_tile(): Generates a new tile with a value of either 2 or 4 at a random location on the board.</li>
<li>highest_score(): Checks and updates the highest score.</li>
<li>new_game(): Generates board and all requirement for a new game</li>
</ol>

<h2>Snapshots</h2>
<hr>

![gameIntro](https://user-images.githubusercontent.com/96474143/229614187-50a1935b-44ab-4759-bf7f-3daf749c7cb2.png)

![board](https://user-images.githubusercontent.com/96474143/229614217-ee8b7861-c600-43ed-a708-987d20670772.png)

![gamePlay](https://user-images.githubusercontent.com/96474143/229614235-ee5e42c6-ed9e-4934-b447-4c3b63c4e910.png)

