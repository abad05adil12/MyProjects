import tkinter as tk
from tkinter import ttk, messagebox

guests = []
rooms = {101: "Available", 102: "Available", 103: "Available",
         104: "Available", 105: "Available", 106: "Available",
         107: "Available", 108: "Available", 109: "Available",
         110: "Available", 111: "Available", 112: "Available",
         113: "Available",
         114: "Available", 115: "Available", 116: "Available",
         117: "Available", 118: "Available", 119: "Available",
         120: "Available", 121: "Available", 122: "Available",
         123: "Available", 124: "Available", 125: "Available",
         126: "Available", 127: "Available", 128: "Available",
         129: "Available", 130: "Available", 131: "Available",
         132: "Available", 133: "Available", 134: "Available",
         135: "Available", 136: "Available", 137: "Available",
         138: "Available", 139: "Available", 140: "Available",
         141: "Available", 142: "Available", 143: "Available",
         144: "Available", 145: "Available", 146: "Available",
         147: "Available", 148: "Available", 149: "Available",
         150: "Available", 151: "Available", 152: "Available",
         153: "Available", 154: "Available", 155: "Available",
         }

class LoginWindow(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("Hotel Management Login")
        self.geometry("300x200")
        
        tk.Label(self, text="Username").pack(pady=5)
        self.username = tk.Entry(self)
        self.username.pack()

        tk.Label(self, text="Password").pack(pady=5)
        self.password = tk.Entry(self, show="*")
        self.password.pack()

        tk.Button(self, text="Login", command=self.check_login).pack(pady=20)

    def check_login(self):
        user = self.username.get()
        pwd = self.password.get()
        if user == "admin" and pwd == "admin":
            self.destroy()
            app = MainApp()
            app.mainloop()
        else:
            messagebox.showerror("Login Failed", "Incorrect credentials!")

class MainApp(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("Hotel Management Dashboard")
        self.geometry("800x500")
        self.minsize(150,250)
        self.maxsize(900,600)
        nav = tk.Frame(self, bg="gray")
        nav.pack(side="left", fill="y")

        tk.Button(nav, text="Guest Registration", width=20, command=self.show_registration).pack(pady=10)
        tk.Button(nav, text="Room Booking", width=20, command=self.show_booking).pack(pady=10)
        tk.Button(nav, text="Billing", width=20, command=self.show_billing).pack(pady=10)

        self.main_frame = tk.Frame(self, bg="white")
        self.main_frame.pack(expand=True, fill="both")

    def clear_frame(self):
        for widget in self.main_frame.winfo_children():
            widget.destroy()

    def show_registration(self):
        self.clear_frame()
        tk.Label(self.main_frame, text="Guest Registration", font=("Arial", 16)).pack(pady=10)

        name_var = tk.StringVar()
        phone_var = tk.StringVar()

        tk.Label(self.main_frame, text="Name").pack()
        tk.Entry(self.main_frame, textvariable=name_var).pack()

        tk.Label(self.main_frame, text="Phone").pack()
        tk.Entry(self.main_frame, textvariable=phone_var).pack()

        def register():
            name = name_var.get()
            phone = phone_var.get()
            guests.append({"name": name, "phone": phone})
            messagebox.showinfo("Success", f"Guest {name} registered!")

        tk.Button(self.main_frame, text="Register Guest", command=register).pack(pady=10)

    def show_booking(self):
        self.clear_frame()
        tk.Label(self.main_frame, text="Room Booking", font=("Arial", 16)).pack(pady=10)

        name_var = tk.StringVar()
        room_var = tk.IntVar()

        tk.Label(self.main_frame, text="Guest Name").pack()
        tk.Entry(self.main_frame, textvariable=name_var).pack()

        tk.Label(self.main_frame, text="Select Room").pack()
        room_box = ttk.Combobox(self.main_frame, textvariable=room_var)
        room_box['values'] = [room for room, status in rooms.items() if status == "Available"]
        room_box.pack()

        def book():
            name = name_var.get()
            room = room_var.get()
            if room in rooms and rooms[room] == "Available":
                rooms[room] = "Booked"
                messagebox.showinfo("Booked", f"Room {room} booked for {name}")
            else:
                messagebox.showerror("Unavailable", "Room not available")
        tk.Button(self.main_frame, text="Book Room", command=book).pack(pady=10)
        
    def show_billing(self):
        self.clear_frame()
        tk.Label(self.main_frame, text="Billing", font=("Arial", 16)).pack(pady=10)

        room_var = tk.IntVar()
        days_var = tk.IntVar()

        tk.Label(self.main_frame, text="Room Number").pack()
        tk.Entry(self.main_frame, textvariable=room_var).pack()

        tk.Label(self.main_frame, text="Number of Days").pack()
        tk.Entry(self.main_frame, textvariable=days_var).pack()

        def generate_bill():
            rate_per_day = 1000
            total = days_var.get() * rate_per_day
            messagebox.showinfo("Bill", f"Total Bill: ${total}")

        tk.Button(self.main_frame, text="Generate Bill", command=generate_bill).pack(pady=10)

        def DisplayGuests(self):
           self.clear_fraem()
           tk.Label(self.mian_frame,text="Booked roooms",font=("Arial",16)).pack(pady=10)
           found=False
           for room,status in rooms.items():
            if status=="Booked":
               found=True
               tk.Label(self.main_frame,text=f"Room{room} is booked").pack()
            if not found:
                tk.Label(self.main_frame,text="No Bookings yet!").pack()
        tk.Button(self.main_frame, text="Display Booked Rooms", command=DisplayGuests).pack(pady=10)

        def logout():
            self.destroy()
            login = LoginWindow()
            login.mainloop()
        tk.Button(self.main_frame, text="Logout", command=logout).pack(pady=10)

if __name__ == "__main__":
    login = LoginWindow()
    login.mainloop()