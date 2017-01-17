import tkinter

window = tkinter.Tk()

window.title("Joga da Vida")

window.configure(background="#a1dbcd")

def callback():
	lbl.configure(text="Button Clicked")


lbl = tkinter.Label(window, text="Nothing happened yet")
lbl.pack()

btn = tkinter.Button(window, text="Run", command=callback)
btn.pack()

window.mainloop()