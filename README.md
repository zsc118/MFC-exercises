# MFC-exercises

Some exercises in the realm of MFC frameworks.

## Exercise 1: Mouse and Keyboard
Please craft a multi-document program with the following specifications:

1. Continuously exhibit the positional status of the mouse within the client area. If a click occurs, present a dialog box informing the user of the pressed mouse button.
2. When the user presses the SHIFT or CTRL key, present a dialog box indicating which key has been pressed.

## Exercise 2: Utilizing CDC in the CView Class

Employ MFC (single-document) to automatically render a sine curve. Specifications include: the sine curve is black with a width of 2, and the coordinate system is red with a width of 1.

## Exercise 3: MFC Standard Controls

Devise a user survey form as depicted in the image:

![](./image/1.png)

Upon the user's selection of the "OK" button, employ a static text control to exhibit all the user's information, akin to the illustration below:

![](./image/2.png)

## Exercise 4: MFC Resource Class

Construct a single-document application encompassing a menu, toolbar, and status bar. Requirements are as follows:

1. Within the main menu bar, introduce a menu item titled "My Menu" with two sub-options: "Color" and "Font." Upon user selection, prompt color and font dialogs to modify the appearance of the displayed "Hello World" text in the document.
2. Add buttons to the toolbar, ensuring their functionalities mirror those of the corresponding menu items.
3. Append two information bars in the status bar to display the mouse's x and y coordinates. As the mouse moves, the pointer's coordinates in the status bar should dynamically update.

## Exercise 5: Commonly Used Classes in MFC

Develop a straightforward clock application.

## Exercise 6: Utilization of MFC Controls

Conceive a calculator with the following functionalities: addition, subtraction, multiplication, division, square root, reciprocal, and modulus. Display the input data, intermediate results, and final outcome in a singular label at the top of the window.

Ensure that "0" cannot serve as a divisor. The "Backspace" button should erase the last input, while the "Clear" button should reset all entered data.

## Exercise 7: MFC Database Application

Establish an SDI application supporting ODBC or ADO for a database. Implement the following features:

1. Retrieve records from the "studentmarks.mdb" (student grades table) table, enabling navigation through the records (previous, next, last, first).
2. Empower users to add, modify, and delete records.
3. Implement sorting based on grades.
4. Enable searching for all grades of a student by their name.

## Exercise 8: MFC Network Programming

Construct a straightforward network chat application facilitating communication between a client and a server.
