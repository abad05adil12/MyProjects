class Book:
    def __init__(self):
        self.books = {}  
    
    def add_book(self):
        title = input("Enter title of the book: ")
        author = input("Enter author of the book: ")
        isbn = input("Enter ISBN of the book: ")
        self.books[title] = {'title': title, 'author': author, 'isbn': isbn}
        print(f"Book '{title}' added successfully!")

    def show_books(self):
        if not self.books:
            print("No books available.")
        else:
            print("\nAvailable Books:")
            for book in self.books.values():
                print(f"Title: {book['title']}, Author: {book['author']}, ISBN: {book['isbn']}")

class Member:
    def __init__(self):
        self.members = {}  
        self.borrowed_books = {}  

    def add_member(self):
        name = input("Enter name of the member: ")
        member_id = input("Enter member ID: ")
        if name in self.members:
            print(f"Member '{name}' already exists.")
        else:
            self.members[name] = {'name': name, 'member_id': member_id}
            self.borrowed_books[name] = [] 
            print(f"Member '{name}' added successfully!")

    def borrow_book(self, book_manager):
        name = input("Enter member's name: ")
        if name not in self.members:
            print("Member not found!")
            return

        if len(self.borrowed_books[name]) >= 3:
            print("You can borrow only up to 3 books.")
            return

        book_title = input("Enter the book title to borrow: ")
        if book_title not in book_manager.books:
            print("Book not available!")
            return

        self.borrowed_books[name].append(book_title)
        print(f"Book '{book_title}' borrowed successfully by {name}!")

    def return_book(self):
        name = input("Enter member's name: ")
        if name not in self.members:
            print("Member not found!")
            return

        if not self.borrowed_books[name]:
            print("No borrowed books to return.")
            return

        book_title = input("Enter the book title to return: ")
        if book_title not in self.borrowed_books[name]:
            print("This book was not borrowed!")
            return

        self.borrowed_books[name].remove(book_title)
        print(f"Book '{book_title}' returned successfully!")

    def display_members(self):
        if not self.members:
            print("No members found.")
        else:
            print("\nRegistered Members:")
            for member in self.members.values():
                print(f"Name: {member['name']}, Member ID: {member['member_id']}")
                borrowed = ", ".join(self.borrowed_books[member['name']]) or "None"
                print(f"  Borrowed Books: {borrowed}")

    def display_menu(self, book_manager):
        while True:
            print("\nLibrary Menu:")
            print("1. Add Book")
            print("2. Show Books")
            print("3. Add Member")
            print("4. Borrow Book")
            print("5. Return Book")
            print("6. Show Members")
            print("7. Exit")

            choice = input("Enter your choice: ")
            if choice == "1":
                book_manager.add_book()
            elif choice == "2":
                book_manager.show_books()
            elif choice == "3":
                self.add_member()
            elif choice == "4":
                self.borrow_book(book_manager)
            elif choice == "5":
                self.return_book()
            elif choice == "6":
                self.display_members()
            elif choice == "7":
                print("Exiting program.")
                break
            else:
                print("Invalid choice, please try again.")

book_manager = Book()
member_manager = Member()
member_manager.display_menu(book_manager)