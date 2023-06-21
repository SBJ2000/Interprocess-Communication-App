from tkinter import *
from subprocess import call
import time

def methode1buttons():
	btn1 = Button(window, text='client', width=10,height=0, bd='1',command=openmethode1clientfile)
	btn1.place(x=150, y=200)
	btn2 = Button(window, text='serveur', width=10,height=0, bd='1',command=openmethode1serveurfile)
	btn2.place(x=630, y=200)
def methode2buttons():
	btn1 = Button(window, text='client', width=10,height=0, bd='1',command=openmethode2clientfile)
	btn1.place(x=1150, y=200)
	btn2 = Button(window, text='serveur', width=10,height=0, bd='1',command=openmethode2serveurfile)
	btn2.place(x=1570, y=200)
def openmethode1clientfile():
	call(["python3","./guipythonmethode1client.py"])
	time.sleep(1)
	with open('outputserver1.txt') as f:
    		contentsserver = f.read()
    		f.close()
	Output = Text(window, height = 20,width = 60, bg = "light cyan",wrap="none")
	Output.insert(END, contentsserver)
	Output.config(state=DISABLED)
	Output.place(x=430,y=260)
	with open('outputclient1.txt') as f:
    		contentsclient = f.read()
    		f.close()
	Output = Text(window, height = 20,width = 45, bg = "light cyan",wrap="none")
	Output.insert(END, contentsclient)
	Output.config(state=DISABLED)
	Output.place(x=20,y=260)
	# Display image
	canvas1.create_image( 170, 200, image =imgtubes, anchor = "nw")	
def openmethode1serveurfile():
	call(["python3","./guipythonmethode1serveur.py"])
def openmethode2clientfile():
	call(["python3","./guipythonmethode2client.py"])
	time.sleep(0.4)
	with open('outputserver2.txt') as f:
    		contentsserver2 = f.read()
    		f.close()
	Output = Text(window, height = 20,width = 55, bg = "light cyan",wrap="none")
	Output.insert(END, contentsserver2)
	Output.config(state=DISABLED)
	Output.place(x=1380,y=260)
	with open('outputclient2.txt') as f:
    		contentsclient2 = f.read()
    		f.close()
	Output = Text(window, height = 20,width = 45, bg = "light cyan",wrap="none")
	Output.insert(END, contentsclient2)
	Output.config(state=DISABLED)
	Output.place(x=1000,y=260)
	# Display image
	canvas1.create_image( 1100, 100, image =imgsocket, anchor = "nw")
def openmethode2serveurfile():
	call(["python3","./guipythonmethode2serveur.py"])
window= Tk()
# Create Canvas
canvas1 = Canvas( window, width = 400,
                 height = 400)
  
canvas1.pack(fill = "both", expand = True)
window.title("Projet Unix 22/23")
window.geometry("1080x720")
btn1 = Button(window, text='Communication Tubes Nommés', width=30,height=0, bd='1',command=methode1buttons)
btn1.place(x=310, y=130)
btn2 = Button(window, text='Communication Socket TCP', width=30,height=0, bd='1',command=methode2buttons)
btn2.place(x=1250, y=130)
# Add Text
canvas1.create_text( 1000, 40,fill="#811d36",font="Arial 20 ", text = "Bienvenue dans le projet unix 22/23 , veuillez choisir la méthode convenable")
# Add image file
imgsocket = PhotoImage(file = "socket.png")
# Create Canvas
canvas1 = Canvas(window ,width = 1000,
                 height = 1000)
canvas1.pack(fill = "both", expand = True)
# Add image file
imgtubes = PhotoImage(file = "tubes.png")
window.mainloop()
