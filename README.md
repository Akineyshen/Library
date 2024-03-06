# Project "The Library"

This project is a library management program that provides functions for adding, deleting, editing, and searching for books. Users can easily find books by author name, title, or year of publication. The program also allows viewing a list of all books with detailed information and sorting them by various criteria.

**1. Adding a book to the file:** The user can enter information about the book, including the author, title, category, year of publication, publisher, and availability. If the user enters an invalid value for availability (not 0 or 1), the program issues an error and prompts to enter the value again.

**2. Removing a book from the file:** The user can specify the number of the book in the list and delete it from the file.

**3. Editing a book: The user selects a book and can edit any information about it.**

**4. Finding a book:** The user can search for books by author name (partial input is allowed), title (partial input is allowed), year of publication, or availability. When searching by availability, the user is prompted to choose to display available or unavailable books.

**5. Viewing all books:** The user can view a list of all books, displaying only the title and author. Then the user is prompted to view detailed information about the selected book, with the option to confirm or decline the viewing. If declined, the user returns to the main menu.

**6. Sorting books:** The user can sort books by author and title in alphabetical order, as well as by availability (available books are displayed first, then unavailable ones).

**7. Saving changes to the file:** After making changes to the library, the user can save them to a text file. It is important to note that if the user exits the program without saving, the changes will not be reflected in the next program run. Therefore, it is recommended to save changes after each session with the program. All information about the books is stored in a text file for convenience in working with data.

**8. Exiting the program:** The user can exit the program.

_The code for this program was written using Code Block IDE in the C programming language and compiled with the MinGW compiler._
